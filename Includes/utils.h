#ifndef UTILS_H
#define UTILS_H

#include "contato.h"

int menu();

contato_t* lerRegistros(int* quantidadeRegistros);

int calcularQuantidadeRegistros(FILE* arquivoEntrada);

void cadastrarRegistro(contato_t** agenda, int* quantidadeRegistros);

contato_t lerNovoRegistro();

void excluirRegistro(contato_t* agenda, int quantidadeRegistros);

void agruparRegistros(contato_t* agenda, int quantidadeRegistros);

void printarRegistro(contato_t* agenda, int posicaoRegistro);

void printarTodosRegistros(contato_t* agenda, int quantidadeRegistros);

void exportarRegistros(contato_t* agenda, int quantidadeRegistros); 


#endif