#ifndef ORDENACAO_H
#define ORDENACAO_H

#include "contato.h"

void ordenarRegistros(contato_t* agenda, int quantidadeRegistros);

void ordenarNome(contato_t* agenda, int quantidadeRegistros);

void ordenarData(contato_t* agenda, int quantidadeRegistros);

void ordenarGrupo(contato_t* agenda, int quantidadeRegistros);

void trocarRegistros(contato_t* registroA, contato_t* registroB);

int menuOrdenacao();

#endif