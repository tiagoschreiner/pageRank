#ifndef PAGERANK_H
#define PAGERANK_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pageS{
    int codigo;
    char nome[30];
    float rank;
    int quantLinksAponta;
    int quantRef;
    struct pageS** pageRef;
}pageS;

typedef struct grafoS{
    struct pageS **page;
}grafoS;

void criaPagina(grafoS *grafo, char *nome);
grafoS* criaGrafo();
void insere(grafoS **grafo, char *nome);
pageS* procuraPage(grafoS* grafo, int codPage, int aux);
void insereRef(grafoS *grafo, int codPage, int codRef);
void mostraTudo(grafoS* grafo);
void inicializaPageRank(grafoS* grafo);
float getPageRank(pageS* page);
void calculaPageRank(grafoS* grafo);

#ifdef __cplusplus
}
#endif

#endif // PAGERANK_H
