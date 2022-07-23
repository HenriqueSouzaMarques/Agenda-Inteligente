#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "contato.h"
#include "buscas.h"

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

/* Lê registros gravados no arquivo binário "dados.dat" */
/* Retorna um vetor na heap com todos os registros lidos */
contato_t* lerRegistros(int* quantidadeRegistros)
{
    FILE* arquivoEntrada = fopen(NOME_ARQUIVO, "rb");

    if(arquivoEntrada == NULL)
    {
        printf("Erro ao abrir arquivo para leitura de dados!\n");
        return NULL;
    }

    *quantidadeRegistros = calcularQuantidadeRegistros(arquivoEntrada);

    contato_t* listaContatos = (contato_t*)malloc((*quantidadeRegistros) * sizeof(contato_t));

    if(listaContatos == NULL)
    {
        printf("Erro ao alocar memória para os contatos!\n");
        fclose(arquivoEntrada);
        return NULL;
    }

    int nLidos = fread(listaContatos, sizeof(contato_t), *quantidadeRegistros, arquivoEntrada);

    if(nLidos != *quantidadeRegistros)
    {
        printf("Erro na leitura do arquivo de dados!\n");
        fclose(arquivoEntrada);
        free(listaContatos);
        return NULL;
    }

    fclose(arquivoEntrada);

    return listaContatos;
}

/* Retorna a quantidade de registros em um arquivo a partir do seu tamanho */
int calcularQuantidadeRegistros(FILE* arquivoEntrada)
{
    int quantidadeRegistros;

    fseek(arquivoEntrada, 0, SEEK_END);

    quantidadeRegistros = ftell(arquivoEntrada) / sizeof(contato_t);

    rewind(arquivoEntrada);

    return quantidadeRegistros;
}

/* Adiciona um registro no vetor com todos os registros */
void cadastrarRegistro(contato_t** agenda, int* quantidadeRegistros)
{
    contato_t novoRegistro = lerNovoRegistro();

    for(int i = 0; i < *quantidadeRegistros; ++i)
    {
        if((*agenda[i]).excluido)
        {
            *agenda[i] = novoRegistro;
            return;
        }
    }

    (*quantidadeRegistros)++;

    contato_t *maisContatos = NULL;
    maisContatos = (contato_t*)realloc(*agenda, *quantidadeRegistros);

    if(maisContatos == NULL)
    {
        printf("Erro ao inserir novo contato!\n");
        free(agenda);
        exit(1);
    }

    *agenda = maisContatos;

    *agenda[*quantidadeRegistros - 1] = novoRegistro; 
}

/* Lê um novo registro do usuário */
contato_t lerNovoRegistro()
{
    contato_t novoRegistro;

    printf("Insira o nome: ");
    scanf("%s", novoRegistro.nomeCompleto);

    printf("Insira a cidade: ");
    scanf("%s", novoRegistro.cidade);

    printf("Insira a Unidade Federativa (sigla): ");
    scanf("%s", novoRegistro.UF);

    printf("Insira a data de nascimento: \n");
    printf("\t--Dia: ");
    scanf("%d", &novoRegistro.dataNascimento.dia);
    printf("\t--Mês: ");
    scanf("%d", &novoRegistro.dataNascimento.mes);
    printf("\t--Ano: ");
    scanf("%d", &novoRegistro.dataNascimento.ano);

    printf("Insira os gostos por esportes (0 a 10): \n");
    printf("\t---Futebol: ");
    scanf("%f", &novoRegistro.esportes.futebol);

    printf("\t---Basquete: ");
    scanf("%f", &novoRegistro.esportes.basquete);

    printf("\t---Vôlei: ");
    scanf("%f", &novoRegistro.esportes.volei);

    novoRegistro.grupo = 0;
    
    novoRegistro.excluido = FALSE;
    
    return novoRegistro;
}

void editarRegistro(contato_t* agenda, int quantidadeRegistros)
{
    return;
}

void excluirRegistro(contato_t* agenda, int quantidadeRegistros)
{
    int opcao = menuBusca();
    int posicaoRegistro = buscarRegistro(agenda, quantidadeRegistros);

    if(posicaoRegistro == -1)
    {
        printf("Contato não encontrado!\n");
        return;
    }

    agenda[posicaoRegistro].excluido = TRUE;
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
    FILE* arquivoSaida = fopen(NOME_ARQUIVO, "wb");

    if(arquivoSaida == NULL)
    {
        printf("Erro ao salvar dados no arquivo %s!\n", NOME_ARQUIVO);
        free(agenda);
        exit(1);
    }

    fwrite(agenda, sizeof(contato_t), quantidadeRegistros, arquivoSaida);

    fclose(arquivoSaida);

    return;
}