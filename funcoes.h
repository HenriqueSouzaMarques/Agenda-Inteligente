#ifndef FUNCOES_H
#define FUNCOES_H

#define TAMANHO_MAXIMO_NOME 100

#define BOOL char
#define TRUE 1
#define FALSE 0

typedef struct data_t_
{
    int dia;
    int mes;
    int ano;
} data_t;

typedef struct preferencias_t_
{
    float futebol;
    float basquete;
    float volei;
} preferencias_t;


typedef struct contato_t_
{
    char nomeCompleto[TAMANHO_MAXIMO_NOME];
    char cidade[TAMANHO_MAXIMO_NOME];
    char UF[2];
    preferencias_t esportes;
    int grupo;
    BOOL excluido;
} contato_t;


int menu();

contato_t* lerRegistros(int* quantidadeRegistros);

int calcularQuantidadeRegistros(FILE* arquivoEntrada);

void cadastrarRegistro(contato_t** agenda, int* quantidadeRegistros);

contato_t lerNovoRegistro();

int buscarRegistro(contato_t* const agenda, int quantidadeRegistros);

void editarRegistro(contato_t* agenda, int quantidadeRegistros);

void excluirRegistro(contato_t* agenda, int quantidadeRegistros);

void ordenarRegistros(contato_t* agenda, int quantidadeRegistros);
    /* Por nome */
    /* Por data */
    /* Por grupo */

void agruparRegistros(contato_t* agenda, int quantidadeRegistros);

void exportarRegistros(contato_t* agenda, int quantidadeRegistros); 


#endif