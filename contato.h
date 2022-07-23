#ifndef CONTATO_H
#define CONTATO_H

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAXIMO_NOME 100

#define NOME_ARQUIVO "dados.dat"

#define BOOL char
#define TRUE 1
#define FALSE 0

typedef struct data_t_
{
    int dia;
    int mes;
    int ano;
} data_t;

typedef struct preferencias_t_
{
    float futebol;
    float basquete;
    float volei;
} preferencias_t;


typedef struct contato_t_
{
    char nomeCompleto[TAMANHO_MAXIMO_NOME];
    char cidade[TAMANHO_MAXIMO_NOME];
    char UF[2];
    preferencias_t esportes;
    data_t dataNascimento;
    int grupo;
    BOOL excluido;
} contato_t;

#endif