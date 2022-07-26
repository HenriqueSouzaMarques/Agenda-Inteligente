#include <stdio.h>
#include <string.h>

#include "Includes/contato.h"
#include "Includes/ordenacao.h"

void ordenarRegistros(contato_t* agenda, int quantidadeRegistros)
{
    int opcao = menuOrdenacao();

    switch (opcao)
    {
        case 1:
            ordenarNome(agenda, quantidadeRegistros);
            break;
        
        case 2:
            ordenarData(agenda, quantidadeRegistros);   
            break;

        case 3:
            ordenarGrupo(agenda, quantidadeRegistros);
            break;

        default:
            printf("Insira uma opção válida!\n\n\n");
            break;
    }
}

void ordenarNome(contato_t* agenda, int quantidadeRegistros)
{
    int indexLetraDiferente;

    /* Aplicando Bubble Sort, critério: nome completo */
    for(int i = 0; i < quantidadeRegistros; ++i)
    {
        for(int j = 0; j < quantidadeRegistros - 1 - i; ++j)
        {
            indexLetraDiferente = 0;

            if(strcmp(agenda[j].nomeCompleto, agenda[j + 1].nomeCompleto) != 0)
            {
                /* While loop para encontrar a primeira letra diferente */
                while(agenda[j].nomeCompleto[indexLetraDiferente] == agenda[j + 1].nomeCompleto[indexLetraDiferente])
                {
                    indexLetraDiferente++;
                }
            }       

            /* Se a primeira letra que difere do registro "j" for menor 
             * que do registro "j + 1" (tabela ASCII), trocar registros */
            if(agenda[j].nomeCompleto[indexLetraDiferente] > agenda[j + 1].nomeCompleto[indexLetraDiferente])
            {
                trocarRegistros(&agenda[j], &agenda[j + 1]);
            }
        }
    }
}

void ordenarData(contato_t* agenda, int quantidadeRegistros)
{
    /* Aplicando Bubble Sort, critério: data de nascimento */
    for(int i = 0; i < quantidadeRegistros; ++i)
    {
        for(int j = 0; j < quantidadeRegistros - 1 - i; ++j)
        {
            /* Se o ano do registro "j" for maior que do "j + 1", trocar registros */
            if(agenda[j].dataNascimento.ano > agenda[j + 1].dataNascimento.ano)
            {
                trocarRegistros(&agenda[j], &agenda[j + 1]);
            }
            /* Se os anos forem iguais, comparamos os meses */
            else if(agenda[j].dataNascimento.ano == agenda[j + 1].dataNascimento.ano)
            {
                /* Se o mês do registro "j" for maior que do "j + 1", trocar registros */
                if(agenda[j].dataNascimento.mes > agenda[j + 1].dataNascimento.mes)
                {
                    trocarRegistros(&agenda[j], &agenda[j + 1]);
                }
                /* Se os meses forem iguais, comparar os dias */
                else if(agenda[j].dataNascimento.mes == agenda[j + 1].dataNascimento.mes)
                {
                    /* Se o dia do registro "j" for maior que do "j + 1", trocar registros */
                    if(agenda[j].dataNascimento.dia > agenda[j + 1].dataNascimento.dia)
                    {
                        trocarRegistros(&agenda[j], &agenda[j + 1]);
                    }
                }
            }
        }
    }
}

void ordenarGrupo(contato_t* agenda, int quantidadeRegistros)
{
    /* Aplicando Bubble Sort, critério: grupo */
    for(int i = 0; i < quantidadeRegistros; ++i)
    {
        for(int j = 0; j < quantidadeRegistros - 1 - i; ++j)
        {
            if(agenda[j].grupo > agenda[j + 1].grupo)
            {
                trocarRegistros(&agenda[j], &agenda[j + 1]);
            }
        }
    }
}

void trocarRegistros(contato_t* registroA, contato_t* registroB)
{
    contato_t aux;

    aux = *registroA;
    *registroA = *registroB;
    *registroB = aux;
}

int menuOrdenacao()
{
    int opcao;

    printf("Insira o critério de escolha para a ordenação: \n");
    printf("[1] Nome\n");
    printf("[2] Data de Nascimento\n");
    printf("[3] Grupo\n");

    scanf("%d", &opcao);

    return opcao;
}