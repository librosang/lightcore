/* SPDX-License-Identifier: GPL-2.0-or-later */
#ifndef _ASM_CSKY_STACKPROTECTOR_H_
#define _ASM_CSKY_STACKPROTECTOR_H_

#include <sched.h>
#include <prandom.h>
#include <ktime.h>
#include <asm-generic/stackprotector.h>

#ifdef CONFIG_STACKPROTECTOR

extern unsigned long __stack_chk_guard;

static __always_inline void stack_canary_switch(struct sched_task *task)
{
    __stack_chk_guard = task->stack_canary;
}

#define boot_stack_canary boot_stack_canary
static __always_inline void boot_stack_canary(void)
{
    unsigned long canary;

    prandom_bytes(&canary, sizeof(canary));
    canary ^= (unsigned long)ktime_get();
    canary &= CANARY_MASK;

    current->stack_canary = canary;
    __stack_chk_guard = canary;
}

#else

static inline void stack_canary_switch(struct sched_task *task) {}
static inline void boot_stack_canary(void) {}

#endif /* CONFIG_STACKPROTECTOR */
#endif /* _ASM_CSKY_STACKPROTECTOR_H_ */
