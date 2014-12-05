#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pageRank.h"

int main(void)
{
    grafoS* grafo = NULL;
    char nome[30];
    int codigo, codigoRef, opcao = 5, flag = 0;

    while(opcao != 0){
        printf("\n1 - Insere Pagina\n"
               "2 - Inicilizar pageRank\n"
               "3 - Adicionar Referencia\n"
               "4 - Calcula pageRank\n"
               "5 - Mostra Tudo\n");
        scanf("%d",&opcao);

        if(opcao == 1){
            printf("\nDigite o nome da pagina: ");
            fflush(stdin);
            gets(nome);
            insere(&grafo, nome);
        }else if(opcao == 2){
            if(flag == 0){
                inicializaPageRank(grafo);
                flag = 1;
            }
            else
                printf("O pageRank ja foi inicializado\n");
        }else if(opcao == 3){
            printf("Digite o codigo da pagina: ");
            scanf("%d",&codigo);
            printf("Digite o codigo da pagina que o referencia: ");
            scanf("%d",&codigoRef);
            insereRef(grafo, codigo, codigoRef);
        }else if(opcao == 4){
            calculaPageRank(grafo);
        }else if(opcao == 5){
            mostraTudo(grafo);
        }

    }
    return 0;
}

