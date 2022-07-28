#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Includes/agrupar.h"
#include "Includes/contato.h"

#define LIMIAR 2

void agruparRegistros(contato_t* agenda, int quantidadeRegistros){
    /* Vetor onde o grupo = index contem a posicao do lider no vetor de struct agenda */
    int* lideresGrupos = vetorLideresGrupos(quantidadeRegistros);
    int quantidadeGrupos = 0;
    
    /* Percorrendo todos os contatos e os inserindo em um grupo ou criando um grupo novo */
    for(int i = 0; i < quantidadeRegistros; ++i)
        agenda[i].grupo = (grupoMenorDistancia(agenda, &quantidadeGrupos, i, lideresGrupos) + 1);

    free(lideresGrupos);
}

int *vetorLideresGrupos(int quantidadeRegistros){
    int *lideresGrupos = (int *) malloc(quantidadeRegistros * sizeof(int));
    if(lideresGrupos == NULL){
        printf("Nao foi possivel ordenar por grupos :(");
        exit(1);
    }
    for(int i = 0; i < quantidadeRegistros; ++i)
        lideresGrupos[i] = -1;

    return lideresGrupos;
}

int grupoMenorDistancia(contato_t* const agenda, int* quantidadeGrupos, int registroAnalisado, int* lideresGrupos){
    float menorDistanciaEuclidiana = LIMIAR;
    float distanciaEuclidianaAtual;
    int grupoMenorDistancia = -1;

    /* Calculando o grupo com a menor distancia */
    for(int i = 0; i < *quantidadeGrupos; ++i){
        distanciaEuclidianaAtual = distanciaEuclidiana(agenda, lideresGrupos[i], registroAnalisado);
        if(distanciaEuclidianaAtual < menorDistanciaEuclidiana){
            menorDistanciaEuclidiana = distanciaEuclidianaAtual;
            grupoMenorDistancia = i;
        }
    }

    /* Criando um grupo caso a menor distancia euclidiana seja maior que o LIMIAR */
    if(menorDistanciaEuclidiana >= LIMIAR){
        lideresGrupos[*quantidadeGrupos] = registroAnalisado;
        grupoMenorDistancia = *quantidadeGrupos;
        *quantidadeGrupos = *quantidadeGrupos + 1;
    }

    return grupoMenorDistancia;
}

float distanciaEuclidiana(contato_t* const agenda, int posicaoLider, int registroAnalisado){
    float distanciaEuclidiana = 0;
    distanciaEuclidiana += pow(agenda[posicaoLider].esportes.futebol - agenda[registroAnalisado].esportes.futebol,2); 
    distanciaEuclidiana += pow(agenda[posicaoLider].esportes.basquete - agenda[registroAnalisado].esportes.basquete,2); 
    distanciaEuclidiana += pow(agenda[posicaoLider].esportes.volei - agenda[registroAnalisado].esportes.volei,2); 
    distanciaEuclidiana = sqrt(distanciaEuclidiana);

    return distanciaEuclidiana;
}