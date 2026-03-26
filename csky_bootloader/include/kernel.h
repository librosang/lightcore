#ifndef _KERNEL_H_
#define _KERNEL_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#endif
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define MSIZE sizeof(uint32_t)
#define container_of(ptr, type, member) ({ \
    const typeof( ((type *)0)->member ) *__mptr = (ptr); \
    (type *)( (char *)__mptr - offsetof(type,member) );})
#define offsetof(TYPE, MEMBER) ((uint32_t) &((TYPE *)0)->MEMBER)
#define unlikely(x) (x)
#define BIT(nr) (1UL << (nr))
#define BIT_HIGH_MASK(nr) (~(BIT(nr) - 1))
#define align_high_adj(size, align) ((size) = ((size) + (align) - 1) & ~((align) - 1))
