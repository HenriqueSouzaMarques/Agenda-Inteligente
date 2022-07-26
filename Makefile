all: agendaInteligente

agendaInteligente: main.c Includes/utils.h utils.o Includes/buscas.h buscas.o Includes/edicao.h edicao.o Includes/ordenacao.h ordenacao.o Includes/contato.h
	gcc -g -o agendaInteligente main.c utils.o buscas.o edicao.o ordenacao.o -lm

utils.o: utils.c Includes/utils.h Includes/contato.h
	gcc -c utils.c

buscas.o: buscas.c Includes/buscas.h
	gcc -c buscas.c

edicao.o: edicao.c Includes/edicao.h buscas.o Includes/contato.h
	gcc -c edicao.c

ordenacao.o: ordenacao.c Includes/ordenacao.h Includes/contato.h
	gcc -c ordenacao.c

clean:
	rm *.o & rm agendaInteligente
