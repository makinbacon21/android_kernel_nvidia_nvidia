/*
 * Tegra Video Input device common APIs
 *
 * Copyright (c) 2015-2016, NVIDIA CORPORATION.  All rights reserved.
 *
 * Author: Bryan Wu <pengw@nvidia.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/init.h>
#include <linux/export.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_platform.h>

#include <media/tegra_v4l2_camera.h>
#include <media/camera_common.h>

#include "dev.h"
#include "mc_common.h"

#define TPG_CHANNELS 6
#define INVALID_PORT 100

/* -----------------------------------------------------------------------------
 * Media Controller and V4L2
 */

static const char *const vi_pattern_strings[] = {
	"Disabled",
	"Black/White Direct Mode",
	"Color Patch Mode",
};

static void set_vi_mode(struct tegra_mc_vi *vi)
{
	int i;
	struct tegra_channel *chan = NULL;

	for (i = 0; i < vi->num_channels; i++) {
		chan = &vi->chans[i];
		chan->bypass = 0;
	}
}

static void set_v4l2_ctrl(struct v4l2_ctrl *ctrl, int value)
{
	v4l2_ctrl_unlock(ctrl);
	v4l2_ctrl_s_ctrl(ctrl, value);
	v4l2_ctrl_lock(ctrl);
}

static int vi_s_ctrl(struct v4l2_ctrl *ctrl)
{
	struct tegra_mc_vi *vi = container_of(ctrl->handler, struct tegra_mc_vi,
					   ctrl_handler);
	struct tegra_channel *chan = NULL;

	switch (ctrl->id) {
	case V4L2_CID_TEST_PATTERN:
		/* set all channels to vi mode before TPG is set */
		/* set bypass port to invalid port */
		if (ctrl->val) {
			set_v4l2_ctrl(vi->bypass, INVALID_PORT);
			dev_info(&vi->ndev->dev, "Turning on TPG mode\n");
		}
		vi->pg_mode = ctrl->val;
		break;
	case V4L2_CID_VI_SET_BYPASS_PORT:
		if (vi->pg_mode) {
			dev_info(&vi->ndev->dev, "Turn off TPG mode\n");
			set_v4l2_ctrl(vi->pattern, 0);
			vi->pg_mode = 0;
		}

		if (ctrl->val < vi->num_channels) {
			chan = &vi->chans[ctrl->val];
			chan->bypass = 1;
		} else
			/* set all channels to vi mode for invalid port */
			set_vi_mode(vi);
		break;
	}

	return 0;
}

static const struct v4l2_ctrl_ops vi_ctrl_ops = {
	.s_ctrl	= vi_s_ctrl,
};

/**
 * Default value is invalid port, max 99 channels are available
 * By default all the channels will be in VI mode
 * Idea is to enable the user space to set bypass flag per channel
 */
static const struct v4l2_ctrl_config bypass_ctrl = {
	.ops = &vi_ctrl_ops,
	.id = V4L2_CID_VI_SET_BYPASS_PORT,
	.name = "Bypass port",
	.type = V4L2_CTRL_TYPE_INTEGER,
	.flags = V4L2_CTRL_FLAG_SLIDER,
	.def = INVALID_PORT,
	.min = 0,
	.max = INVALID_PORT,
	.step = 1,
};

void tegra_vi_v4l2_cleanup(struct tegra_mc_vi *vi)
{
	v4l2_ctrl_handler_free(&vi->ctrl_handler);
	v4l2_device_unregister(&vi->v4l2_dev);
	media_device_unregister(&vi->media_dev);
}

int tegra_vi_v4l2_init(struct tegra_mc_vi *vi)
{
	int ret;

	vi->pg_mode = 0;
	vi->media_dev.dev = vi->dev;
	strlcpy(vi->media_dev.model, "NVIDIA Tegra Video Input Device",
		sizeof(vi->media_dev.model));
	vi->media_dev.hw_revision = 3;

	ret = media_device_register(&vi->media_dev);
	if (ret < 0) {
		dev_err(vi->dev, "media device registration failed (%d)\n",
			ret);
		return ret;
	}

	vi->v4l2_dev.mdev = &vi->media_dev;
	ret = v4l2_device_register(vi->dev, &vi->v4l2_dev);
	if (ret < 0) {
		dev_err(vi->dev, "V4L2 device registration failed (%d)\n",
			ret);
		goto register_error;
	}

	v4l2_ctrl_handler_init(&vi->ctrl_handler, 2);
	vi->pattern = v4l2_ctrl_new_std_menu_items(&vi->ctrl_handler,
					&vi_ctrl_ops, V4L2_CID_TEST_PATTERN,
					ARRAY_SIZE(vi_pattern_strings) - 1,
					0, 0, vi_pattern_strings);

	vi->bypass = v4l2_ctrl_new_custom(&vi->ctrl_handler,
					&bypass_ctrl, NULL);
	if (vi->ctrl_handler.error) {
		dev_err(vi->dev, "failed to add controls\n");
		ret = vi->ctrl_handler.error;
		goto ctrl_error;
	}
	vi->v4l2_dev.ctrl_handler = &vi->ctrl_handler;

	ret = v4l2_ctrl_handler_setup(&vi->ctrl_handler);
	if (ret < 0) {
		dev_err(vi->dev, "failed to set controls\n");
		goto ctrl_error;
	}
	return 0;


ctrl_error:
	v4l2_ctrl_handler_free(&vi->ctrl_handler);
	v4l2_device_unregister(&vi->v4l2_dev);
register_error:
	media_device_unregister(&vi->media_dev);
	return ret;
}

static int vi_parse_dt(struct tegra_mc_vi *vi, struct platform_device *dev)
{
	int err = 0;
	int num_channels = 0;
	struct device_node *node = dev->dev.of_node;

	err = of_property_read_u32(node, "num-channels", &num_channels);
	if (err) {
		dev_err(&dev->dev,
			"Failed to find num of channels, reset to 1\n");
		/* Needed this WAR to have ap_sim sanity */
		num_channels = 1;
	}

	vi->num_channels = num_channels;
	vi->chans = devm_kzalloc(&dev->dev,
			(sizeof(struct tegra_channel) * num_channels),
			GFP_KERNEL);
	if (!vi->chans)
		return -ENOMEM;

	return 0;
}

int tegra_vi_media_controller_init(struct tegra_mc_vi *mc_vi,
			struct platform_device *pdev)
{
	int err = 0;

	err = vi_parse_dt(mc_vi, pdev);
	if (err)
		goto mc_init_fail;

	mc_vi->ndev = pdev;
	mc_vi->dev = &pdev->dev;
	INIT_LIST_HEAD(&mc_vi->entities);

	err = tegra_vi_v4l2_init(mc_vi);
	if (err < 0)
		goto mc_init_fail;

	/* Init Tegra VI channels */
	err = tegra_vi_channels_init(mc_vi);
	if (err < 0)
		goto channels_error;

	/* Setup media links between VI and external sensor subdev. */
	err = tegra_vi_graph_init(mc_vi);
	if (err < 0)
		goto graph_error;

	return 0;

graph_error:
	tegra_vi_channels_cleanup(mc_vi);
channels_error:
	tegra_vi_v4l2_cleanup(mc_vi);
mc_init_fail:
	dev_err(&pdev->dev, "%s: failed\n", __func__);
	return err;
}

void tegra_vi_media_controller_cleanup(struct tegra_mc_vi *mc_vi)
{
	tegra_vi_graph_cleanup(mc_vi);
	tegra_vi_channels_cleanup(mc_vi);
	tegra_vi_v4l2_cleanup(mc_vi);
}
