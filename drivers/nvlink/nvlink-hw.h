/*
 * nvlink-hw.h:
 * This header contains register definitions and HW related macros for the
 * NVLINK driver stack.
 *
 * Copyright (c) 2017-2018, NVIDIA CORPORATION.  All rights reserved.
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

#ifndef NVLINK_REGS_H
#define NVLINK_REGS_H

/* NVLINK APERTURES - START */


/* TIOCTRL MACROS */
/* TODO: Confirm this delay is correct for Tegra */
#define NVLW_POST_RESET_DELAY_US				8

/* TIOCTRL Registers */
#define NVLW_RESET						0x140
#define NVLW_RESET_LINKRESET					8

#define NVLW_DEBUG_RESET					0x144
#define NVLW_DEBUG_RESET_LINK					0
#define NVLW_DEBUG_RESET_COMMON					31

#define NVLW_COMMON_INTR_0_MASK					0x220
#define NVLW_COMMON_INTR_0_MASK_FATAL				0

#define NVLW_COMMON_INTR_1_MASK					0x228
#define NVLW_COMMON_INTR_1_MASK_NONFATAL			1
#define NVLW_COMMON_INTR_1_MASK_CORRECTABLE			2

#define NVLW_COMMON_INTR_2_MASK					0x230
#define NVLW_COMMON_INTR_2_MASK_INTRA				3
#define NVLW_COMMON_INTR_2_MASK_INTRB				4

#define NVLW_LINK_INTR_0_MASK					0x240
#define NVLW_LINK_INTR_0_MASK_FATAL				0

#define NVLW_LINK_INTR_1_MASK					0x248
#define NVLW_LINK_INTR_1_MASK_NONFATAL				1
#define NVLW_LINK_INTR_1_MASK_CORRECTABLE			2

#define NVLW_LINK_INTR_2_MASK					0x250
#define NVLW_LINK_INTR_2_MASK_INTRA				3
#define NVLW_LINK_INTR_2_MASK_INTRB				4


/* NVLIPT Registers */
#define NVLIPT_INTR_CONTROL_COMMON				0x4b0
#define NVLIPT_INTR_CONTROL_COMMON_STALLENABLE			0
#define NVLIPT_INTR_CONTROL_COMMON_NOSTALLENABLE		1

#define NVLIPT_INTR_CONTROL_LINK0				0x4b4
#define NVLIPT_INTR_CONTROL_LINK0_STALLENABLE			0
#define NVLIPT_INTR_CONTROL_LINK0_NOSTALLENABLE			1

#define NVLIPT_ERR_UC_FIRST_LINK0				0x530

#define NVLIPT_ERR_UC_STATUS_LINK0				0x524
#define NVLIPT_ERR_UC_STATUS_LINK0_DLPROTOCOL			4
#define NVLIPT_ERR_UC_STATUS_LINK0_DATAPOISONED			12
#define NVLIPT_ERR_UC_STATUS_LINK0_FLOWCONTROL			13
#define NVLIPT_ERR_UC_STATUS_LINK0_RESPONSETIMEOUT		14
#define NVLIPT_ERR_UC_STATUS_LINK0_TARGETERROR			15
#define NVLIPT_ERR_UC_STATUS_LINK0_UNEXPECTEDRESPONSE		16
#define NVLIPT_ERR_UC_STATUS_LINK0_RECEIVEROVERFLOW		17
#define NVLIPT_ERR_UC_STATUS_LINK0_MALFORMEDPACKET		18
#define NVLIPT_ERR_UC_STATUS_LINK0_STOMPEDPACKETRECEIVED	19
#define NVLIPT_ERR_UC_STATUS_LINK0_UNSUPPORTEDREQUEST		20
#define NVLIPT_ERR_UC_STATUS_LINK0_UCINTERNAL			22


/* MINION Registers */
#define CMINION_FALCON_IRQSCLR					0x4

#define CMINION_FALCON_IRQSTAT					0x8
#define CMINION_FALCON_IRQSTAT_WDTMR				1
#define CMINION_FALCON_IRQSTAT_HALT				4
#define CMINION_FALCON_IRQSTAT_EXTERR				5
#define CMINION_FALCON_IRQSTAT_SWGEN0				6
#define CMINION_FALCON_IRQSTAT_SWGEN1				7

#define CMINION_FALCON_IRQMASK					0x18

#define CMINION_FALCON_IRQDEST					0x1c

#define CMINION_FALCON_MAILBOX0					0x40

#define CMINION_FALCON_MAILBOX1					0x44

#define CMINION_FALCON_IDLESTATE				0x4c

#define CMINION_FALCON_CURCTX					0x50

#define CMINION_FALCON_NXTCTX					0x54

#define CMINION_FALCON_OS					0x80
#define CMINION_FALCON_OS_MINOR_VER_MASK			0xffff
#define CMINION_FALCON_OS_MINOR_VER_SHIFT			0
#define CMINION_FALCON_OS_MAJOR_VER_MASK			0xffff0000
#define CMINION_FALCON_OS_MAJOR_VER_SHIFT			16

#define CMINION_FALCON_DEBUG1					0x90

#define CMINION_FALCON_DEBUGINFO				0x94

#define CMINION_FALCON_ENGCTL					0xa4

#define CMINION_FALCON_CPUCTL					0x100
#define CMINION_FALCON_CPUCTL_STARTCPU				1

#define CMINION_FALCON_BOOTVEC					0x104

#define CMINION_FALCON_HWCFG					0x108

#define CMINION_FALCON_DMACTL					0x10c
#define CMINION_FALCON_DMACTL_DMEM_SCRUBBING			1
#define CMINION_FALCON_DMACTL_IMEM_SCRUBBING			2

#define CMINION_FALCON_TRACEIDX					0x148
#define CMINION_FALCON_TRACEIDX_IDX_F(v)			((v & 0xff) \
									<< 0)
#define CMINION_FALCON_TRACEIDX_MAXIDX_V(r)			((r >> 16) \
									& 0xff)

#define CMINION_FALCON_TRACEPC					0x14c
#define CMINION_FALCON_TRACEPC_PC_V(r)				((r >> 0) \
								& 0xffffff)

#define CMINION_FALCON_IMEMC					0x180
#define CMINION_FALCON_IMEMC_BLK_MASK				0xff00
#define CMINION_FALCON_IMEMC_BLK_SHIFT				8
#define CMINION_FALCON_IMEMC_AINCW				24
#define CMINION_FALCON_IMEMC_AINCR				25
#define CMINION_FALCON_IMEMC_SECURE				28

#define CMINION_FALCON_IMEMD					0x184

#define CMINION_FALCON_IMEMT					0x188

#define CMINION_FALCON_DMEMC					0x1c0
#define CMINION_FALCON_DMEMC_AINCR				25
#define CMINION_FALCON_DMEMC_BLK_MASK				0xff00
#define CMINION_FALCON_DMEMC_BLK_SHIFT				8
#define CMINION_FALCON_DMEMC_AINCW				24

#define CMINION_FALCON_DMEMD					0x1c4

#define CMINION_FALCON_SCTL					0x240
#define CMINION_FALCON_SCTL_HSMODE				1

#define MINION_MINION_DEVICES					0x800

#define MINION_MINION_INTR					0x810
#define MINION_MINION_INTR_FATAL				0
#define MINION_MINION_INTR_NONFATAL				1
#define MINION_MINION_INTR_FALCON_STALL				2
#define MINION_MINION_INTR_FALCON_NOSTALL			3
#define MINION_MINION_INTR_LINK_V(x)			(((x) >> 16) & 0xffff)

#define MINION_MINION_INTR_STALL_EN				0x818
#define MINION_MINION_INTR_STALL_EN_FATAL			0
#define MINION_MINION_INTR_STALL_EN_NONFATAL			1
#define MINION_MINION_INTR_STALL_EN_FALCON_STALL		2
#define MINION_MINION_INTR_STALL_EN_FALCON_NOSTALL		3
#define MINION_MINION_INTR_STALL_EN_LINK(x)		(((x) & 0xffff) << 16)
#define MINION_MINION_INTR_STALL_EN_LINK_ENABLE_ALL		0x0000ffff

#define MINION_MINION_INTR_NONSTALL_EN				0x81c

#define MINION_MINION_STATUS					0x830
#define MINION_MINION_STATUS_STATUS_MASK			0xff
#define MINION_MINION_STATUS_STATUS_SHIFT			0
#define MINION_MINION_STATUS_STATUS_INIT			0
#define MINION_MINION_STATUS_STATUS_BOOT			1

#define MINION_MISC						0x8b0

#define MINION_NVLINK_DL_CMD					0x900
#define MINION_NVLINK_DL_CMD_COMMAND_MASK			0xff
#define MINION_NVLINK_DL_CMD_COMMAND_SHIFT			0
#define MINION_NVLINK_DL_CMD_COMMAND_NOP			0
#define MINION_NVLINK_DL_CMD_COMMAND_INITPHY			1
#define MINION_NVLINK_DL_CMD_COMMAND_SWINTR			2
#define MINION_NVLINK_DL_CMD_COMMAND_INITLANEENABLE		3
#define MINION_NVLINK_DL_CMD_COMMAND_INITDLPL			4
#define MINION_NVLINK_DL_CMD_COMMAND_LANEDISABLE		8
#define MINION_NVLINK_DL_CMD_COMMAND_FASTLANEDISABLE		9
#define MINION_NVLINK_DL_CMD_COMMAND_SETACMODE			10
#define MINION_NVLINK_DL_CMD_COMMAND_CLRACMODE			11
#define MINION_NVLINK_DL_CMD_COMMAND_ENABLEPM			16
#define MINION_NVLINK_DL_CMD_COMMAND_DISABLEPM			17
#define MINION_NVLINK_DL_CMD_COMMAND_SAVESTATE			24
#define MINION_NVLINK_DL_CMD_COMMAND_RESTORESTATE		25
#define MINION_NVLINK_DL_CMD_COMMAND_INITPLL_0			32
#define MINION_NVLINK_DL_CMD_COMMAND_INITPLL_1			33
#define MINION_NVLINK_DL_CMD_COMMAND_INITPLL_2			34
#define MINION_NVLINK_DL_CMD_COMMAND_INITPLL_3			35
#define MINION_NVLINK_DL_CMD_COMMAND_INITPLL_4			36
#define MINION_NVLINK_DL_CMD_COMMAND_INITPLL_5			37
#define MINION_NVLINK_DL_CMD_COMMAND_INITPLL_6			38
#define MINION_NVLINK_DL_CMD_COMMAND_INITPLL_7			39
#define MINION_NVLINK_DL_CMD_COMMAND_CONFIGEOM			64
#define MINION_NVLINK_DL_CMD_COMMAND_SETNEA			65
#define MINION_NVLINK_DL_CMD_COMMAND_XAVIER_PLLOVERRIDE_ON	80
#define MINION_NVLINK_DL_CMD_COMMAND_XAVIER_PLLOVERRIDE_OFF	81
#define MINION_NVLINK_DL_CMD_COMMAND_XAVIER_CALIBRATEPLL	82
#define MINION_NVLINK_DL_CMD_COMMAND_ALWAYSFAULT		255
#define MINION_NVLINK_DL_CMD_FAULT				30
#define MINION_NVLINK_DL_CMD_READY				31

#define MINION_NVLINK_LINK_DL_STAT				0x980

#define MINION_NVLINK_LINK_INTR					0xa00
#define MINION_NVLINK_LINK_INTR_CODE_MASK			0xff
#define MINION_NVLINK_LINK_INTR_CODE_SHIFT			0
#define MINION_NVLINK_LINK_INTR_CODE_NA				0
#define MINION_NVLINK_LINK_INTR_CODE_SWREQ			1
#define MINION_NVLINK_LINK_INTR_CODE_DLREQ			2
#define MINION_NVLINK_LINK_INTR_CODE_PMDISABLED			3
#define MINION_NVLINK_LINK_INTR_CODE_DLCMDFAULT			4
#define MINION_NVLINK_LINK_INTR_CODE_NOINIT			16
#define MINION_NVLINK_LINK_INTR_CODE_BADINIT			32
#define MINION_NVLINK_LINK_INTR_CODE_PMFAIL			33
#define MINION_NVLINK_LINK_INTR_STATE				31


/* NVL Registers */
#define NVL_LINK_STATE						0x0
#define NVL_LINK_STATE_STATE_MASK				0xff
#define NVL_LINK_STATE_STATE_SHIFT				0
#define NVL_LINK_STATE_STATE_INIT				0
#define NVL_LINK_STATE_STATE_HWCFG				1
#define NVL_LINK_STATE_STATE_SWCFG				2
#define NVL_LINK_STATE_STATE_ACTIVE				3
#define NVL_LINK_STATE_STATE_FAULT				4
#define NVL_LINK_STATE_STATE_RCVY_AC				8
#define NVL_LINK_STATE_STATE_RCVY_SW				9
#define NVL_LINK_STATE_STATE_RCVY_RX				10

#define NVL_LINK_CONFIG						0x18
#define NVL_LINK_CONFIG_LINK_EN					31

#define NVL_LINK_CHANGE					0x40
#define NVL_LINK_CHANGE_ACTION_F(x)			(((x) & 0x3) << 2)
#define NVL_LINK_CHANGE_ACTION_LTSSM_CHANGE		1
#define NVL_LINK_CHANGE_ACTION_LTSSM_FORCE		3
#define NVL_LINK_CHANGE_NEWSTATE_F(x)			(((x) & 0xf) << 4)
#define NVL_LINK_CHANGE_NEWSTATE_INIT			0
#define NVL_LINK_CHANGE_NEWSTATE_HWCFG			1
#define NVL_LINK_CHANGE_NEWSTATE_SWCFG			2
#define NVL_LINK_CHANGE_NEWSTATE_ACTIVE			3
#define NVL_LINK_CHANGE_OLDSTATE_MASK_F(x)		(((x) & 0xf) << 16)
#define NVL_LINK_CHANGE_OLDSTATE_MASK_DONTCARE		0xf

#define NVL_SUBLINK_CHANGE				0x44
#define NVL_SUBLINK_CHANGE_STATUS_MASK			3
#define NVL_SUBLINK_CHANGE_STATUS_DONE			0
#define NVL_SUBLINK_CHANGE_STATUS_BUSY			1
#define NVL_SUBLINK_CHANGE_STATUS_FAULT			2
#define NVL_SUBLINK_CHANGE_STATUS_ABORT			3
#define NVL_SUBLINK_CHANGE_ACTION_F(x)			(((x) & 0x3) << 2)
#define NVL_SUBLINK_CHANGE_ACTION_SLSM_CHANGE		1
#define NVL_SUBLINK_CHANGE_ACTION_SLSM_FORCE		3
#define NVL_SUBLINK_CHANGE_NEWSTATE_F(x)		(((x) & 0xf) << 4)
#define NVL_SUBLINK_CHANGE_NEWSTATE_HS			0
#define NVL_SUBLINK_CHANGE_NEWSTATE_EIGHTH		4
#define NVL_SUBLINK_CHANGE_NEWSTATE_SAFE		6
#define NVL_SUBLINK_CHANGE_NEWSTATE_OFF			7
#define NVL_SUBLINK_CHANGE_SUBLINK_F(x)			(((x) & 0xf) << 12)
#define NVL_SUBLINK_CHANGE_SUBLINK_TX			0
#define NVL_SUBLINK_CHANGE_SUBLINK_RX			1

#define NVL_INTR						0x50
#define NVL_INTR_TX_REPLAY					0
#define NVL_INTR_TX_RECOVERY_SHORT				1
#define NVL_INTR_TX_RECOVERY_LONG				2
#define NVL_INTR_TX_FAULT_RAM					4
#define NVL_INTR_TX_FAULT_INTERFACE				5
#define NVL_INTR_TX_FAULT_SUBLINK_CHANGE			8
#define NVL_INTR_RX_FAULT_SUBLINK_CHANGE			16
#define NVL_INTR_RX_FAULT_DL_PROTOCOL				20
#define NVL_INTR_RX_SHORT_ERROR_RATE				21
#define NVL_INTR_RX_LONG_ERROR_RATE				22
#define NVL_INTR_RX_ILA_TRIGGER					23
#define NVL_INTR_RX_CRC_COUNTER					24
#define NVL_INTR_LTSSM_FAULT					28
#define NVL_INTR_LTSSM_PROTOCOL					29
#define NVL_INTR_MINION_REQUEST					30

#define NVL_INTR_SW2						0x54

#define NVL_INTR_STALL_EN					0x58
#define NVL_INTR_STALL_EN_TX_REPLAY				0
#define NVL_INTR_STALL_EN_TX_RECOVERY_SHORT			1
#define NVL_INTR_STALL_EN_TX_RECOVERY_LONG			2
#define NVL_INTR_STALL_EN_TX_FAULT_RAM				4
#define NVL_INTR_STALL_EN_TX_FAULT_INTERFACE			5
#define NVL_INTR_STALL_EN_TX_FAULT_SUBLINK_CHANGE		8
#define NVL_INTR_STALL_EN_RX_FAULT_SUBLINK_CHANGE		16
#define NVL_INTR_STALL_EN_RX_FAULT_DL_PROTOCOL			20
#define NVL_INTR_STALL_EN_RX_SHORT_ERROR_RATE			21
#define NVL_INTR_STALL_EN_RX_SHORT_ERROR_RATE_ENABLE		1
#define NVL_INTR_STALL_EN_RX_LONG_ERROR_RATE			22
#define NVL_INTR_STALL_EN_RX_ILA_TRIGGER			23
#define NVL_INTR_STALL_EN_RX_CRC_COUNTER			24
#define NVL_INTR_STALL_EN_LTSSM_FAULT				28
#define NVL_INTR_STALL_EN_LTSSM_PROTOCOL			29
#define NVL_INTR_STALL_EN_MINION_REQUEST			30

#define NVL_INTR_NONSTALL_EN					0x5c

#define NVL_SL0_SAFE_CTRL2_TX					0x2008

#define NVL_SL0_TRAIN0_TX					0x2018

#define NVL_SL0_TRAIN1_TX					0x201c

#define NVL_BR0_CFG_CTL_CAL					0x281c
#define NVL_BR0_CFG_CTL_CAL_RXCAL				0
#define NVL_BR0_CFG_CTL_CAL_INIT_TRAIN_DONE			1
#define NVL_BR0_CFG_CTL_CAL_EOM_DIS				2

#define NVL_BR0_CFG_STATUS_CAL					0x2838
#define NVL_BR0_CFG_STATUS_CAL_RXCAL_DONE			2

#define NVL_SL1_CONFIG_RX					0x3000
#define NVL_SL1_CONFIG_RX_HW_LANE_REVERSE			8
#define NVL_SL1_CONFIG_RX_LANE_REVERSE				24
#define NVL_SL1_CONFIG_RX_REVERSAL_OVERRIDE			29

#define NVL_SL1_SLSM_STATUS_RX					0x3014
#define NVL_SL1_SLSM_STATUS_RX_PRIMARY_STATE_MASK		0xf0
#define NVL_SL1_SLSM_STATUS_RX_PRIMARY_STATE_SHIFT		4
#define NVL_SL1_SLSM_STATUS_RX_PRIMARY_STATE_HS			0
#define NVL_SL1_SLSM_STATUS_RX_PRIMARY_STATE_EIGHTH		4
#define NVL_SL1_SLSM_STATUS_RX_PRIMARY_STATE_SAFE		6
#define NVL_SL1_SLSM_STATUS_RX_PRIMARY_STATE_OFF		7

#define NVL_SL0_SLSM_STATUS_TX					0x2024
#define NVL_SL0_SLSM_STATUS_TX_PRIMARY_STATE_MASK		0xf0
#define NVL_SL0_SLSM_STATUS_TX_PRIMARY_STATE_SHIFT		4
#define NVL_SL0_SLSM_STATUS_TX_PRIMARY_STATE_HS			0
#define NVL_SL0_SLSM_STATUS_TX_PRIMARY_STATE_EIGHTH		4
#define NVL_SL0_SLSM_STATUS_TX_PRIMARY_STATE_SAFE		6
#define NVL_SL0_SLSM_STATUS_TX_PRIMARY_STATE_OFF		7

#define NVL_TXIOBIST_CONFIG					0x2e10
#define NVL_TXIOBIST_CONFIG_DPG_PRBSSEEDLD			2

#define NVL_SL1_RXSLSM_TIMEOUT_2				0x3034

#define NVL_SL1_ERROR_RATE_CTRL					0x3284
#define NVL_SL1_ERROR_RATE_CTRL_SHORT_THRESHOLD_MAN_F(x) (((x) & 0x7) << 0)
#define NVL_SL1_ERROR_RATE_CTRL_LONG_THRESHOLD_MAN_F(x)	(((x) & 0x7) << 16)

#define NVL_SL1_ERROR_COUNT_CTRL			0x3280
#define NVL_SL1_ERROR_COUNT_CTRL_CLEAR_FLIT_CRC		0
#define NVL_SL1_ERROR_COUNT_CTRL_CLEAR_LANE_CRC		1
#define NVL_SL1_ERROR_COUNT_CTRL_CLEAR_RATES		2

#define NVL_SL0_ERROR_COUNT_CTRL			0x2280
#define NVL_SL0_ERROR_COUNT_CTRL_CLEAR_REPLAY		8

#define NVL_ERROR_COUNT_CTRL				0x80
#define NVL_ERROR_COUNT_CTRL_CLEAR_RECOVERY		2

#define NVL_SL1_ERROR_COUNT1				0x3288
#define NVL_SL1_ERROR_COUNT1_FLIT_CRC_ERRORS_V(x)	(((x) >> 0) & 0xffff)

#define NVL_SL1_ERROR_COUNT2_LANECRC			0x328c
#define NVL_SL1_ERROR_COUNT2_LANECRC_L0_V(x)		(((x) >> 0) & 0xff)
#define NVL_SL1_ERROR_COUNT2_LANECRC_L1_V(x)		(((x) >> 8) & 0xff)
#define NVL_SL1_ERROR_COUNT2_LANECRC_L2_V(x)		(((x) >> 16) & 0xff)
#define NVL_SL1_ERROR_COUNT2_LANECRC_L3_V(x)		(((x) >> 24) & 0xff)

#define NVL_SL1_ERROR_COUNT3_LANECRC			0x3290
#define NVL_SL1_ERROR_COUNT3_LANECRC_L4_V(x)		(((x) >> 0) & 0xff)
#define NVL_SL1_ERROR_COUNT3_LANECRC_L5_V(x)		(((x) >> 8) & 0xff)
#define NVL_SL1_ERROR_COUNT3_LANECRC_L6_V(x)		(((x) >> 16) & 0xff)
#define NVL_SL1_ERROR_COUNT3_LANECRC_L7_V(x)		(((x) >> 24) & 0xff)

#define NVL_SL0_ERROR_COUNT4				0x2288
#define NVL_SL0_ERROR_COUNT4_REPLAY_EVENTS_V(x)		(((x) >> 16) & 0xffff)

#define NVL_ERROR_COUNT1				0x8c
#define NVL_ERROR_COUNT1_RECOVERY_EVENTS_V(x)		(((x) >> 0) & 0x3ff)


/* NVLTLC Registers */
#define NVLTLC_TX_CTRL_BUFFER_SZ_VC0				0x200

#define NVLTLC_TX_CTRL_BUFFER_SZ_VC1				0x204

#define NVLTLC_TX_CTRL_BUFFER_SZ_VC2				0x208

#define NVLTLC_TX_CTRL_BUFFER_SZ_VC3				0x20c

#define NVLTLC_TX_CTRL_BUFFER_SZ_VC4				0x210

#define NVLTLC_TX_CTRL_BUFFER_SZ_VC5				0x214

#define NVLTLC_TX_CTRL_BUFFER_SZ_VC6				0x218

#define NVLTLC_TX_CTRL_BUFFER_SZ_VC7				0x21c

#define NVLTLC_TX_CTRL_BUFFER_CREDITS_VC0			0x300

#define NVLTLC_TX_CTRL_BUFFER_CREDITS_VC1			0x304

#define NVLTLC_TX_CTRL_BUFFER_CREDITS_VC2			0x308

#define NVLTLC_TX_CTRL_BUFFER_CREDITS_VC3			0x30c

#define NVLTLC_TX_CTRL_BUFFER_CREDITS_VC4			0x310

#define NVLTLC_TX_CTRL_BUFFER_CREDITS_VC5			0x314

#define NVLTLC_TX_CTRL_BUFFER_CREDITS_VC6			0x318

#define NVLTLC_TX_CTRL_BUFFER_CREDITS_VC7			0x31c

#define NVLTLC_TX_CTRL_BUFFER_READY				0x400

#define NVLTLC_TX_ERR_STATUS_0					0x700
#define NVLTLC_TX_ERR_STATUS_0_TXHDRCREDITOVFERR_F(x)	(((x) & 0xff) << 0)
#define NVLTLC_TX_ERR_STATUS_0_TXHDRCREDITOVFERR_V(x)	(((x) >> 0) & 0xff)
#define NVLTLC_TX_ERR_STATUS_0_TXDATACREDITOVFERR_F(x)	(((x) & 0xff) << 8)
#define NVLTLC_TX_ERR_STATUS_0_TXDATACREDITOVFERR_V(x)	(((x) >> 8) & 0xff)
#define NVLTLC_TX_ERR_STATUS_0_TXDLCREDITOVFERR			16
#define NVLTLC_TX_ERR_STATUS_0_TXDLCREDITPARITYERR		17
#define NVLTLC_TX_ERR_STATUS_0_TXRAMHDRPARITYERR		18
#define NVLTLC_TX_ERR_STATUS_0_TXRAMDATAPARITYERR		19
#define NVLTLC_TX_ERR_STATUS_0_TXUNSUPVCOVFERR			20
#define NVLTLC_TX_ERR_STATUS_0_TXSTOMPDET			22
#define NVLTLC_TX_ERR_STATUS_0_TXPOISONDET			23
#define NVLTLC_TX_ERR_STATUS_0_TARGETERR			24
#define NVLTLC_TX_ERR_STATUS_0_UNSUPPORTEDREQUESTERR		25

#define NVLTLC_TX_ERR_LOG_EN_0					0x704

#define NVLTLC_TX_ERR_REPORT_EN_0				0x708
#define NVLTLC_TX_ERR_REPORT_EN_0_TXHDRCREDITOVFERR_F(x) (((x) & 0xff) << 0)
#define NVLTLC_TX_ERR_REPORT_EN_0_TXDATACREDITOVFERR_F(x) (((x) & 0xff) << 8)
#define NVLTLC_TX_ERR_REPORT_EN_0_TXDLCREDITOVFERR		16
#define NVLTLC_TX_ERR_REPORT_EN_0_TXDLCREDITPARITYERR		17
#define NVLTLC_TX_ERR_REPORT_EN_0_TXRAMHDRPARITYERR		18
#define NVLTLC_TX_ERR_REPORT_EN_0_TXRAMDATAPARITYERR		19
#define NVLTLC_TX_ERR_REPORT_EN_0_TXUNSUPVCOVFERR		20
#define NVLTLC_TX_ERR_REPORT_EN_0_TXSTOMPDET			22
#define NVLTLC_TX_ERR_REPORT_EN_0_TXPOISONDET			23
#define NVLTLC_TX_ERR_REPORT_EN_0_TARGETERR			24
#define NVLTLC_TX_ERR_REPORT_EN_0_UNSUPPORTEDREQUESTERR		25

#define NVLTLC_TX_ERR_INJECT_0					0x710
#define NVLTLC_TX_ERR_INJECT_0_TXHDRCREDITOVFERR_V(x)	(((x) >> 0) & 0xff)
#define NVLTLC_TX_ERR_INJECT_0_TXDATACREDITOVFERR_V(x)	(((x) >> 8) & 0xff)
#define NVLTLC_TX_ERR_INJECT_0_TXDLCREDITOVFERR			16
#define NVLTLC_TX_ERR_INJECT_0_TXDLCREDITPARITYERR		17
#define NVLTLC_TX_ERR_INJECT_0_TXRAMHDRPARITYERR		18
#define NVLTLC_TX_ERR_INJECT_0_TXRAMDATAPARITYERR		19
#define NVLTLC_TX_ERR_INJECT_0_TXUNSUPVCOVFERR			20
#define NVLTLC_TX_ERR_INJECT_0_TXSTOMPDET			22
#define NVLTLC_TX_ERR_INJECT_0_TXPOISONDET			23
#define NVLTLC_TX_ERR_INJECT_0_TARGETERR			24
#define NVLTLC_TX_ERR_INJECT_0_UNSUPPORTEDREQUESTERR		25

#define NVLTLC_TX_ERR_FIRST_0					0x714

#define NVLTLC_TX_ERR_CONTAIN_EN_0				0x70c

#define NVLTLC_RX_CTRL_BUFFER_SZ_VC0				0xa00

#define NVLTLC_RX_CTRL_BUFFER_SZ_VC1				0xa04

#define NVLTLC_RX_CTRL_BUFFER_SZ_VC2				0xa08

#define NVLTLC_RX_CTRL_BUFFER_SZ_VC3				0xa0c

#define NVLTLC_RX_CTRL_BUFFER_SZ_VC4				0xa10

#define NVLTLC_RX_CTRL_BUFFER_SZ_VC5				0xa14

#define NVLTLC_RX_CTRL_BUFFER_SZ_VC6				0xa18

#define NVLTLC_RX_CTRL_BUFFER_SZ_VC7				0xa1c

#define NVLTLC_RX_CTRL_BUFFER_CREDITS_VC0			0xb00

#define NVLTLC_RX_CTRL_BUFFER_CREDITS_VC1			0xb04

#define NVLTLC_RX_CTRL_BUFFER_CREDITS_VC2			0xb08

#define NVLTLC_RX_CTRL_BUFFER_CREDITS_VC3			0xb0c

#define NVLTLC_RX_CTRL_BUFFER_CREDITS_VC4			0xb10

#define NVLTLC_RX_CTRL_BUFFER_CREDITS_VC5			0xb14

#define NVLTLC_RX_CTRL_BUFFER_CREDITS_VC6			0xb18

#define NVLTLC_RX_CTRL_BUFFER_CREDITS_VC7			0xb1c

#define NVLTLC_RX_CTRL_BUFFER_READY				0xc00

#define NVLTLC_RX_ERR_LOG_EN_0					0xf04

#define NVLTLC_RX_ERR_REPORT_EN_0				0xf08
#define NVLTLC_RX_ERR_REPORT_EN_0_RXDLHDRPARITYERR		0
#define NVLTLC_RX_ERR_REPORT_EN_0_RXDLDATAPARITYERR		1
#define NVLTLC_RX_ERR_REPORT_EN_0_RXDLCTRLPARITYERR		2
#define NVLTLC_RX_ERR_REPORT_EN_0_RXRAMDATAPARITYERR		3
#define NVLTLC_RX_ERR_REPORT_EN_0_RXRAMHDRPARITYERR		4
#define NVLTLC_RX_ERR_REPORT_EN_0_RXINVALIDAEERR		5
#define NVLTLC_RX_ERR_REPORT_EN_0_RXINVALIDBEERR		6
#define NVLTLC_RX_ERR_REPORT_EN_0_RXINVALIDADDRALIGNERR		7
#define NVLTLC_RX_ERR_REPORT_EN_0_RXPKTLENERR			8
#define NVLTLC_RX_ERR_REPORT_EN_0_RSVCMDENCERR			9
#define NVLTLC_RX_ERR_REPORT_EN_0_RSVDATLENENCERR		10
#define NVLTLC_RX_ERR_REPORT_EN_0_RSVADDRTYPEERR		11
#define NVLTLC_RX_ERR_REPORT_EN_0_RSVRSPSTATUSERR		12
#define NVLTLC_RX_ERR_REPORT_EN_0_RSVPKTSTATUSERR		13
#define NVLTLC_RX_ERR_REPORT_EN_0_RSVCACHEATTRPROBEREQERR	14
#define NVLTLC_RX_ERR_REPORT_EN_0_RSVCACHEATTRPROBERSPERR	15
#define NVLTLC_RX_ERR_REPORT_EN_0_DATLENGTATOMICREQMAXERR	17
#define NVLTLC_RX_ERR_REPORT_EN_0_DATLENGTRMWREQMAXERR		18
#define NVLTLC_RX_ERR_REPORT_EN_0_DATLENLTATRRSPMINERR		19
#define NVLTLC_RX_ERR_REPORT_EN_0_INVALIDCACHEATTRPOERR		20
#define NVLTLC_RX_ERR_REPORT_EN_0_INVALIDCRERR			21
#define NVLTLC_RX_ERR_REPORT_EN_0_RXRESPSTATUSTARGETERR		22
#define NVLTLC_RX_ERR_REPORT_EN_0_RXRESPSTATUSUNSUPPORTEDREQUESTERR	23

#define NVLTLC_RX_ERR_STATUS_0					0xf00
#define NVLTLC_RX_ERR_STATUS_0_RXDLHDRPARITYERR			0
#define NVLTLC_RX_ERR_STATUS_0_RXDLDATAPARITYERR		1
#define NVLTLC_RX_ERR_STATUS_0_RXDLCTRLPARITYERR		2
#define NVLTLC_RX_ERR_STATUS_0_RXRAMDATAPARITYERR		3
#define NVLTLC_RX_ERR_STATUS_0_RXRAMHDRPARITYERR		4
#define NVLTLC_RX_ERR_STATUS_0_RXINVALIDAEERR			5
#define NVLTLC_RX_ERR_STATUS_0_RXINVALIDBEERR			6
#define NVLTLC_RX_ERR_STATUS_0_RXINVALIDADDRALIGNERR		7
#define NVLTLC_RX_ERR_STATUS_0_RXPKTLENERR			8
#define NVLTLC_RX_ERR_STATUS_0_RSVCMDENCERR			9
#define NVLTLC_RX_ERR_STATUS_0_RSVDATLENENCERR			10
#define NVLTLC_RX_ERR_STATUS_0_RSVADDRTYPEERR			11
#define NVLTLC_RX_ERR_STATUS_0_RSVRSPSTATUSERR			12
#define NVLTLC_RX_ERR_STATUS_0_RSVPKTSTATUSERR			13
#define NVLTLC_RX_ERR_STATUS_0_RSVCACHEATTRPROBEREQERR		14
#define NVLTLC_RX_ERR_STATUS_0_RSVCACHEATTRPROBERSPERR		15
#define NVLTLC_RX_ERR_STATUS_0_DATLENGTATOMICREQMAXERR		17
#define NVLTLC_RX_ERR_STATUS_0_DATLENGTRMWREQMAXERR		18
#define NVLTLC_RX_ERR_STATUS_0_DATLENLTATRRSPMINERR		19
#define NVLTLC_RX_ERR_STATUS_0_INVALIDCACHEATTRPOERR		20
#define NVLTLC_RX_ERR_STATUS_0_INVALIDCRERR			21
#define NVLTLC_RX_ERR_STATUS_0_RXRESPSTATUSTARGETERR		22
#define NVLTLC_RX_ERR_STATUS_0_RXRESPSTATUSUNSUPPORTEDREQUESTERR	23

#define NVLTLC_RX_ERR_CONTAIN_EN_0				0xf0c

#define NVLTLC_RX_ERR_INJECT_0					0xf10
#define NVLTLC_RX_ERR_INJECT_0_RXDLHDRPARITYERR			0
#define NVLTLC_RX_ERR_INJECT_0_RXDLDATAPARITYERR		1
#define NVLTLC_RX_ERR_INJECT_0_RXDLCTRLPARITYERR		2
#define NVLTLC_RX_ERR_INJECT_0_RXRAMDATAPARITYERR		3
#define NVLTLC_RX_ERR_INJECT_0_RXRAMHDRPARITYERR		4
#define NVLTLC_RX_ERR_INJECT_0_RXINVALIDAEERR			5
#define NVLTLC_RX_ERR_INJECT_0_RXINVALIDBEERR			6
#define NVLTLC_RX_ERR_INJECT_0_RXINVALIDADDRALIGNERR		7
#define NVLTLC_RX_ERR_INJECT_0_RXPKTLENERR			8
#define NVLTLC_RX_ERR_INJECT_0_RSVCMDENCERR			9
#define NVLTLC_RX_ERR_INJECT_0_RSVDATLENENCERR			10
#define NVLTLC_RX_ERR_INJECT_0_RSVADDRTYPEERR			11
#define NVLTLC_RX_ERR_INJECT_0_RSVRSPSTATUSERR			12
#define NVLTLC_RX_ERR_INJECT_0_RSVPKTSTATUSERR			13
#define NVLTLC_RX_ERR_INJECT_0_RSVCACHEATTRPROBEREQERR		14
#define NVLTLC_RX_ERR_INJECT_0_RSVCACHEATTRPROBERSPERR		15
#define NVLTLC_RX_ERR_INJECT_0_DATLENGTATOMICREQMAXERR		17
#define NVLTLC_RX_ERR_INJECT_0_DATLENGTRMWREQMAXERR		18
#define NVLTLC_RX_ERR_INJECT_0_DATLENLTATRRSPMINERR		19
#define NVLTLC_RX_ERR_INJECT_0_INVALIDCACHEATTRPOERR		20
#define NVLTLC_RX_ERR_INJECT_0_INVALIDCRERR			21
#define NVLTLC_RX_ERR_INJECT_0_RXRESPSTATUSTARGETERR		22
#define NVLTLC_RX_ERR_INJECT_0_RXRESPSTATUSUNSUPPORTEDREQUESTERR	23

#define NVLTLC_RX_ERR_FIRST_0					0xf14

#define NVLTLC_RX_ERR_STATUS_1					0xf18
#define NVLTLC_RX_ERR_STATUS_1_RXHDROVFERR_F(x)		(((x) & 0xff) << 0)
#define NVLTLC_RX_ERR_STATUS_1_RXHDROVFERR_V(x)		(((x) >> 0) & 0xff)
#define NVLTLC_RX_ERR_STATUS_1_RXDATAOVFERR_F(x)	(((x) & 0xff) << 8)
#define NVLTLC_RX_ERR_STATUS_1_RXDATAOVFERR_V(x)	(((x) >> 8) & 0xff)
#define NVLTLC_RX_ERR_STATUS_1_STOMPDETERR			16
#define NVLTLC_RX_ERR_STATUS_1_RXPOISONERR			17
#define NVLTLC_RX_ERR_STATUS_1_CORRECTABLEINTERNALERR		18
#define NVLTLC_RX_ERR_STATUS_1_RXUNSUPVCOVFERR			19
#define NVLTLC_RX_ERR_STATUS_1_RXUNSUPNVLINKCREDITRELERR	20
#define NVLTLC_RX_ERR_STATUS_1_RXUNSUPNCISOCCREDITRELERR	21

#define NVLTLC_RX_ERR_LOG_EN_1					0xf1c

#define NVLTLC_RX_ERR_REPORT_EN_1				0xf20
#define NVLTLC_RX_ERR_REPORT_EN_1_RXHDROVFERR_F(x)	(((x) & 0xff) << 0)
#define NVLTLC_RX_ERR_REPORT_EN_1_RXDATAOVFERR_F(x)	(((x) & 0xff) << 8)
#define NVLTLC_RX_ERR_REPORT_EN_1_STOMPDETERR			16
#define NVLTLC_RX_ERR_REPORT_EN_1_RXPOISONERR			17
#define NVLTLC_RX_ERR_REPORT_EN_1_CORRECTABLEINTERNALERR	18
#define NVLTLC_RX_ERR_REPORT_EN_1_RXUNSUPVCOVFERR		19
#define NVLTLC_RX_ERR_REPORT_EN_1_RXUNSUPNVLINKCREDITRELERR	20
#define NVLTLC_RX_ERR_REPORT_EN_1_RXUNSUPNCISOCCREDITRELERR	21

#define NVLTLC_RX_ERR_CONTAIN_EN_1				0xf24

#define NVLTLC_RX_ERR_INJECT_1					0xf28
#define NVLTLC_RX_ERR_INJECT_1_RXHDROVFERR_V(x)		(((x) >> 0) & 0xff)
#define NVLTLC_RX_ERR_INJECT_1_RXDATAOVFERR_V(x)	(((x) >> 8) & 0xff)
#define NVLTLC_RX_ERR_INJECT_1_STOMPDETERR			16
#define NVLTLC_RX_ERR_INJECT_1_RXPOISONERR			17
#define NVLTLC_RX_ERR_INJECT_1_CORRECTABLEINTERNALERR		18
#define NVLTLC_RX_ERR_INJECT_1_RXUNSUPVCOVFERR			19
#define NVLTLC_RX_ERR_INJECT_1_RXUNSUPNVLINKCREDITRELERR	20
#define NVLTLC_RX_ERR_INJECT_1_RXUNSUPNCISOCCREDITRELERR	21

#define NVLTLC_RX_ERR_FIRST_1					0xf2c

#define NVLTLC_TX_DEBUG_TP_CNTR_CTRL				0x490
#define NVLTLC_TX_DEBUG_TP_CNTR_CTRL_RESETTX0			16
#define NVLTLC_TX_DEBUG_TP_CNTR_CTRL_RESETTX1			17

#define NVLTLC_RX_DEBUG_TP_CNTR_CTRL				0xc90
#define NVLTLC_RX_DEBUG_TP_CNTR_CTRL_RESETRX0			16
#define NVLTLC_RX_DEBUG_TP_CNTR_CTRL_RESETRX1			17

#define NVLTLC_TX_DEBUG_TP_CNTR0_LO				0x49c

#define NVLTLC_TX_DEBUG_TP_CNTR0_HI				0x4a0
#define NVLTLC_TX_DEBUG_TP_CNTR0_HI_ROLLOVER			31

#define NVLTLC_TX_DEBUG_TP_CNTR1_LO				0x4ac

#define NVLTLC_TX_DEBUG_TP_CNTR1_HI				0x4b0
#define NVLTLC_TX_DEBUG_TP_CNTR1_HI_ROLLOVER			31

#define NVLTLC_RX_DEBUG_TP_CNTR0_LO				0xc9c

#define NVLTLC_RX_DEBUG_TP_CNTR0_HI				0xca0
#define NVLTLC_RX_DEBUG_TP_CNTR0_HI_ROLLOVER			31

#define NVLTLC_RX_DEBUG_TP_CNTR1_LO				0xcac

#define NVLTLC_RX_DEBUG_TP_CNTR1_HI				0xcb0
#define NVLTLC_RX_DEBUG_TP_CNTR1_HI_ROLLOVER			31

#define NVLTLC_TX_ERR_STATUS_0				0x700
#define NVLTLC_RX_ERR_STATUS_0				0xf00
#define NVLTLC_RX_ERR_STATUS_1				0xf18

/* MSSNVLINK Registers */
#define MSSNVLINK_MASTER_CREDIT_TRANSINFO			0x10

#define MSSNVLINK_MASTER_CREDIT_INGR_DATA			0x14

#define MSSNVLINK_SLAVE_CREDIT_TRANSINFO			0x20

#define MSSNVLINK_SLAVE_CREDIT_INGR_DATA			0x24


/* NVLINK APERTURES - END */


/* NON-NVLINK APERTURES - START */


/* CPU System Registers */
#define SCF_NVLINK_CFG_TOM_MB_F(x)			(((x) & 0xfffff) << 0)
#define SCF_NVLINK_CFG_EN				31


/*
 * TODO: Currently the MC driver is disabled for T194. Therefore we can't use
 * the MC driver's register read/write APIs (i.e. mc_writel()/mc_readl()). The
 * WAR for this is to introduce a temporary API to access MC registers. We're
 * using MCB_BASE for this WAR. Remove this WAR once the MC driver gets enabled
 * for T194.
 */
/* MC Registers */
#define MCB_BASE					0x2c10000


/* NON-NVLINK APERTURES - END */

#endif /* NVLINK_REGS_H */
