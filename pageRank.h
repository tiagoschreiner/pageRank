#ifndef PAGERANK_H
#define PAGERANK_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pageS{
    int codigo;
    char nome[30];
    struct pageS **page;
}pageS;

pageS* criaPagina(char *nome, int codRef);
void insere(pageS** page, char *nome, int codRef);
void busca(pageS* page, char *nome);

#ifdef __cplusplus
}
#endif

#endif // PAGERANK_H
