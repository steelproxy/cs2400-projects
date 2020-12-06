CC=g++
CFLAGS=-Wall -std=c++11

a.out: main.o my_int.o
	$(CC) $(CFLAGS) main.o my_int.o

main.o: main.cc my_int.h
	$(CC) $(CFLAGS) -c main.cc

my_int.o: my_int.cc my_int.h
	$(CC) $(CFLAGS) -c my_int.cc

clean:
	rm a.out main.o my_int.o