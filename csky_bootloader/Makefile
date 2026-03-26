CC = csky-elf-gcc
LD = csky-elf-ld
OBJCOPY = csky-elf-objcopy

INCLUDE = -I./include -I./csky -I./lib -I./boot/include

CFLAGS = -mcpu=ck610 -g -Os -Wall $(INCLUDE) \
         -ffreestanding -nostdinc -fno-stack-protector -fno-common \
         -ffunction-sections -fdata-sections -D__ASSEMBLY__=0

ASFLAGS = -mcpu=ck610 -D__ASSEMBLY__ $(INCLUDE)

LDFLAGS = -T boot.lds -nostdlib --gc-sections

OBJS = csky/head.o csky/main.o csky/page.o \
       lib/string.o lib/check.o lib/memtest.o \
       lib/mem.o lib/info.o lib/vsprintf.o lib/decompress.o

all: boot.bin

boot.elf: $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS)

boot.bin: boot.elf
	$(OBJCOPY) -O binary $< $@

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.S
	$(CC) $(ASFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) boot.elf boot.bin
