main: main.o list.o
	gcc -o main list.o main.o -Wall -Wextra
list.o: list.c list.h
	gcc -c list.c -Wall -Wextra
main.o: main.c main.h
	gcc -c main.c -Wall -Wextra

