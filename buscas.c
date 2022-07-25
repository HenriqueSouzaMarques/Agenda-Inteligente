#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Includes/buscas.h"

/* Busca um registro pelo seu: (i) Nome; (ii) Data de Nascimento ou (iii) Grupo */
int buscarRegistro(contato_t* const agenda, int quantidadeRegistros)
{
    int opcao = menuBusca();
    int posicaoRegistro;

    switch(opcao)
    {
        case 1:
            posicaoRegistro = buscarNome(agenda, quantidadeRegistros);
            break;

        case 2:
            posicaoRegistro = buscarData(agenda, quantidadeRegistros);
            break;
        
        case 3:
            posicaoRegistro = buscarGrupo(agenda, quantidadeRegistros);
            break;

        default:
            printf("Insira uma opção válida!\n");
            return -1;
    }

    return posicaoRegistro;
}

/* Caso o nome procurado seja substring de um dos contatos da lista, retorna sua posição */
int buscarNome(contato_t* const agenda, int quantidadeRegistros)
{
    char nomeProcurado[TAMANHO_MAXIMO_NOME];

    printf("Digitar o nome ou parte do nome:\n");
    scanf("%s", nomeProcurado);

    for(int i = 0; i < quantidadeRegistros; ++i)
    {
        if(strstr(agenda[i].nomeCompleto, nomeProcurado) != NULL)
        {
            return i;
        }
    }

    printf("Registro não encontrado!\n\n\n");
    return -1;
}

/* Caso a data de nascimento procurada coincida com a de algum registro, retornar a posição do registro */
int buscarData(contato_t* const agenda, int quantidadeRegistros)
{
    int dia, mes, ano;

    printf("Digite o dia: ");
    scanf("%d", &dia);

    printf("Digite o mês: ");
    scanf("%d", &mes);

    printf("Digite o ano: ");
    scanf("%d", &ano);

    for(int i = 0; i < quantidadeRegistros; ++i)
    {
        if(dia == agenda[i].dataNascimento.dia && mes == agenda[i].dataNascimento.mes && ano == agenda[i].dataNascimento.ano)
        {
            return i;
        }
    }

    printf("Registro não encontrado!\n\n\n");
    return -1;
}

int buscarGrupo(contato_t* const agenda, int quantidadeRegistros)
{
    return -1;
}

int menuBusca()
{
    int opcao;

    printf("Insira a opção de busca: \n");
    printf("\t[1] Nome\n");
    printf("\t[2] Data de Nascimento\n");
    printf("\t[3] Grupo\n");

    scanf("%d", &opcao);

    return opcao;
}
