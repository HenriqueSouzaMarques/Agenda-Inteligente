#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcoes.h"

int menu()
{
    int opt;

    printf("1) Importa Registros de um Arquivo\n");
    printf("2) Cadastra novo Registro\n");
    printf("3) Editar Registro\n");
    printf("4) Excluir Registro\n");
    printf("5) Buscar Registro\n");
    printf("6) Ordenar Registro");
    printf("7) Agrupar Registro\n");
    printf("8) Exportar Registros para um arquivo de saída\n");
    printf("0) ")
    scanf("%d", &opt);

    return opt; 
}