#modify this makefile so that it will work for this new assignment
CC=g++

all: main.o
	$(CC) -std=c++11 main.o -o a.out

main: main.o 
	$(CC) -c -std=c++11 main.cpp

clean: 
	rm *.o *.out
