CC=g++
CFLAGS=-std=c++11 -g -Wall 

all: driver

person.o: person.cpp person.h
	$(CC) $(CFLAGS) -c person.cpp

driver: driver.cpp person.o
	$(CC) $(CFLAGS) -o driver person.o driver.cpp

clean:
	rm *.o driver