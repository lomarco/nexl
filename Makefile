CC     = clang
LD     = lld
CFLAGS = -fno-pic -ffreestanding -mno-red-zone \
				 -std=c23 -Wall -Werror -pedantic -I$(SRC)

SRC  = $(abspath src)
SRCS = $(wildcard $(SRC)/*.c)

SRC  = $(abspath src)
SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c,%.o,$(SRCS))

all: $(OBJS)

%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all
