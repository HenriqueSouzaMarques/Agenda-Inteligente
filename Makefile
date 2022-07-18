all: main

main: main.c funcoes.h funcoes.o
	gcc -o main main.c funcoes.o -lm

funcoes.o: funcoes.c funcoes.h
	gcc -c funcoes.c

clean:
	rm *.o