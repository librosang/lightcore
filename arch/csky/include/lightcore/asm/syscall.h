/* SPDX-License-Identifier: GPL-2.0-or-later */
#ifndef _LIGHTCORE_ASM_CSKY_SYSCALL_H_
#define _LIGHTCORE_ASM_CSKY_SYSCALL_H_

static inline long
syscall(unsigned int callnr, long arg1, long arg2,
        long arg3, long arg4, long arg5, long arg6)
{
    long retval;
    
    asm volatile (
        "mov    r1, %1\n"
        "mov    a0, %2\n"
        "mov    a1, %3\n"
        "mov    a2, %4\n"
        "mov    a3, %5\n"
        "mov    a4, %6\n"
        "mov    a5, %7\n"
        "trap   0\n"
        "mov    %0, a0\n"
        : "=r"(retval)
        : "r"(callnr), "r"(arg1), "r"(arg2), "r"(arg3), "r"(arg4), "r"(arg5), "r"(arg6)
        : "r1", "a0", "a1", "a2", "a3", "a4", "a5", "memory"
    );

    return retval;
}

#endif /* _LIGHTCORE_ASM_CSKY_SYSCALL_H_ */
