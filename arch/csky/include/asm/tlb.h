/* SPDX-License-Identifier: GPL-2.0-or-later */
#ifndef _ASM_CSKY_TLB_H_
#define _ASM_CSKY_TLB_H_

#include <asm/regs.h>

#ifdef CONFIG_CSKY_ABIV1

static inline void tlb_probe(void)
{
    cpwcr("cpcr8", MCIR_TLBP);
}

static inline void tlb_read(void)
{
    cpwcr("cpcr8", MCIR_TLBR);
}

static inline void tlb_inval_indexed(void)
{
	cpwcr("cpcr8", MCIR_TLBINVD);
}

static inline void tlb_inval_all(void)
{
    cpwcr("cpcr8", MCIR_TLBINVA);
}

#endif /* CONFIG_CSKY_ABIV1 */

void tlb_refresh(size_t addr);

static inline void tlb_inval_range(size_t addr, size_t size)
{
    tlb_inval_all();
}

#endif /* _ASM_CSKY_TLB_H_ */
