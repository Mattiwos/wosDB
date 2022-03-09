CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpedantic

SOURCE = include/$(wildcard *.c)
OBJECT = $(wildcard *.o)
FILE = /home/wos/Repos/github.com/mattiwos/wosDB/.clang-format
INCLUDE = include/*

all: wosDB 

wosDB: 
	$(CC) $(CFLAGS) wosDB.c -o wosDB

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJECT) wosDB 

scan-build: clean
	scan-build make

format:
	clang-format -i -style=FILE *.c include/*.h
