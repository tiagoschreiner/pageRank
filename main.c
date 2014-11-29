#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pageRank.h"

int main(void)
{
    pageS* page = NULL;
    char nome[30], nomeRef[30];

    printf("Digite o nome do site: ");
    fflush(stdin);
    gets(nome);
    printf("Digite o nome da pagina de referencia: ");
    fflush(stdin);
    gets(nomeRef);
    insere(&page, nome, nomeRef);
    return 0;
}

