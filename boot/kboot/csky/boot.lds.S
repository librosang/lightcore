/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright(c) 2021 John Sanpe <sanpeqf@gmail.com>
 */

#include <size.h>
#include <kboot.h>
#include <asm-generic/kernel.lds.h>

OUTPUT_ARCH(csky)
ENTRY(_start)

#define STACK_SIZE      (SZ_1KiB * 16)
#define HEAP_SIZE       (SZ_1KiB * 64)

#ifndef CONFIG_PAGE_OFFSET
#define CONFIG_PAGE_OFFSET 0x80000000
#endif

SECTIONS {
    . = CONFIG_LOAD_ADDR;
    _ld_header_start = .;

    .startup : {
        KEEP(*(.startup))
        KEEP(*(.startup.*))
    }

    .text : {
        *(.text)
        *(.text.*)
    }

    .rodata : {
        *(.rodata)
        *(.rodata.*)
    }

    .data : {
        *(.data)
        *(.data.*)
    }

    . = ALIGN(512);
    _ld_header_end = .;

    .piggydata : {
        _ld_piggy_start = .;
        KEEP(*(.piggydata))
        _ld_piggy_end = .;
    }

    .dtbdata : {
        _ld_dtb_start = .;
        KEEP(*(.dtbdata))
        _ld_dtb_end = .;
    }

    . = ALIGN(512);
    _ld_header_end = .;

    .bss (NOLOAD) : {
        . = ALIGN(4);
        _ld_bss_start = .;
        *(.bss)
        *(.bss.*)
        *(COMMON)
        . = ALIGN(4);
        _ld_bss_end = .;
    }

    .heap (NOLOAD) : {
        . = ALIGN(4);
        _ld_heap_start = .;
        . = _ld_heap_start + HEAP_SIZE;
        _ld_heap_end = .;
    }

    .stack (NOLOAD) : {
        . = ALIGN(4);
        _ld_stack_start = .;
        . = _ld_stack_start + STACK_SIZE;
        _ld_stack_end = .;
    }

    DISCARDS
}

PROVIDE(_ld_header_size = _ld_header_end - _ld_header_start);
