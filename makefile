
universalDoubleLinkeList: main.o udll.o
	gcc -Wall -o universalDoubleLinkeList main.o udll.o

main.o: main.c
	gcc -Wall -c main.c

udll.o: udll.c udll.h
	gcc -Wall -c udll.c