#ifndef ARVORE_H    // INCLUDE GUARD
#define ARVORE_H

// INTERFACE DA ARVORE BINÁRIA DE BUSCA (ARVORE)

typedef struct No No;

bool buscar(No* raiz, int valor);
No* criar(int value);
No* inserir(No* a, int valor);
void largura(No* no);
void liberar(No** no);
void percorrer(No *no);
No* remover(No* raiz, int valor);


#endif // ARVORE_H