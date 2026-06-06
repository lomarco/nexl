SUBSYSTEMS += drivers/
SUBSYSTEMS += init/
SUBSYSTEMS += kernel/

include $(patsubst %,%/Makefile,$(SUBSYSTEMS))

INC = include/

OBJS := $(foreach d,$(obj-y),$($(d)_obj-y))

CC           = clang
CLANG_TARGET = --target=x86_64-pc-windows-msvc
CFLAGS       = -ffreestanding -mno-red-zone -std=c23 -Wall -Wextra -Werror -pedantic \
							 -I. -fno-pie -fshort-wchar -fno-builtin -fno-stack-protector -O2
LD           = lld
LDFLAGS      = -Wl,-flavor,link -Wl,-subsystem:efi_application -Wl,-entry:efi_main

all: kernel

kernel: $(OBJS)
	$(CC) $(CLANG_TARGET) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CLANG_TARGET) $(CFLAGS) -c $< -o $@

.PHONY: all kernel
