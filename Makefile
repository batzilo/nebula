# Makefile
CC=gcc
CFLAGS=-g -Wall -Werror -Wextra -std=c99 -O3 -lm

all : nebula

nebula : main.c
	$(CC) $(CFLAGS) -o $@ $^

.PHONY : clean

clean :
	$(RM) nebula
