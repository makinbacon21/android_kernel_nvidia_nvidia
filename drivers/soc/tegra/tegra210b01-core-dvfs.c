/*
 * Copyright (c) 2017, NVIDIA CORPORATION.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

static const int coreb01_voltages_mv[MAX_DVFS_FREQS] = {
	637, 650, 675, 700, 725, 750, 775, 800, 825, 850, 875, 900, 925, 950, 975, 1000, 1025, 1050
};

static struct dvfs coreb01_dvfs_table[] = {
/* Per-bin Tables */
	/* SOC Speedo 0, Process 0. Core voltages(mV):	    637,     650,     675,     700,     725,     750,     775,     800,     825,     850,     875,     900,     925,     950,     975,    1000,    1025,    1050 */
	CORE_DVFS("emc",		0, 0, 1, KHZ,	      1,       1,       1,       1,       1,       1,       1,       1, 2133000, 2133000, 2133000, 2133000, 2133000, 2133000, 2133000, 2133000, 2133000, 2133000),

	CORE_DVFS("vic03",		0, 0, 1, KHZ,	 307200,  364800,  441600,  499200,  518400,  537600,  556800,  576000,  576000,  595200,  614400,  614400,  633600,  633600,  652800,  652800,  652800,  652800),
	CORE_DVFS("nvjpg",		0, 0, 1, KHZ,	 307200,  364800,  441600,  499200,  518400,  537600,  556800,  576000,  576000,  595200,  614400,  614400,  633600,  633600,  652800,  652800,  652800,  652800),
	CORE_DVFS("se",			0, 0, 1, KHZ,	 307200,  364800,  441600,  499200,  518400,  537600,  556800,  576000,  576000,  595200,  614400,  614400,  633600,  633600,  652800,  652800,  652800,  652800),
	CORE_DVFS("tsecb",		0, 0, 1, KHZ,	 307200,  364800,  441600,  499200,  518400,  537600,  556800,  576000,  576000,  595200,  614400,  614400,  633600,  633600,  652800,  652800,  652800,  652800),
	CORE_DVFS("c2bus",		0, 0, 1, KHZ,	 307200,  364800,  441600,  499200,  518400,  537600,  556800,  576000,  576000,  595200,  614400,  614400,  633600,  633600,  652800,  652800,  652800,  652800),

	CORE_DVFS("nvenc",		0, 0, 1, KHZ,	 364800,  403200,  499200,  576000,  595200,  672000,  710400,  748800,  787200,  825600,  844800,  864000,  883200,  902400,  921600,  940800,  960000,  979200),
	CORE_DVFS("nvdec",		0, 0, 1, KHZ,	 364800,  403200,  499200,  576000,  595200,  672000,  710400,  748800,  787200,  825600,  844800,  864000,  883200,  902400,  921600,  940800,  960000,  979200),
	CORE_DVFS("c3bus",		0, 0, 1, KHZ,	 364800,  403200,  499200,  576000,  595200,  672000,  710400,  748800,  787200,  825600,  844800,  864000,  883200,  902400,  921600,  940800,  960000,  979200),

	CORE_DVFS("vi",			0, 0, 1, KHZ,	 422400,  422400,  556800,  595200,  652800,  691200,  729600,  787200,  825600,  864000,  902400,  940800,  960000,  998400, 1036800, 1056000, 1094400, 1113600),
	CORE_DVFS("cbus",		0, 0, 1, KHZ,	 422400,  422400,  556800,  595200,  652800,  691200,  729600,  787200,  825600,  864000,  902400,  940800,  960000,  998400, 1036800, 1056000, 1094400, 1113600),

	CORE_DVFS("abus",		0, 0, 1, KHZ,	 576000,  691200,  729600,  768000,  844800,  921600,  998400, 1036800, 1113600, 1152000, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400),
	CORE_DVFS("aclk",		0, 0, 1, KHZ,	 576000,  691200,  729600,  768000,  844800,  921600,  998400, 1036800, 1113600, 1152000, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400),

	CORE_DVFS("ape",		0, 0, 1, KHZ,	 422400,  480000,  499200,  595200,  633600,  652800,  691200,  729600,  768000,  806400,  844800,  883200,  940800,  979200,  998400,  998400,  998400,  998400),
	CORE_DVFS("sbus",		0, 0, 1, KHZ,	 102000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000),
	CORE_DVFS("sclk",		0, 0, 1, KHZ,	 102000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000),

	CORE_DVFS("host1x",		0, 0, 1, KHZ,	 102000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000),
	CORE_DVFS("tsec",		0, 0, 1, KHZ,	 307200,  364800,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000),
	CORE_DVFS("mselect",		0, 0, 1, KHZ,	 102000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000),

	CORE_DVFS("disp1",		0, 0, 0, KHZ,	 300000,  350000,  450000,  500000,  525000,  550000,  600000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000),
	CORE_DVFS("disp2",		0, 0, 0, KHZ,	 300000,  350000,  450000,  500000,  525000,  550000,  600000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000),


	CORE_DVFS("sor1",		0, 0, 1, KHZ,	      1,       1,  297000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000),
	CORE_DVFS("hda",		0, 0, 1, KHZ,	      1,       1,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000),
	CORE_DVFS("hda2codec_2x",	0, 0, 1, KHZ,	      1,       1,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000),
	CORE_DVFS("maud",		0, 0, 1, KHZ,	      1,       1,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000),

	/* SOC Speedo 0, Process 1. Core voltages(mV):	    637,     650,     675,     700,     725,     750,     775,     800,     825,     850,     875,     900,     925,     950,     975,    1000,    1025,    1050 */
	CORE_DVFS("emc",		0, 1, 1, KHZ,	      1,       1,       1,       1,       1,       1,       1,       1, 2133000, 2133000, 2133000, 2133000, 2133000, 2133000, 2133000, 2133000, 2133000, 2133000),

	CORE_DVFS("vic03",		0, 1, 1, KHZ,	 422400,  441600,  499200,  518400,  537600,  556800,  576000,  576000,  595200,  614400,  633600,  633600,  652800,  652800,  652800,  652800,  652800,  652800),
	CORE_DVFS("nvjpg",		0, 1, 1, KHZ,	 422400,  441600,  499200,  518400,  537600,  556800,  576000,  576000,  595200,  614400,  633600,  633600,  652800,  652800,  652800,  652800,  652800,  652800),
	CORE_DVFS("se",			0, 1, 1, KHZ,	 422400,  441600,  499200,  518400,  537600,  556800,  576000,  576000,  595200,  614400,  633600,  633600,  652800,  652800,  652800,  652800,  652800,  652800),
	CORE_DVFS("tsecb",		0, 1, 1, KHZ,	 422400,  441600,  499200,  518400,  537600,  556800,  576000,  576000,  595200,  614400,  633600,  633600,  652800,  652800,  652800,  652800,  652800,  652800),
	CORE_DVFS("c2bus",		0, 1, 1, KHZ,	 422400,  441600,  499200,  518400,  537600,  556800,  576000,  576000,  595200,  614400,  633600,  633600,  652800,  652800,  652800,  652800,  652800,  652800),

	CORE_DVFS("nvenc",		0, 1, 1, KHZ,	 460800,  499200,  556800,  633600,  652800,  710400,  748800,  787200,  825600,  844800,  883200,  902400,  921600,  940800,  960000,  979200,  979200,  979200),
	CORE_DVFS("nvdec",		0, 1, 1, KHZ,	 460800,  499200,  556800,  633600,  652800,  710400,  748800,  787200,  825600,  844800,  883200,  902400,  921600,  940800,  960000,  979200,  979200,  979200),
	CORE_DVFS("c3bus",		0, 1, 1, KHZ,	 460800,  499200,  556800,  633600,  652800,  710400,  748800,  787200,  825600,  844800,  883200,  902400,  921600,  940800,  960000,  979200,  979200,  979200),

	CORE_DVFS("vi",			0, 1, 1, KHZ,	 460800,  499200,  614400,  672000,  729600,  787200,  825600,  864000,  902400,  940800,  979200, 1017600, 1036800, 1056000, 1094400, 1113600, 1113600, 1113600),
	CORE_DVFS("cbus",		0, 1, 1, KHZ,	 460800,  499200,  614400,  672000,  729600,  787200,  825600,  864000,  902400,  940800,  979200, 1017600, 1036800, 1056000, 1094400, 1113600, 1113600, 1113600),

	CORE_DVFS("abus",		0, 1, 1, KHZ,	 691200,  768000,  806400,  883200,  921600,  960000, 1075200, 1113600, 1152000, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400),
	CORE_DVFS("aclk",		0, 1, 1, KHZ,	 691200,  768000,  806400,  883200,  921600,  960000, 1075200, 1113600, 1152000, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400),

	CORE_DVFS("ape",		0, 1, 1, KHZ,	 441600,  499200,  537600,  633600,  672000,  691200,  729600,  787200,  806400,  844800,  883200,  921600,  979200,  998400,  998400,  998400,  998400,  998400),
	CORE_DVFS("sbus",		0, 1, 1, KHZ,	 204000,  204000,  204000,  204000,  204000,  204000,  204000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000),
	CORE_DVFS("sclk",		0, 1, 1, KHZ,	 204000,  204000,  204000,  204000,  204000,  204000,  204000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000),

	CORE_DVFS("host1x",		0, 1, 1, KHZ,	 204000,  204000,  204000,  204000,  204000,  204000,  204000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000),
	CORE_DVFS("tsec",		0, 1, 1, KHZ,	 408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000),
	CORE_DVFS("mselect",		0, 1, 1, KHZ,	 204000,  204000,  204000,  204000,  204000,  204000,  204000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000),

	CORE_DVFS("disp1",		0, 1, 0, KHZ,	 400000,  500000,  535000,  600000,  635000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000),
	CORE_DVFS("disp2",		0, 1, 0, KHZ,	 400000,  500000,  535000,  600000,  635000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000),


	CORE_DVFS("sor1",		0, 1, 1, KHZ,	 297000,  297000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000),
	CORE_DVFS("hda",		0, 1, 1, KHZ,	 102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000),
	CORE_DVFS("hda2codec_2x",	0, 1, 1, KHZ,	  48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000),
	CORE_DVFS("maud",		0, 1, 1, KHZ,	 102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000),

	/* SOC Speedo 0, Process 2. Core voltages(mV):	    637,     650,     675,     700,     725,     750,     775,     800,     825,     850,     875,     900,     925,     950,     975,    1000,    1025,    1050 */
	CORE_DVFS("emc",		0, 2, 1, KHZ,	      1,       1,       1,       1,       1,       1,       1,       1, 2133000, 2133000, 2133000, 2133000, 2133000, 2133000, 2133000, 2133000, 2133000, 2133000),

	CORE_DVFS("vic03",		0, 2, 1, KHZ,	 499200,  499200,  537600,  556800,  576000,  595200,  614400,  614400,  633600,  652800,  652800,  652800,  652800,  652800,  652800,  652800,  652800,  652800),
	CORE_DVFS("nvjpg",		0, 2, 1, KHZ,	 499200,  499200,  537600,  556800,  576000,  595200,  614400,  614400,  633600,  652800,  652800,  652800,  652800,  652800,  652800,  652800,  652800,  652800),
	CORE_DVFS("se",			0, 2, 1, KHZ,	 499200,  499200,  537600,  556800,  576000,  595200,  614400,  614400,  633600,  652800,  652800,  652800,  652800,  652800,  652800,  652800,  652800,  652800),
	CORE_DVFS("tsecb",		0, 2, 1, KHZ,	 499200,  499200,  537600,  556800,  576000,  595200,  614400,  614400,  633600,  652800,  652800,  652800,  652800,  652800,  652800,  652800,  652800,  652800),
	CORE_DVFS("c2bus",		0, 2, 1, KHZ,	 499200,  499200,  537600,  556800,  576000,  595200,  614400,  614400,  633600,  652800,  652800,  652800,  652800,  652800,  652800,  652800,  652800,  652800),

	CORE_DVFS("nvenc",		0, 2, 1, KHZ,	 556800,  595200,  652800,  691200,  748800,  787200,  825600,  844800,  864000,  883200,  921600,  940800,  940800,  960000,  979200,  979200,  979200,  979200),
	CORE_DVFS("nvdec",		0, 2, 1, KHZ,	 556800,  595200,  652800,  691200,  748800,  787200,  825600,  844800,  864000,  883200,  921600,  940800,  940800,  960000,  979200,  979200,  979200,  979200),
	CORE_DVFS("c3bus",		0, 2, 1, KHZ,	 556800,  595200,  652800,  691200,  748800,  787200,  825600,  844800,  864000,  883200,  921600,  940800,  940800,  960000,  979200,  979200,  979200,  979200),

	CORE_DVFS("vi",			0, 2, 1, KHZ,	 576000,  614400,  652800,  691200,  768000,  806400,  844800,  883200,  921600,  960000,  998400, 1036800, 1075200, 1094400, 1113600, 1113600, 1113600, 1113600),
	CORE_DVFS("cbus",		0, 2, 1, KHZ,	 576000,  614400,  652800,  691200,  768000,  806400,  844800,  883200,  921600,  960000,  998400, 1036800, 1075200, 1094400, 1113600, 1113600, 1113600, 1113600),

	CORE_DVFS("abus",		0, 2, 1, KHZ,	 768000,  844800,  921600,  960000,  998400, 1075200, 1113600, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400),
	CORE_DVFS("aclk",		0, 2, 1, KHZ,	 768000,  844800,  921600,  960000,  998400, 1075200, 1113600, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400, 1190400),

	CORE_DVFS("ape",		0, 2, 1, KHZ,	 576000,  595200,  652800,  710400,  729600,  806400,  844800,  883200,  921600,  960000,  998400,  998400,  998400,  998400,  998400,  998400,  998400,  998400),
	CORE_DVFS("sbus",		0, 2, 1, KHZ,	 204000,  204000,  204000,  204000,  204000,  204000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000),
	CORE_DVFS("sclk",		0, 2, 1, KHZ,	 204000,  204000,  204000,  204000,  204000,  204000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000),

	CORE_DVFS("host1x",		0, 2, 1, KHZ,	 204000,  204000,  204000,  204000,  204000,  204000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000),
	CORE_DVFS("tsec",		0, 2, 1, KHZ,	 408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000),
	CORE_DVFS("mselect",		0, 2, 1, KHZ,	 204000,  204000,  204000,  204000,  204000,  204000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000,  408000),

	CORE_DVFS("disp1",		0, 2, 0, KHZ,	 450000,  500000,  550000,  600000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000),
	CORE_DVFS("disp2",		0, 2, 0, KHZ,	 450000,  500000,  550000,  600000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000,  665000),


	CORE_DVFS("sor1",		0, 2, 1, KHZ,	 297000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000,  594000),
	CORE_DVFS("hda",		0, 2, 1, KHZ,	 102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000),
	CORE_DVFS("hda2codec_2x",	0, 2, 1, KHZ,	  48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000),
	CORE_DVFS("maud",		0, 2, 1, KHZ,	 102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000),

/* Common Tables */
	/* Core voltages(mV):				    637,     650,     675,     700,     725,     750,     775,     800,     825,     850,     875,     900,     925,     950,     975,    1000,    1025,    1050 */
	CORE_DVFS("pll_a",		-1, -1, 1, KHZ,	1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000),
	CORE_DVFS("pll_c",		-1, -1, 1, KHZ,	1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000),
	CORE_DVFS("pll_c2",		-1, -1, 1, KHZ,	1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000),
	CORE_DVFS("pll_c3",		-1, -1, 1, KHZ,	1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000),
	CORE_DVFS("pll_c4_out0",	-1, -1, 1, KHZ,	1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000),
	CORE_DVFS("pll_d_out0",		-1, -1, 1, KHZ,	1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000),
	CORE_DVFS("pll_d2",		-1, -1, 1, KHZ,	1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000),
	CORE_DVFS("pll_dp",		-1, -1, 1, KHZ,	1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000, 1500000),

	/* Core voltages(mV):				    637,     650,     675,     700,     725,     750,     775,     800,     825,     850,     875,     900,     925,     950,     975,    1000,    1025,    1050 */
	CORE_DVFS("csi",		-1, -1, 1, KHZ,	 750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000),
	CORE_DVFS("cilab",		-1, -1, 1, KHZ,	 102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  204000,  204000,  204000,  204000,  204000,  204000,  204000),
	CORE_DVFS("cilcd",		-1, -1, 1, KHZ,	 102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  204000,  204000,  204000,  204000,  204000,  204000,  204000),

	CORE_DVFS("clk72mhz",		-1, -1, 1, KHZ,	  68000,   68000,   68000,   68000,   68000,   68000,   68000,   68000,   68000,   68000,   68000,   68000,   68000,   68000,   68000,   68000,   68000,   68000),
	CORE_DVFS("dsia",		-1, -1, 1, KHZ,	 750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000),
	CORE_DVFS("dsib",		-1, -1, 1, KHZ,	 750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000,  750000),

	CORE_DVFS("dsialp",		-1, -1, 1, KHZ,	 102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000),
	CORE_DVFS("dsiblp",		-1, -1, 1, KHZ,	 102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000,  102000),



	CORE_DVFS("i2s0",		-1, -1, 1, KHZ,	  24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576),
	CORE_DVFS("i2s1",		-1, -1, 1, KHZ,	  24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576),
	CORE_DVFS("i2s2",		-1, -1, 1, KHZ,	  24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576),
	CORE_DVFS("i2s3",		-1, -1, 1, KHZ,	  24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576),
	CORE_DVFS("i2s4",		-1, -1, 1, KHZ,	  24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576),

	CORE_DVFS("d_audio",		-1, -1, 1, KHZ,	  98304,   98304,   98304,   98304,   98304,   98304,   98304,   98304,   98304,   98304,   98304,   98304,   98304,   98304,   98304,   98304,   98304,   98304),
	CORE_DVFS("spdif_in",		-1, -1, 1, KHZ,	 163200,  163200,  163200,  163200,  163200,  163200,  163200,  163200,  163200,  163200,  163200,  163200,  163200,  163200,  163200,  163200,  163200,  163200),
	CORE_DVFS("spdif_out",		-1, -1, 1, KHZ,	  24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576,   24576),
	CORE_DVFS("dmic1",		-1, -1, 1, KHZ,	  12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288),
	CORE_DVFS("dmic2",		-1, -1, 1, KHZ,	  12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288),
	CORE_DVFS("dmic3",		-1, -1, 1, KHZ,	  12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288,   12288),




	CORE_DVFS("sdmmc1",		-1, -1, 1, KHZ,	 204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000),
	CORE_DVFS("sdmmc3",		-1, -1, 1, KHZ,	 204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000,  204000),

	CORE_DVFS("sdmmc1_ddr",		-1, -1, 1, KHZ,	  50000,   50000,   50000,   50000,   50000,   50000,   50000,   50000,   50000,   50000,   50000,   50000,   50000,   50000,   50000,   50000,   50000,   50000),
	CORE_DVFS("sdmmc3_ddr",		-1, -1, 1, KHZ,	  50000,   50000,   50000,   50000,   50000,   50000,   50000,   50000,   50000,   50000,   50000,   50000,   50000,   50000,   50000,   50000,   50000,   50000),

	CORE_DVFS("sdmmc2",		-1, -1, 1, KHZ,	 200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000),
	CORE_DVFS("sdmmc4",		-1, -1, 1, KHZ,	 200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000),

	CORE_DVFS("sdmmc_legacy",	-1, -1, 1, KHZ,	  12000,   12000,   12000,   12000,   12000,   12000,   12000,   12000,   12000,   12000,   12000,   12000,   12000,   12000,   12000,   12000,   12000,   12000),

	CORE_DVFS("xusb_falcon_src",	-1, -1, 1, KHZ,	 336000,  336000,  336000,  336000,  336000,  336000,  336000,  336000,  336000,  336000,  336000,  336000,  336000,  336000,  336000,  336000,  336000,  336000),
	CORE_DVFS("xusb_host_src",	-1, -1, 1, KHZ,	 112000,  112000,  112000,  112000,  112000,  112000,  112000,  112000,  112000,  112000,  112000,  112000,  112000,  112000,  112000,  112000,  112000,  112000),
	CORE_DVFS("xusb_dev_src",	-1, -1, 1, KHZ,	 112000,  112000,  112000,  112000,  112000,  112000,  112000,  112000,  112000,  112000,  112000,  112000,  112000,  112000,  112000,  112000,  112000,  112000),
	CORE_DVFS("xusb_ssp_src",	-1, -1, 1, KHZ,	 120000,  120000,  120000,  120000,  120000,  120000,  120000,  120000,  120000,  120000,  120000,  120000,  120000,  120000,  120000,  120000,  120000,  120000),
	CORE_DVFS("xusb_fs_src",	-1, -1, 1, KHZ,	  48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000),
	CORE_DVFS("xusb_hs_src",	-1, -1, 1, KHZ,	 480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000),
	CORE_DVFS("usbd",		-1, -1, 1, KHZ,	 480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000),
	CORE_DVFS("usb2",		-1, -1, 1, KHZ,	 480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000,  480000),

	CORE_DVFS("pcie",		-1, -1, 1, KHZ,	 500000,  500000,  500000,  500000,  500000,  500000,  500000,  500000,  500000,  500000,  500000,  500000,  500000,  500000,  500000,  500000,  500000,  500000),

	CORE_DVFS("i2c1",		-1, -1, 1, KHZ,	 136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000),
	CORE_DVFS("i2c2",		-1, -1, 1, KHZ,	 136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000),
	CORE_DVFS("i2c3",		-1, -1, 1, KHZ,	 136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000),
	CORE_DVFS("i2c4",		-1, -1, 1, KHZ,	 136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000),
	CORE_DVFS("i2c5",		-1, -1, 1, KHZ,	 136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000),
	CORE_DVFS("i2c6",		-1, -1, 1, KHZ,	 136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000),
	CORE_DVFS("vii2c",		-1, -1, 1, KHZ,	 136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000),

	CORE_DVFS("i2cslow",		-1, -1, 1, KHZ,	     33,      33,      33,      33,      33,      33,      33,      33,      33,      33,      33,      33,      33,      33,      33,      33,      33,      33),
	CORE_DVFS("pwm",		-1, -1, 1, KHZ,	  48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000,   48000),

	CORE_DVFS("extern1",		-1, -1, 1, KHZ,	  49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152),
	CORE_DVFS("extern2",		-1, -1, 1, KHZ,	  49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152),
	CORE_DVFS("extern3",		-1, -1, 1, KHZ,	  49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152,   49152),

	CORE_DVFS("soc_therm",		-1, -1, 1, KHZ,	 136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000,  136000),
	CORE_DVFS("tsensor",		-1, -1, 1, KHZ,	  19200,   19200,   19200,   19200,   19200,   19200,   19200,   19200,   19200,   19200,   19200,   19200,   19200,   19200,   19200,   19200,   19200,   19200),
};

static struct dvfs sor1_dpb01_dvfs_table[] = {
	CORE_DVFS("sor1",		0, 0, 1, KHZ,	      1,       1,  270000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000),
	CORE_DVFS("sor1",		0, 1, 1, KHZ,	 270000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000),
	CORE_DVFS("sor1",		0, 2, 1, KHZ,	 540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000,  540000),
};

static struct dvfs spib01_dvfs_table[] = {
	CORE_DVFS("sbc1",		-1, -1, 1, KHZ,	  51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000),
	CORE_DVFS("sbc2",		-1, -1, 1, KHZ,	  51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000),
	CORE_DVFS("sbc3",		-1, -1, 1, KHZ,	  51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000),
	CORE_DVFS("sbc4",		-1, -1, 1, KHZ,	  51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000,   51000),

};

static struct dvfs spi_slaveb01_dvfs_table[] = {
	CORE_DVFS("sbc1",		-1, -1, 1, KHZ,	  45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000),
	CORE_DVFS("sbc2",		-1, -1, 1, KHZ,	  45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000),
	CORE_DVFS("sbc3",		-1, -1, 1, KHZ,	  45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000),
	CORE_DVFS("sbc4",		-1, -1, 1, KHZ,	  45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000,   45000),

};

static struct dvfs qspi_sdrb01_dvfs_table[] = {
	CORE_DVFS("qspi",		-1, -1, 1, KHZ,	 133000,  133000,  133000,  133000,  133000,  133000,  133000,  133000,  133000,  133000,  133000,  133000,  133000,  133000,  133000,  133000,  133000,  133000),
};

static struct dvfs qspi_ddrb01_dvfs_table[] = {
	CORE_DVFS("qspi",		-1, -1, 1, KHZ,	 200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000,  200000),
};

/* EMC DVB DVFS tables */
static struct dvb_dvfs emcb01_dvb_dvfs_table[] = {
	{
		.speedo_id = -1,
		.freqs_mult = KHZ,
		.dvb_table = {
			{  204000, {  637,  637,  637, } },
			{  408000, {  637,  637,  637, } },
			{  800000, {  637,  637,  637, } },
			{ 1065600, {  637,  637,  637, } },
			{ 1331200, {  650,  637,  637, } },
			{ 1600000, {  675,  650,  637, } },
			{ 1862400, {  675,  650,  637, } },
			{ 2133000, {  700,  675,  650, } },
			{ 0, { } },
		},
	},
};

static const char coreb01_dvfs_table_ver[] = "SOC - p4v3 SOC_IO - p4v4 SOC_EMC- p4v3";
