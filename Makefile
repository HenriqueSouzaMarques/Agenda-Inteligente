all: main

main: main.c Includes/utils.h utils.o Includes/buscas.h buscas.o Includes/edicao.h edicao.o Includes/contato.h
	gcc -g -o main main.c utils.o buscas.o edicao.o -lm

utils.o: utils.c Includes/utils.h Includes/contato.h
	gcc -c utils.c

buscas.o: buscas.c Includes/buscas.h
	gcc -c buscas.c

edicao.o: edicao.c Includes/edicao.h buscas.o Includes/contato.h
	gcc -c edicao.c

clean:
	rm *.o
