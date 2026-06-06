CC     = clang
LD     = lld
CFLAGS = -fno-pic -ffreestanding -mno-red-zone \
				 -std=c23 -Wall -Werror -pedantic -I.

subdirs += drivers/
subdirs += init/
subdirs += kernel/

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SRCS))

all: $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all
