CC = g++
CFLAGS = -Wall -w

all: part-1 part-2

part-1: part-1.cc
	$(CC) $(CFLAGS) -o part-1 part-1.cc


part-2: part-2.cc
	$(CC) $(CFLAGS) -o part-2 part-2.cc

run: all
	make part-1
	make part-2
	./part-1
	./part-2
	make clean

clean: 
	rm -rf *.o part-1 part-2

