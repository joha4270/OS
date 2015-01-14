CC=gcc
CFLAGS=-I.

DEPS= rawio.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 



sfstestmake: test.o rawio.o
	$(CC) -o sfstest.exe test.o rawio.o -I.
