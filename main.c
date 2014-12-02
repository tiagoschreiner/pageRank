#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pageRank.h"

int main(void)
{
    grafoS* grafo = NULL;
    char nome[30];
    int codigo, codigoRef, opcao = 5;

    while(opcao != 0){
        printf("\n1 - Insere\n"
               "2 - Adicionar Referencia\n"
               "3 - Busca\n"
               "4 - Mostra Tudo\n");
        scanf("%d",&opcao);

        if(opcao == 1){
            printf("\nDigite o nome do site: ");
            fflush(stdin);
            gets(nome);
            insere(&grafo, nome);
        }else if(opcao == 2){
            printf("Digite o codigo do site: ");
            scanf("%d",&codigo);
            printf("Digite o codigo do site que o referencia: ");
            scanf("%d",&codigoRef);
            insereRef(grafo, codigo, codigoRef);
        }else if(opcao == 3){
            printf("busca a implementar");
        }else if(opcao == 4){
            mostraTudo(grafo);
        }

    }
    return 0;
}

