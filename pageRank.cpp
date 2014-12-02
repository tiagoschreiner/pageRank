#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pageRank.h"

#ifdef __cplusplus
extern "C" {
#endif

int cod = 1;

pageS* criaPagina(char* nome, int codRef)
{
    pageS* page = (pageS*) malloc(sizeof(pageS));
    page->codigo = cod;
    strcpy(page->nome, nome);

    cod++ ;
    return page;
}

void insere(pageS** page, char* nome, int codRef)
{
    if(*page ==  NULL){
        *page = criaPagina(nome, codRef);
    }else{

    }
}

/*void insereRef()
{

}*/

/*void busca(pageS *page, char *nome)
{

}*/

#ifdef __cplusplus
}
#endif
