#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pageRank.h"

#define d 0.85
/*d = damping
 *Um usuario que randomicamente clica em links, vai eventualmente parar de clicar,a probabilidade de que em
 * qualquer hora ele poderá continuar é o fator d(damping)
*/

#ifdef __cplusplus
extern "C" {
#endif

int cod = 0;
int tamGrafo = 0;

/*cria e aloca a pagina*/
void criaPagina(grafoS *grafo, char* nome)
{
    pageS* page = (pageS*) malloc(sizeof(pageS));
    page->pageRef = (pageS**) malloc(sizeof(pageS));
    strcpy(page->nome, nome);
    page->codigo = cod;
    grafo->page[tamGrafo] = page;
    page->quantRef = 0;
    page->quantLinksAponta = 0;

    system("cls");
    printf("\nCodigo da Pagina: %d\n",cod);
    printf("Nome da Pagina: %s\n", nome);

    tamGrafo++;
    cod++;
}

/*cria e aloca vetor inicial do grafo*/
grafoS* criaGrafo()
{
    grafoS* grafo = (grafoS*) malloc(sizeof(grafoS));
    grafo->page = (pageS**) malloc(sizeof(pageS));
    return grafo;
}

/*insere paginas*/
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
pageS* procuraPage(grafoS* grafo, int codPage, int aux)
{
    /*aux usado para saber se quer saber se é
     * é para procurar cod de referencia, ou
     *cod pagina normal ||  0 = codPage || 1 = codRef
     *Isso é usado para calcular os OutBounds de cada page*/
    int i;
    for(i = 0; i < tamGrafo; i++)
        if(grafo->page[i]->codigo == codPage){
            if(aux == 1)
                grafo->page[i]->quantLinksAponta ++;
            return grafo->page[i];
        }
    return NULL;
}

/*verifica se a page existe de acordo com o codigo*/
bool verificaPageRef(grafoS* grafo, int codRef)
{
    int i;
    for(i = 0; i < tamGrafo; i++ )
        if(grafo->page[i]->codigo == codRef)
            return true;

    return false;
}

/*insere o codigo da page que o referencia*/
void insereRef(grafoS *grafo, int codPage, int codRef)
{
    pageS* page = NULL;

    if(procuraPage(grafo, codPage,0) != NULL){
        if(verificaPageRef(grafo, codRef)){
            page = procuraPage(grafo, codPage,0);
            if(page->quantRef == 0)
                page->pageRef[page->quantRef] = procuraPage(grafo, codRef,1);
            else{
                realloc(page->pageRef, page->quantRef * sizeof(pageS));
                page->pageRef[page->quantRef] = procuraPage(grafo, codRef,1);
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
        printf("Codigo Page         : %d\n", grafo->page[i]->codigo);
        printf("Nome page           : %s\n", grafo->page[i]->nome);
        printf("pageRank            : %f\n", grafo->page[i]->rank);
        printf("OutBound links      : %d\n", grafo->page[i]->quantLinksAponta);
        printf("Links referenciados : %d\n", grafo->page[i]->quantRef);
        for(i2 = 0; i2 < grafo->page[i]->quantRef; i2 ++)
            printf("%d ", grafo->page[i]->pageRef[i2]->codigo);
        printf("\n\n");
    }
}

/*inicializa o rank de cada pagina inserida ate o momento*/
void inicializaPageRank(grafoS* grafo)
{
    int i;
    for(i = 0; i < tamGrafo; i++)
        grafo->page[i]->rank = (float) 1.0 / tamGrafo;
}

/*calcula o rank de cada pagina*/
void calculaPageRank(grafoS* grafo)
{
    int i,i2;
    float somaRank = 0.0;
    for(i = 0; i < tamGrafo; i++){
        somaRank = 0.0;
        for(i2 = 0; i2 < grafo->page[i]->quantRef; i2 ++)
            somaRank += getPageRank(grafo->page[i]->pageRef[i2]);
        grafo->page[i]->rank = ((1.0 - d) / (float)tamGrafo) + ( d * somaRank);
    }
}

/*pega o rank da page e divide pelo numero de links q ela aponta*/
float getPageRank(pageS* page)
{
    if(page != NULL){
        if(page->quantLinksAponta != 0)
            return ( page->rank / ((float) page->quantLinksAponta));
        else
            return 0.0;
    }else
        return 0.0;
}


#ifdef __cplusplus
}
#endif
