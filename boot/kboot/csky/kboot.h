/* SPDX-License-Identifier: GPL-2.0-or-later */
#ifndef _KBOOT_H_
#define _KBOOT_H_

#ifndef __ASSEMBLY__
#include <memory.h>
#include <lib.h>

extern void *_ld_piggy_start[];
extern void *_ld_piggy_end[];
extern void *_ld_heap_start[];
extern void *_ld_heap_end[];
extern void *_ld_dtb_start[];
extern void *_ld_dtb_end[];

#define bss_start   ((void *)_ld_bss_start)
#define bss_end     ((void *)_ld_bss_end)
#define bss_size    ((uintptr_t)bss_end - (uintptr_t)bss_start)

#define piggy_start ((void *)_ld_piggy_start)
#define piggy_end   ((void *)_ld_piggy_end)
#define piggy_size  ((uintptr_t)piggy_end - (uintptr_t)piggy_start)

#define dtb_start   ((void *)_ld_dtb_start)
#define dtb_end     ((void *)_ld_dtb_end)
#define dtb_size    ((uintptr_t)dtb_end - (uintptr_t)dtb_start)

#define heap_start  ((void *)_ld_heap_start)
#define heap_end    ((void *)_ld_heap_end)
#define heap_size   ((uintptr_t)heap_end - (uintptr_t)heap_start)

#define kernel_entry ((void *)pa_to_va(NORMAL_OFFSET))

/* startup.S */
void head(void);
void kernel_start(void *entry, int a0, int a1, int a2);
void halt(void);

/* page.c */
void kernel_map(void);

#endif /* __ASSEMBLY__ */

#endif /* _KBOOT_H_ */
