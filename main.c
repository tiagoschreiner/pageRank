#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pageRank.h"

int main(void)
{
    pageS* page = NULL;
    char nome[30];
    int codigo, opcao = 5;

    while(opcao != 0){
        printf("\n1 - Insere\n"
               "2 - Adicionar Referencia\n"
               "3 - Busca\n");
        scanf("%d",&opcao);

        if(opcao == 1){
            printf("\nDigite o nome do site: ");
            fflush(stdin);
            gets(nome);
            printf("Digite o codigo como referencia: ");
            scanf("%d",&codigo);
            insere(&page, nome, codigo);
        }else if(opcao == 2){
            /*adiciona uma referencia a uma pagina*/
        }else if(opcao == 3){
            printf("busca a implementar");
        }

    }
    return 0;
}

