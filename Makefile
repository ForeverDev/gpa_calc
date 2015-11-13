CC = g++
CF = -Wall -c

all: gpa

gpa: main.o
	$(CC) main.o -o gpa
	sudo mv gpa /usr/bin
	rm -Rf *.o

main.o: main.cpp
	$(CC) $(CF) main.cpp -o main.o
