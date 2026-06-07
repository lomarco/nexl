KERNEL = nexl

INC := include/

CC           := clang
CLANG_TARGET := --target=x86_64-unknown-uefi
CFLAGS       := -ffreestanding -mno-red-zone -std=c23 -Wall -Wextra -Werror -pedantic \
                -I$(INC) -fno-pie -fshort-wchar -fno-builtin -fno-stack-protector -O2
LDFLAGS      := -fuse-ld=lld

include .config

obj-$(CONFIG_EFI_STUB) += init/init.c
obj-$(CONFIG_EFI_STUB) += drivers/efistub/main.c

all: $(KERNEL)

kernel: $(KERNEL)

$(KERNEL): $(obj-y)
	$(CC) $(CLANG_TARGET) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CLANG_TARGET) $(CFLAGS) -c $< -o $@

print-objs:
	@printf '%s\n' $(obj-y)

.PHONY: all kernel print-objs
