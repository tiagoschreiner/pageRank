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

pageS* criaPagina(pageS* page);
void insere(pageS** page, char *nome, char *nomeRef);
void busca(pageS* page, char* nome[30]);

#ifdef __cplusplus
}
#endif

#endif // PAGERANK_H
