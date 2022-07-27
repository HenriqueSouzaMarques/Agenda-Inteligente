#ifndef AGRUPAR_H
#define AGRUPAR_H

#include "contato.h"

void agruparRegistros(contato_t* agenda, int quantidadeRegistros);

int *vetorLideresGrupos(int quantidadeRegistros);

int grupoMenorDistancia(contato_t* const agenda, int* quantidadeGrupos, int registroAnalisado, int* lideresGrupos);

float distanciaEuclidiana(contato_t* const agenda, int posicaoLider, int registroAnalisado);

#endif