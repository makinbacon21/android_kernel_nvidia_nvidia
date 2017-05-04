/*
 * Tegra 12x SoC-specific mcerr code.
 *
 * Copyright (c) 2014, NVIDIA Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#define pr_fmt(fmt) "mc-err: " fmt

#include <linux/of.h>
#include <linux/moduleparam.h>
#include <linux/platform/tegra/mcerr.h>
#include <dt-bindings/memory/tegra-swgroup.h>

/*** Auto generated by `mcp.pl'. Do not modify! ***/

struct mc_client mc_clients[] = {
	client("ptc", "csr_ptcr", INVALID),
	client("dc", "csr_display0a", DC),
	client("dcb", "csr_display0ab", DCB),
	client("dc", "csr_display0b", DC),
	client("dcb", "csr_display0bb", DCB),
	client("dc", "csr_display0c", DC),
	client("dcb", "csr_display0cb", DCB),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("afi", "csr_afir", AFI),
	client("avpc", "csr_avpcarm7r", AVPC),
	client("dc", "csr_displayhc", DC),
	client("dcb", "csr_displayhcb", DCB),
	dummy_client,
	dummy_client,
	dummy_client,
	client("hda", "csr_hdar", HDA),
	client("hc", "csr_host1xdmar", HC),
	client("hc", "csr_host1xr", HC),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("nvenc", "csr_nvencsrd", NVENC),
	client("ppcs", "csr_ppcsahbdmar", PPCS),
	client("ppcs", "csr_ppcsahbslvr", PPCS),
	client("sata", "csr_satar", SATA),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("mpcore", "csr_mpcorer", INVALID),
	dummy_client,
	dummy_client,
	dummy_client,
	client("nvenc", "csw_nvencswr", NVENC),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("afi", "csw_afiw", AFI),
	client("avpc", "csw_avpcarm7w", AVPC),
	dummy_client,
	dummy_client,
	client("hda", "csw_hdaw", HDA),
	client("hc", "csw_host1xw", HC),
	dummy_client,
	dummy_client,
	client("mpcore", "csw_mpcorew", INVALID),
	dummy_client,
	client("ppcs", "csw_ppcsahbdmaw", PPCS),
	client("ppcs", "csw_ppcsahbslvw", PPCS),
	client("sata", "csw_sataw", SATA),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("isp2", "csr_ispra", ISP2),
	dummy_client,
	client("isp2", "csw_ispwa", ISP2),
	client("isp2", "csw_ispwb", ISP2),
	dummy_client,
	dummy_client,
	client("xusb_host", "csr_xusb_hostr", XUSB_HOST),
	client("xusb_host", "csw_xusb_hostw", XUSB_HOST),
	client("xusb_dev", "csr_xusb_devr", XUSB_DEV),
	client("xusb_dev", "csw_xusb_devw", XUSB_DEV),
	client("isp2b", "csr_isprab", ISP2B),
	dummy_client,
	client("isp2b", "csw_ispwab", ISP2B),
	client("isp2b", "csw_ispwbb", ISP2B),
	dummy_client,
	dummy_client,
	client("tsec", "csr_tsecsrd", TSEC),
	client("tsec", "csw_tsecswr", TSEC),
	client("a9avp", "csr_a9avpscr", A9AVP),
	client("a9avp", "csw_a9avpscw", A9AVP),
	client("gpu", "csr_gpusrd", GPU),
	client("gpu", "csw_gpuswr", GPU),
	client("dc", "csr_displayt", DC),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("sdmmc1a", "csr_sdmmcra", SDMMC1A),
	client("sdmmc2a", "csr_sdmmcraa", SDMMC2A),
	client("sdmmc3a", "csr_sdmmcr", SDMMC3A),
	client("sdmmc4a", "csr_sdmmcrab", SDMMC4A),
	client("sdmmc1a", "csw_sdmmcwa", SDMMC1A),
	client("sdmmc2a", "csw_sdmmcwaa", SDMMC2A),
	client("sdmmc3a", "csw_sdmmcw", SDMMC3A),
	client("sdmmc4a", "csw_sdmmcwab", SDMMC4A),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("vic", "csr_vicsrd", VIC),
	client("vic", "csw_vicswr", VIC),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("vi", "csw_viw", VI),
	client("dc", "csr_displayd", DC),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("nvdec", "csr_nvdecsrd", NVDEC),
	client("nvdec", "csw_nvdecswr", NVDEC),
	client("ape", "csr_aper", INVALID),
	client("ape", "csw_apew", INVALID),
	dummy_client,
	dummy_client,
	client("nvjpg", "csr_nvjpgsrd", NVJPG),
	client("nvjpg", "csw_nvjpgswr", NVJPG),
	client("se", "csr_sesrd", SE),
	client("se", "csw_seswr", SE),
	client("axiap", "csr_axiapr", INVALID),
	client("axiap", "csw_axiapw", INVALID),
	client("etr", "csr_etrr", INVALID),
	client("etr", "csw_etrw", INVALID),
	client("tsecb", "csr_tsecsrdb", TSECB),
	client("tsecb", "csw_tsecswrb", TSECB),
	client("gpu", "csr_gpusrd2", GPU),
	client("gpu", "csw_gpuswr2", GPU),
};
int mc_client_last = ARRAY_SIZE(mc_clients) - 1;
/*** Done. ***/

static const char *t210_intr_info[] = {
	NULL,		/* Bit 0 */
	NULL,
	NULL,
	NULL,
	NULL,		/* Bit 4 */
	NULL,
	"decerr-emem",
	NULL,
	"secerr",	/* Bit 8 */
	"arb-emem",
	"smmu-err",
	"apb_err",
	"decerr-vpr",	/* Bit 12 */
	"decerr-sec",
	NULL,
	NULL,
	"decerr-mts",	/* Bit 16 */
	"decerr-gsc",
	NULL,
	NULL,
	NULL,		/* Bit 20 */
	NULL,
	NULL,
	NULL,
	NULL,		/* Bit 24 */
	NULL,
	NULL,
	NULL,
	NULL,		/* Bit 28 */
	NULL,
	NULL,
	NULL,
};

/*
 * Some platforms report SMMU errors via the SMMU driver.
 */
static const char *const smmu_page_attrib[] = {
	"nr-nw-s",
	"nr-nw-ns",
	"nr-wr-s",
	"nr-wr-ns",
	"rd-nw-s",
	"rd-nw-ns",
	"rd-wr-s",
	"rd-wr-ns"
};

/*
 * Table of known errors and their interrupt signatures.
 */
static const struct mc_error mc_errors[] = {
	MC_ERR(MC_INT_DECERR_EMEM,
	       "EMEM address decode error",
	       0, MC_ERR_STATUS, MC_ERR_ADR),
	MC_ERR(MC_INT_DECERR_VPR,
	       "MC request violates VPR requirements",
	       E_VPR, MC_ERR_VPR_STATUS, MC_ERR_VPR_ADR),
	MC_ERR(MC_INT_SECURITY_VIOLATION,
	       "non secure access to secure region",
	       0, MC_ERR_STATUS, MC_ERR_ADR),
	MC_ERR(MC_INT_DECERR_EMEM | MC_INT_SECURITY_VIOLATION,
	       "non secure access to secure region",
	       0, MC_ERR_STATUS, MC_ERR_ADR),
	MC_ERR(MC_INT_SECERR_SEC,
	       "MC request violated SEC carveout requirements",
	       0, MC_ERR_SEC_STATUS, MC_ERR_SEC_ADR),

	/*
	 * SMMU related faults.
	 */
	MC_ERR(MC_INT_INVALID_SMMU_PAGE,
	       "SMMU address translation fault",
	       E_SMMU, MC_ERR_STATUS, MC_ERR_ADR),
	MC_ERR(MC_INT_INVALID_SMMU_PAGE | MC_INT_DECERR_EMEM,
	       "EMEM decode error on PDE or PTE entry",
	       E_SMMU, MC_ERR_STATUS, MC_ERR_ADR),
	MC_ERR(MC_INT_INVALID_SMMU_PAGE | MC_INT_SECERR_SEC,
	       "secure SMMU address translation fault",
	       E_SMMU, MC_ERR_SEC_STATUS, MC_ERR_SEC_ADR),
	MC_ERR(MC_INT_INVALID_SMMU_PAGE | MC_INT_DECERR_VPR,
	       "VPR SMMU address translation fault",
	       E_VPR | E_SMMU, MC_ERR_VPR_STATUS, MC_ERR_VPR_ADR),
	MC_ERR(MC_INT_INVALID_SMMU_PAGE | MC_INT_DECERR_VPR |
	       MC_INT_DECERR_EMEM,
	       "EMEM decode error on PDE or PTE entry on VPR context",
	       E_VPR | E_SMMU, MC_ERR_VPR_STATUS, MC_ERR_VPR_ADR),

	/*
	 * MTS access violation.
	 */
	MC_ERR(MC_INT_DECERR_MTS,
	       "MTS carveout access violation",
	       0, MC_ERR_MTS_STATUS, MC_ERR_MTS_ADR),

	/*
	 * Generalized carveouts.
	 */
	MC_ERR(MC_INT_DECERR_GENERALIZED_CARVEOUT,
	       "GSC access violation", 0,
	       MC_ERR_GENERALIZED_CARVEOUT_STATUS,
	       MC_ERR_GENERALIZED_CARVEOUT_ADR),
	MC_ERR(MC_INT_DECERR_GENERALIZED_CARVEOUT | MC_INT_DECERR_EMEM,
	       "EMEM GSC access violation", 0,
	       MC_ERR_GENERALIZED_CARVEOUT_STATUS,
	       MC_ERR_GENERALIZED_CARVEOUT_ADR),

	/*
	 * Miscellaneous errors.
	 */
	MC_ERR(MC_INT_INVALID_APB_ASID_UPDATE,
	       "invalid APB ASID update", 0,
	       MC_ERR_STATUS, MC_ERR_ADR),

	/* NULL terminate. */
	MC_ERR(0, NULL, 0, 0, 0),
};

static int arb_intr_mma_set(const char *arg, const struct kernel_param *kp);
static int arb_intr_mma_get(char *buff, const struct kernel_param *kp);

static struct arb_emem_intr_info arb_intr_info = {
	.lock = __SPIN_LOCK_UNLOCKED(arb_intr_info.lock),
};
static int arb_intr_count;

static struct kernel_param_ops arb_intr_mma_ops = {
	.get = arb_intr_mma_get,
	.set = arb_intr_mma_set,
};

module_param_cb(arb_intr_mma_in_ms, &arb_intr_mma_ops,
		&arb_intr_info.arb_intr_mma, S_IRUGO | S_IWUSR);
module_param(arb_intr_count, int, S_IRUGO | S_IWUSR);

static int arb_intr_mma_set(const char *arg, const struct kernel_param *kp)
{
	int ret;
	unsigned long flags;

	spin_lock_irqsave(&arb_intr_info.lock, flags);
	ret = param_set_int(arg, kp);
	spin_unlock_irqrestore(&arb_intr_info.lock, flags);
	return ret;
}

static int arb_intr_mma_get(char *buff, const struct kernel_param *kp)
{
	return param_get_int(buff, kp);
}

static const struct mc_error *mcerr_default_info(u32 intr)
{
	const struct mc_error *err;

	for (err = mc_errors; err->sig && err->msg; err++) {
		if (intr != err->sig)
			continue;
		return err;
	}

	return NULL;
}

void __weak smmu_dump_pagetable(int swgid, dma_addr_t addr)
{
}

/*
 * This will print at least 8 hex digits for address. If the address is bigger
 * then more digits will be printed but the full 16 hex digits for a 64 bit
 * address will not get printed by the current code.
 */
static void mcerr_default_print(const struct mc_error *err,
				const struct mc_client *client,
				u32 status, phys_addr_t addr,
				int secure, int rw, const char *smmu_info)
{
	if (smmu_info)
		smmu_dump_pagetable(client->swgid, addr);

	if (err->flags & E_VPR)
		mcerr_pr("vpr base=%x:%x, size=%x, ctrl=%x, override:(%x, %x, %x, %x)\n",
			 mc_readl(MC_VIDEO_PROTECT_BOM_ADR_HI),
			 mc_readl(MC_VIDEO_PROTECT_BOM),
			 mc_readl(MC_VIDEO_PROTECT_SIZE_MB),
			 mc_readl(MC_VIDEO_PROTECT_REG_CTRL),
			 mc_readl(MC_VIDEO_PROTECT_VPR_OVERRIDE),
			 mc_readl(MC_VIDEO_PROTECT_VPR_OVERRIDE1),
			 mc_readl(MC_VIDEO_PROTECT_GPU_OVERRIDE_0),
			 mc_readl(MC_VIDEO_PROTECT_GPU_OVERRIDE_1));

	mcerr_pr("(%d) %s: %s\n", client->swgid, client->name, err->msg);
	mcerr_pr("  status = 0x%08x; addr = 0x%08llx\n", status,
		 (long long unsigned int)addr);
	mcerr_pr("  secure: %s, access-type: %s, SMMU fault: %s\n",
		secure ? "yes" : "no", rw ? "write" : "read",
		smmu_info ? smmu_info : "none");
}

static void arb_intr(void)
{
	u64 time;
	u32 time_diff_ms;
	unsigned long flags;

	spin_lock_irqsave(&arb_intr_info.lock, flags);
	arb_intr_count++;
	time = sched_clock();
	time_diff_ms = (time - arb_intr_info.time) >> 20;
	arb_intr_info.time = time;
	arb_intr_info.arb_intr_mma =
		((MMA_HISTORY_SAMPLES - 1) * time_diff_ms +
		 arb_intr_info.arb_intr_mma) / MMA_HISTORY_SAMPLES;
	spin_unlock_irqrestore(&arb_intr_info.lock, flags);
}

static void clear_interrupt(unsigned int irq)
{
	mc_writel(0x00033F40, MC_INTSTATUS);
}

static void mcerr_info_update(struct mc_client *c, u32 stat)
{
	int i;

	for (i = 0; i < (sizeof(stat) * 8); i++) {
		if (stat & (1 << i))
			c->intr_counts[i]++;
	}
}

static void log_mcerr_fault(unsigned int irq)
{
	struct mc_client *client;
	const struct mc_error *fault;
	const char *smmu_info;
	phys_addr_t addr;
	u32 status, write, secure, client_id;
	int src_chan = MC_BROADCAST_CHANNEL;
	u32 intstatus = mc_int_mask &
			__mc_readl(src_chan, MC_INTSTATUS);


	if (intstatus & MC_INT_ARBITRATION_EMEM) {
		arb_intr();
		if (intstatus == MC_INT_ARBITRATION_EMEM)
			return;
		intstatus &= ~MC_INT_ARBITRATION_EMEM;
	}

	fault = mcerr_default_info(intstatus & mc_int_mask);
	if (WARN(!fault, "Unknown error! intr sig: 0x%08x\n",
		 intstatus & mc_int_mask))
		return;

	if (fault->flags & E_NO_STATUS) {
		mcerr_pr("MC fault - no status: %s\n", fault->msg);
		return;
	}

	status = __mc_readl(src_chan, fault->stat_reg);
	addr = __mc_readl(src_chan, fault->addr_reg);

	if (fault->flags & E_TWO_STATUS) {
		mcerr_pr("MC fault - %s\n", fault->msg);
		mcerr_pr("status: 0x%08x status2: 0x%08llx\n",
			status, addr);
		return;
	}

	secure = !!(status & MC_ERR_STATUS_SECURE);
	write = !!(status & MC_ERR_STATUS_WRITE);
	client_id = status & 0xff;
	client = &mc_clients[client_id <= mc_client_last
				     ? client_id : mc_client_last];

	mcerr_info_update(client, intstatus & mc_int_mask);

	/*
	 * LPAE: make sure we get the extra 2 physical address bits available
	 * and pass them down to the printing function.
	 */
	addr |= (((phys_addr_t)(status & MC_ERR_STATUS_ADR_HI)) << 12);

	if (fault->flags & E_SMMU)
		smmu_info = smmu_page_attrib[MC_ERR_SMMU_BITS(status)];
	else
		smmu_info = NULL;

	mcerr_default_print(fault, client, status, addr, secure, write,
				  smmu_info);
}

/*
 * Set up chip specific functions and data for handling this particular chip's
 * error decoding and logging.
 */
void mcerr_chip_specific_setup(struct mcerr_chip_specific *spec)
{
	spec->nr_clients = ARRAY_SIZE(mc_clients);
	spec->intr_descriptions = t210_intr_info;
	spec->clear_interrupt = clear_interrupt;
	spec->log_mcerr_fault = log_mcerr_fault;
	spec->nr_clients = ARRAY_SIZE(mc_clients);
	spec->intr_descriptions = t210_intr_info;
	return;
}
