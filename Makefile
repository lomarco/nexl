INC := include/

CC           := clang
CLANG_TARGET := --target=x86_64-unknown-uefi
CFLAGS       := -ffreestanding -mno-red-zone -std=c23 -Wall -Wextra -Werror -pedantic \
                -I$(INC) -fno-pie -fshort-wchar -fno-builtin -fno-stack-protector -O2
LDFLAGS      := -fuse-ld=lld

include .config

KERNEL = nexl

ifeq ($(CONFIG_EFI_STUB), y)
	obj-y += drivers/efistub/main.c
endif

all: $(KERNEL)

kernel: $(KERNEL)

$(KERNEL): $(OBJS)
	$(CC) $(CLANG_TARGET) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CLANG_TARGET) $(CFLAGS) -c $< -o $@

.PHONY: all kernel
