all: main

main: main.c utils.h utils.o buscas.h buscas.o contato.h
	gcc -g -o main main.c utils.o buscas.o -lm

utils.o: utils.c utils.h contato.h
	gcc -c utils.c

buscas.o: buscas.c buscas.h
	gcc -c buscas.c

clean:
	rm *.o
