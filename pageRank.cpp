#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pageRank.h"

#ifdef __cplusplus
extern "C" {
#endif

int cod = 0;
int tamGrafo = 0;

void criaPagina(grafoS *grafo, char* nome)
{
    pageS* page = (pageS*) malloc(sizeof(pageS));
    page->codRef = (int*) malloc(sizeof(int));
    strcpy(page->nome, nome);
    page->codigo = cod;
    grafo->page[tamGrafo] = page;
    page->quantRef = 0;

    system("cls");
    printf("Codigo da Pagina: %d\n",cod);
    printf("Nome da Pagina: %s\n", nome);

    tamGrafo++;
    cod++;
}

grafoS* criaGrafo()
{
    grafoS* grafo = (grafoS*) malloc(sizeof(grafoS));
    grafo->page = (pageS**) malloc(sizeof(pageS));
    return grafo;
}

void insere(grafoS **grafo, char* nome)
{
    if(*grafo ==  NULL){
        *grafo = criaGrafo();
        criaPagina(*grafo, nome);
    }else{
        criaPagina(*grafo, nome);
    }
}

/*retorna a page se ela existe de acordo com o codigo*/
pageS* procuraPage(grafoS* grafo, int codPage)
{
    int i;
    for(i = 0; i < tamGrafo; i++)
        if(grafo->page[i]->codigo == codPage)
            return grafo->page[i];

    return NULL;
}

/*verifica se a page existe de acordo com o codigo de referencia*/
bool verificaPageRef(grafoS* grafo, int codRef)
{
    int i;
    for(i = 0; i < tamGrafo; i++ )
        if(grafo->page[i]->codigo == codRef)
            return true;

    return false;
}

/*insere a o codigo da page que o referencia*/
void insereRef(grafoS *grafo, int codPage, int codRef)
{
    pageS* page = NULL;

    if(procuraPage(grafo, codPage) != NULL){
        if(verificaPageRef(grafo, codRef)){
            page = procuraPage(grafo, codPage);
            if(page->quantRef == 0)
                page->codRef[page->quantRef] = codRef;
            else{
                realloc(page->codRef, page->quantRef * sizeof(int));
                page->codRef[page->quantRef] = codRef;
            }
            page->quantRef++;
        }else
            printf("Codigo para pagina de referencia nao existe !!\n");
    }else
        printf("Pagina nao existe");
}

/*void busca(pageS *page, char *nome)
{

}*/

void mostraTudo(grafoS* grafo)
{
    int i, i2;
    for(i = 0; i < tamGrafo; i++ ){
        printf("Codigo Page: %d\n", grafo->page[i]->codigo);
        printf("Nome page: %s\n", grafo->page[i]->nome);
        for(i2 = 0; i2 < grafo->page[i]->quantRef; i2 ++)
            printf("%d  ", grafo->page[i]->codRef[i2]);
        printf("\n\n");
    }
}

#ifdef __cplusplus
}
#endif
