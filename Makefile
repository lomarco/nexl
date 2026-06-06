CC     = clang
LD     = lld
CFLAGS = -fno-pic -ffreestanding -mno-red-zone \
				 -std=c23 -Wall -Werror -pedantic -I.

subdirs += drivers/
subdirs += init/
subdirs += kernel/

include $(patsubst %,%/Makefile,$(subdirs))

OBJS := $(foreach d,$(obj-y),$($(d)_obj-y))

all: kernel

kernel: $(OBJS)
	$(CC) -o $@ $^ $(LDFAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all
