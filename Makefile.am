#   #

CC=gcc
CFLAGS=-g -Wall
LIBS=-lm
EXTRA_DIST = myheader.h main.c parse.c execute.c my_cd.c

all: assignment2

assignment2: main.o parse.o execute.o my_cd.o
	$(CC) $(LIBS) main.o parse.o execute.o my_cd.o -o assignment2

main.o: main.c
	$(CC) -c $(CFLAGS) main.c

parse.o: parse.c
	$(CC) -c $(CFLAGS) parse.c

execute.o: execute.c
	$(CC) -c $(CFLAGS) execute.c

my_cd.o: my_cd.c
	$(CC) -c $(CFLAGS) my_cd.c

clean:
	rm -rf *.o assignment2
