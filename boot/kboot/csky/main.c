/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright(c) 2021 John Sanpe <sanpeqf@gmail.com>
 */

#include <linkage.h>
#include <kernel.h>
#include <kboot.h>

asmlinkage void main(uint32_t mask, uint32_t dtb_start_arg, void *printf)
{
    void *input = piggy_start;
    size_t input_size = piggy_size;

    memset(bss_start, 0, bss_size);

    if (mask == KMAGIC)
        pr_init(printf);

    heap_setup(heap_start, heap_size);

    kernel_map();

#ifdef CONFIG_KBOOT_LINUX
    /* Skip uImage header (64 bytes) */
    input += 64;
    input_size -= 64;
    extract_kernel(kernel_entry, input, input_size);

    pr_boot("boot to linux kernel...\n");
    /* Linux on csky: a0=0, a1=0, a2=dtb_phys */
    kernel_start(kernel_entry, 0, 0, va_to_pa(dtb_start));
#else
    struct boot_head *head;
    extract_kernel(kernel_entry, piggy_start, piggy_size);

    head = kernel_entry;
    head->dtb = dtb_start_arg ? CONFIG_PAGE_OFFSET + dtb_start_arg : 0;
    head->stdout = (size_t)stdout;

    pr_boot("boot to kernel...\n");
    kernel_start(kernel_entry, (int)kernel_entry, 0, 0);
#endif
}
