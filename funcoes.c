#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcoes.h"

int menu()
{
    int opcao;

    printf("1) Importa Registros de um Arquivo\n");
    printf("2) Cadastra novo Registro\n");
    printf("3) Editar Registro\n");
    printf("4) Excluir Registro\n");
    printf("5) Buscar Registro\n");
    printf("6) Ordenar Registro\n");
    printf("7) Agrupar Registro\n");
    printf("8) Exportar Registros para um arquivo de saída\n");
    printf("0) Sair\n");
    printf("----------------------------\n\n\n");

    scanf("%d", &opcao);

    return opcao; 
}

contato_t* lerRegistros(int* quantidadeRegistros)
{
    return;
}

int calcularQuantidadeRegistros(FILE* arquivoEntrada)
{
    return;
}

void cadastrarRegistro(contato_t** agenda, int* quantidadeRegistros)
{
    return;
}

int buscarRegistro(contato_t* const agenda, int quantidadeRegistros)
{
    return;
}

void editarRegistro(contato_t* agenda, int quantidadeRegistros)
{
    return;
}

void excluirRegistro(contato_t* agenda, int quantidadeRegistros)
{
    return;
}

void ordenarRegistros(contato_t* agenda, int quantidadeRegistros)
{
    return;
}

void agruparRegistros(contato_t* agenda, int quantidadeRegistros)
{
    return;
}


void exportarRegistros(contato_t* agenda, int quantidadeRegistros)
{
    return;
}