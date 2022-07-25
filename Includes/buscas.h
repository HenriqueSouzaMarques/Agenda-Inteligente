#ifndef BUSCAS_H
#define BUSCAS_H


#include "contato.h"

/* Retorna posição do registro de interesse */
int buscarRegistro(contato_t* const agenda, int quantidadeRegistros);
    /* Por nome */
    int buscarNome(contato_t* const agenda, int quantidadeRegistros);
    /* Por data de nascimento */
    int buscarData(contato_t* const agenda, int quantidadeRegistros);
    /* Por grupo */
    int buscarGrupo(contato_t* const agenda, int quantidadeRegistros);

int menuBusca();

#endif