CC     = clang
LD     = lld
CFLAGS = -fno-pic -ffreestanding -mno-red-zone \
				 -std=c23 -Wall -Werror -pedantic -I.

SUBSYSTEMS += drivers/
SUBSYSTEMS += init/
SUBSYSTEMS += kernel/

include $(patsubst %,%/Makefile,$(SUBSYSTEMS))

INC = include/

OBJS := $(foreach d,$(obj-y),$($(d)_obj-y))

all: kernel

kernel: $(OBJS)
	$(CC) -o $@ $^ -I $(INC) $(LDFAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all kernel
