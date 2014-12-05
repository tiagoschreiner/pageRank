#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pageRank.h"

#define d 0.85

#ifdef __cplusplus
extern "C" {
#endif

int cod = 0;
int tamGrafo = 0;

void criaPagina(grafoS *grafo, char* nome)
{
    pageS* page = (pageS*) malloc(sizeof(pageS));
    page->pageRef = (pageS**) malloc(sizeof(pageS));
    strcpy(page->nome, nome);
    page->codigo = cod;
    grafo->page[tamGrafo] = page;
    page->quantRef = 0;

    system("cls");
    printf("\nCodigo da Pagina: %d\n",cod);
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
                page->pageRef[page->quantRef] = procuraPage(grafo, codRef);
            else{
                realloc(page->pageRef, page->quantRef * sizeof(pageS));
                page->pageRef[page->quantRef] = procuraPage(grafo, codRef);
            }
            page->quantRef++;
        }else
            printf("Codigo para pagina de referencia nao existe !!\n");
    }else
        printf("Pagina nao existe");
}

/*mostra todas as paginas do grafo*/
void mostraTudo(grafoS* grafo)
{
    int i, i2;
    system("cls");
    for(i = 0; i < tamGrafo; i++ ){
        printf("Codigo Page: %d\n", grafo->page[i]->codigo);
        printf("Nome page  : %s\n", grafo->page[i]->nome);
        printf("pageRank   : %f\n", grafo->page[i]->rank);
        for(i2 = 0; i2 < grafo->page[i]->quantRef; i2 ++)
            printf("%d  ", grafo->page[i]->pageRef[i2]->codigo);
        printf("\n");
    }
}

/*inicializa o rank de cada pagina inserida ate o momento*/
void inicializaPageRank(grafoS* grafo)
{
    int i;
    for(i = 0; i < tamGrafo; i++){
        grafo->page[i]->rank = (float) 1.0 / tamGrafo;
    }
}

/*calcula o rank de cada pagina*/
void calculaPageRank(grafoS** grafo)
{
    int i;
    for(i = 0; i < tamGrafo; i++)
        calculaRank((*grafo)->page[i]);
}

void calculaRank(pageS* page)
{
    int i;
    float somaRankPageRef = 0.0;

    if(page->quantRef != 0){
        /*soma os ranks das page que referenciam a page atual*/
        for(i = 0; i < page->quantRef; i ++)
            somaRankPageRef += getPageRank(page->pageRef[i]);

        printf("%s %f\n", page->nome, somaRankPageRef);
        /*junta as duas partes da formula e insere o novo rank à page*/
        page->rank = (((0.15 / tamGrafo) + 0.85) * somaRankPageRef);
    }
}

/*pega o rank da page e divide pelo numero de links q ela aponta*/
float getPageRank(pageS* page)
{
    if(page != NULL){
        if(page->quantRef != 0)
            return ((float) page->rank / page->quantRef);
        else
            return 0.0;
    }else
        return 0.0;
}

void busca(grafoS* grafo, char *nome)
{
    pageS** page;
    float* rank;
}

#ifdef __cplusplus
}
#endif
