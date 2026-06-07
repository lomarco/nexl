include .config

KERNEL = bootx64.efi

include drivers/Makefile
include init/Makefile
include kernel/Makefile

INC = $(CURDIR)/include/

CC           = clang
CLANG_TARGET = --target=x86_64-unknown-uefi
CFLAGS       = -ffreestanding -mno-red-zone -std=c23 -Wall -Wextra -Werror -pedantic \
							 -I$(INC) -fno-pie -fshort-wchar -fno-builtin -fno-stack-protector -O2
LDFLAGS      = -fuse-ld=lld

all: $(KERNEL)

kernel: $(KERNEL)

$(KERNEL): $(OBJS)
	$(CC) $(CLANG_TARGET) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CLANG_TARGET) $(CFLAGS) -c $< -o $@

.PHONY: all kernel
