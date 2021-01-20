#Make file
SHELL = /bin/sh

CC=gcc #compiler
TARGET=main #target file name
CFLAGS=-g -Wall
INCLUDE=include/create.h
all: 
	$(CC) $(CFLAGS) $(INCLUDE) main.c -o $(TARGET)

clean:
	-rm -f *.o core *.core
