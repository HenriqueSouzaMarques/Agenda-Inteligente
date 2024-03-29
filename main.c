#include <stdio.h>
#include <stdlib.h>

#include "Includes/contato.h"
#include "Includes/utils.h"
#include "Includes/edicao.h"
#include "Includes/buscas.h"
#include "Includes/ordenacao.h"
#include "Includes/agrupar.h"

int main()
{
    int posicaoRegistro;
    int opcao;
    int quantidadeRegistros = 0;
    contato_t* agenda = NULL;

    do
    {
        opcao = menu();

        switch(opcao)
        {
            case 1:
                agenda = lerRegistros(&quantidadeRegistros);
                break;

            case 2:
                cadastrarRegistro(&agenda, &quantidadeRegistros);
                break;

            case 3:
                editarRegistro(agenda, quantidadeRegistros);
                break;

            case 4:
                excluirRegistro(agenda, quantidadeRegistros);
                break;

            case 5:
                posicaoRegistro = buscarRegistro(agenda, quantidadeRegistros);
                printarRegistro(agenda, posicaoRegistro);
                break;

            case 6:
                ordenarRegistros(agenda, quantidadeRegistros);
                break;
        
            case 7:
                agruparRegistros(agenda, quantidadeRegistros);
                break;
            
            case 8: 
                printarTodosRegistros(agenda, quantidadeRegistros);
                break;

            case 9:
                exportarRegistros(agenda, quantidadeRegistros);
                break;
                
            case 0:
                printf("Obrigado por usar o programa!\n");
                free(agenda);
                break;
        }
        
    }while(opcao != 0);

    return 0;
}
