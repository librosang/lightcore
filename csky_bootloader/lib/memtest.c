/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright(c) 2021 John Sanpe <sanpeqf@gmail.com>
 */

#include <lib.h>
#include <kernel.h>

static uint32_t patterns[] = {
    (uint32_t)0x0000000000000000ULL,
    (uint32_t)0xffffffffffffffffULL,
    (uint32_t)0x5555555555555555ULL,
    (uint32_t)0xaaaaaaaaaaaaaaaaULL,
    (uint32_t)0x1111111111111111ULL,
    (uint32_t)0x2222222222222222ULL,
    (uint32_t)0x4444444444444444ULL,
    (uint32_t)0x8888888888888888ULL,
    (uint32_t)0x3333333333333333ULL,
    (uint32_t)0x7777777777777777ULL,
    (uint32_t)0xccccccccccccccccULL,
    (uint32_t)0xeeeeeeeeeeeeeeeeULL,
};

static int pattern_test(uint32_t *addr, uint32_t size, uint32_t pattern)
{
    uint32_t *tmp, *end = addr + (size / MSIZE);

    for (tmp = addr; tmp < end; tmp++)
        *tmp = pattern;
    for (tmp = addr; tmp < end; tmp++)
        if (*tmp != pattern)
            return -1;
    return 0;
}

int memtest_fast(uint32_t *addr, uint32_t size)
{
    unsigned char i;

    pr_boot("memtest: size 0x%x @ 0x%x\n", size, addr);

    for (i = 0; i < 2; i++)
        if (pattern_test(addr, size, patterns[i]))
            return -1;

    return 0;
}

int memtest(uint32_t *addr, uint32_t size)
{
    unsigned char i;

    pr_boot("memtest: size 0x%x @ 0x%x\n", size, addr);

    for (i = 0; i < ARRAY_SIZE(patterns); i++)
        if (pattern_test(addr, size, patterns[i]))
            return -1;

    return 0;
}
