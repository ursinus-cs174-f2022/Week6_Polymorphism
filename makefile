CC=g++
CFLAGS=-std=c++11 -g -Wall 

all: driver_arr driver_list

person.o: person.cpp person.h
	$(CC) $(CFLAGS) -c person.cpp

driver_arr: driver_arr.cpp person.o
	$(CC) $(CFLAGS) -o driver_arr person.o driver_arr.cpp

driver_list: driver_list.cpp person.o
	$(CC) $(CFLAGS) -o driver_list person.o driver_list.cpp

clean:
	rm *.o driver_list driver_arr