#ifndef PAGERANK_H
#define PAGERANK_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pageS{
    int codigo;
    char nome[30];
    int *codRef, quantRef;
}pageS;

typedef struct grafoS{
    struct pageS **page;
}grafoS;

void criaPagina(grafoS *grafo, char *nome);
grafoS* criaGrafo();
void insere(grafoS **grafo, char *nome);
pageS* procuraPage(grafoS *grafo, int codPage);
void insereRef(grafoS *grafo, int codPage, int codRef);
void busca(grafoS* grafo, char *nome);
void mostraTudo(grafoS* grafo);

#ifdef __cplusplus
}
#endif

#endif // PAGERANK_H
