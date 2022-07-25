#ifndef UTILS_H
#define UTILS_H

#include "contato.h"

int menu();

contato_t* lerRegistros(int* quantidadeRegistros);

int calcularQuantidadeRegistros(FILE* arquivoEntrada);

void cadastrarRegistro(contato_t** agenda, int* quantidadeRegistros);

contato_t lerNovoRegistro();

void editarRegistro(contato_t* agenda, int quantidadeRegistros);

void excluirRegistro(contato_t* agenda, int quantidadeRegistros);

void ordenarRegistros(contato_t* agenda, int quantidadeRegistros);
    /* Por nome */
    /* Por data */
    /* Por grupo */

void printarRegistro(contato_t* agenda, int posicaoRegistro);

void agruparRegistros(contato_t* agenda, int quantidadeRegistros);

void exportarRegistros(contato_t* agenda, int quantidadeRegistros); 


#endif