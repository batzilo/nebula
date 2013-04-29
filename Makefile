all : nebula

CC = gcc
CFLAGS = -O3 -g -Wall -Werror -std=c99 -Wextra

nebula : main.o
	$(CC) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $^

.PHONY : clean distclean

clean :
	$(RM) *.o

distclean : clean
	$(RM) nebula
