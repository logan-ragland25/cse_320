decoder: main.o LinkedList.o
	gcc -o decoder main.o LinkedList.o

main.o: main.c
	gcc -c -Wall main.c

LinkedList.o: LinkedList.c LinkedList.h
	gcc -c -Wall LinkedList.c