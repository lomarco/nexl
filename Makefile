CC     = clang
LD     = lld
CFLAGS = -fno-pic -ffreestanding -mno-red-zone \
				 -std=c23 -Wall -Werror -pedantic -I.

subdirs += drivers/
subdirs += init/
subdirs += kernel/

all: $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all
