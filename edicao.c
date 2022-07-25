#include <stdio.h>
#include <string.h>

#include "Includes/edicao.h"
#include "Includes/contato.h"
#include "Includes/buscas.h"


void editarRegistro(contato_t* agenda, int quantidadeRegistros)
{
    int posicaoRegistro = buscarRegistro(agenda, quantidadeRegistros);

    if(posicaoRegistro == -1) return;

    int opcao = menuEdicao();

    switch (opcao)
    {
        case 1:
            editarNome(agenda, posicaoRegistro);
            break;

        case 2:
            editarCidade(agenda, posicaoRegistro);
            break;

        case 3:
            editarEstado(agenda, posicaoRegistro);
            break;

        case 4: 
            editarPreferencia(agenda, posicaoRegistro);
            break;

        case 5:
            editarData(agenda, posicaoRegistro);
            break;

        default:
            printf("Insira uma opção válida!\n");
            break;
    }
}

void editarNome(contato_t* agenda, int posicaoRegistro)
{
    char novoNome[TAMANHO_MAXIMO_NOME];
    printf("Insira o novo nome: ");
    scanf("%s", novoNome);

    strcpy(agenda[posicaoRegistro].nomeCompleto, novoNome);
}

void editarCidade(contato_t* agenda, int posicaoRegistro)
{
    char novaCidade[TAMANHO_MAXIMO_NOME];
    printf("Insira a nova cidade: ");
    scanf("%s", novaCidade);

    strcpy(agenda[posicaoRegistro].cidade, novaCidade);
}

void editarEstado(contato_t* agenda, int posicaoRegistro)
{
    char novaUF[TAMANHO_MAXIMO_NOME];
    printf("Insira a nova Unidade Federativa: ");
    scanf("%s", novaUF);

    strcpy(agenda[posicaoRegistro].cidade, novaUF);
}

void editarData(contato_t* agenda, int posicaoRegistro)
{
    int dia, mes, ano;

    printf("Insira a nova data: \n");
    
    printf("\t -- Dia: ");
    scanf("%d", &dia);

    printf("\t -- Mes: ");
    scanf("%d", &mes);

    printf("\t -- Ano: ");
    scanf("%d", &ano);

    agenda[posicaoRegistro].dataNascimento.dia = dia;
    agenda[posicaoRegistro].dataNascimento.mes = mes;
    agenda[posicaoRegistro].dataNascimento.ano = ano;
}


void editarPreferencia(contato_t* agenda, int posicaoRegistro)
{
    int opcao = menuPreferencia();

    switch (opcao)
    {
        case 1:
            editarFutebol(agenda, posicaoRegistro);
            break;
        
        case 2:
            editarBasquete(agenda, posicaoRegistro);
            break;

        case 3:
            editarVolei(agenda, posicaoRegistro);
            break;

        default:
            printf("Insira uma opção válida!\n");
            break;
    }
}

void editarFutebol(contato_t* agenda, int posicaoRegistro)
{
    float novaPreferencia;

    printf("Insira a nova preferência por futebol (0 a 10): \n");
    scanf("%f", &novaPreferencia);

    agenda[posicaoRegistro].esportes.futebol = novaPreferencia;
}

void editarBasquete(contato_t* agenda, int posicaoRegistro)
{
    float novaPreferencia;

    printf("Insira a nova preferência por basquete (0 a 10): \n");
    scanf("%f", &novaPreferencia);

    agenda[posicaoRegistro].esportes.basquete = novaPreferencia;

}

void editarVolei(contato_t* agenda, int posicaoRegistro)
{
    float novaPreferencia;

    printf("Insira a nova preferência por volei (0 a 10): \n");
    scanf("%f", &novaPreferencia);

    agenda[posicaoRegistro].esportes.volei = novaPreferencia;

}


int menuPreferencia()
{
    int opcao;
    printf("Insira o esporte a ser alterado: \n");
    printf("[1] Futebol\n");
    printf("[2] Basquete\n");
    printf("[3] Volei\n");

    scanf("%d", &opcao);
    return opcao;
}

int menuEdicao()
{
    int opcao;
    printf("Escolha o campo a ser editado:\n");

    printf("\t[1] Nome\n");
    printf("\t[2] Cidade\n");
    printf("\t[3] Unidade Federativa (sigla)\n");
    printf("\t[4] Preferências Esportivas\n");
    printf("\t[5] Data de Nascimento\n");

    scanf("%d", &opcao);

    return opcao;
}