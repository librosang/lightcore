/* SPDX-License-Identifier: GPL-2.0-or-later */
#ifndef _ASM_CSKY_PGTABLE_H_
#define _ASM_CSKY_PGTABLE_H_

#include <types.h>
#include <state.h>
#include <arch/csky/page.h>
#include <asm/page.h>

typedef struct pte pte_t;
typedef struct pgd pgd_t;

#define SSEG0_BASE  0x80000000
#define SSEG1_BASE  0xa0000000

#include <asm-generic/pgtable-nopmd.h>

static inline bool pmd_present(pmd_t *pmd)
{
    return !!pmd->pte;
}

static inline bool pte_none(pte_t *pte)
{
    return !pte->val;
}

static inline bool pmd_none(pmd_t *pmd)
{
    return !pmd_present(pmd);
}

static inline bool pmd_get_huge(pmd_t *pmd)
{
    return false;
}

static inline bool pmd_inval(pmd_t *pmd)
{
    return !pmd_present(pmd);
}

static inline void pmd_clear(pmd_t *pmd)
{
    pmd->pte = 0;
}

static inline void *pmd_address(pmd_t *pmd)
{
    return pa_to_va(pmd->pte);
}

static inline void pte_clear(pte_t *pte)
{
    pte->val = 0;
}

static inline void pmd_populate(pmd_t *pmd, pte_t *pte)
{
    pmd->pte = va_to_pa(pte);
}

#define pte_index(va) (((va) >> PAGE_SHIFT) & (PTRS_PER_PTE - 1))
#define pde_index(va) ((va) >> PGDIR_SHIFT)

extern pgd_t page_dir[];

state arch_page_map(size_t pa, size_t va, size_t size);
void arch_page_setup(void);

#endif /* _ASM_CSKY_PGTABLE_H_ */
