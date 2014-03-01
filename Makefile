# Makefile

CC=/usr/bin/c99
#CC=gcc
CFLAGS=-g -Wall -Werror -Wextra -std=c99 -O3 -lm

everything=nebula

all : $(everything)

% : %.c
	$(CC) $(CFLAGS) -o $@ $^

.PHONY : clean

clean :
	$(RM) $(everything)
