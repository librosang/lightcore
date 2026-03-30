/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright(c) 2021 John Sanpe <sanpeqf@gmail.com>
 */

#include <linkage.h>

    .section .startup,"ax"
GLOBAL(_start)
    lrw     r1, _ld_stack_end
    mov     sp, r1

    bsr     main
    br      halt
END(_start)

GLOBAL(kernel_start)
    mov     r4, a0
    mov     a0, a1
    mov     a1, a2
    mov     a2, a3
    jmp     r4
END(kernel_start)

GLOBAL(halt)
    stop
    br      halt
END(halt)
