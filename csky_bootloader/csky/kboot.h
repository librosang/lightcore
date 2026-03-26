#ifndef _KBOOT_H_
#define _KBOOT_H_

#include <stdint.h>
#include <stddef.h>
#include <lib.h>
#include "linux_config.h"

extern char ld_bss_start[];
extern char ld_bss_end[];
#define bss_start   ((char *)ld_bss_start)
#define bss_end     ((char *)ld_bss_end)
#define bss_size    (bss_end - bss_start)

extern char ld_piggy_start[];
extern char ld_piggy_end[];
#define piggy_start ((char *)ld_piggy_start)
#define piggy_end   ((char *)ld_piggy_end)
#define piggy_size  (piggy_end - piggy_start)

extern char ld_heap_start[];
extern char ld_heap_end[];
#define heap_start  ((char *)ld_heap_start)
#define heap_end    ((char *)ld_heap_end)
#define heap_size   (heap_end - heap_start)

#define NORMAL_OFFSET  (CONFIG_RAM_BASE + CONFIG_RAM_PAD)
#define pa_to_va(pa) ((pa) - CONFIG_RAM_BASE + CONFIG_PAGE_OFFSET)
#define kernel_entry ((void*)pa_to_va(NORMAL_OFFSET))

struct boot_head {
    uint32_t dtb;
    uint32_t stdout;
};

void head(void);
void kernel_start(void *addr);
void halt(void);
void kernel_map(void);

#endif /* _KBOOT_H_ */
#define KMAGIC 0x5a5a5a5a
struct boot_head_full {
    char magic[16];
    uint32_t size;
    uint32_t crc;
    uint32_t dtb;
    uint32_t stdout;
};
