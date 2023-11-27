#include <bits/stdc++.h>
#include "arvore.h"
using namespace std;

struct No{
    int value;
    No * sae;
    No * sad;
};

bool buscar(No *raiz, int valor){
    if(raiz == NULL)
        return false;

    if(raiz->value == valor)
        return true;
    
    if(raiz->value > valor)
        buscar(raiz->sae, valor);
    else
        buscar(raiz->sad, valor);
}

No* criar(int value){
    No *raiz = (No*) calloc(1, sizeof(No));
    raiz->sad = NULL; raiz->sae = NULL;
    raiz->value = value;
    return raiz;
}

No* inserir(No* no, int valor){
    if(no == NULL)
        return criar(valor);
    
    if(valor < no->value)
        no->sae = inserir(no, valor);
    else
        no->sad = inserir(no, valor);
    
    return no;
}

void largura(No* no) {
    queue<No*> f;
    f.push(no);
    while(!f.empty()) {
        No* atual = f.front();
        cout << atual->value << " ";
        f.pop();
        if(atual->sae)
            f.push(atual->sae);
        if(atual->sad)
            f.push(atual->sad);
    }
}

void liberar(No ** no){
    if(no == NULL)
        return;
    
    No* temp = *no;
    liberar(&((*no)->sae));
    liberar(&((*no)->sad));
    free(temp);
}

No* minimo(No* no) {
    if(no->sae != NULL)
        return minimo(no->sae);

    return no;
}

No* remover(No* no, int valor) {
    if(no == NULL)
        return NULL;
    
    if(valor < no->value) {
        no->sae = remover(no->sae, valor);
    } else if(valor > no->value) {
        no->sad = remover(no->sad, valor);
    } else {
        No* temp = NULL;
        if(no->sae == NULL && no->sad == NULL) {
            free(no);
            return NULL;
        } else if(no->sae == NULL) {
            temp = no->sad;
            free(no);
            return temp;
        } else if(no->sad == NULL) {
            temp = no->sae;
            free(no);
            return temp;
        } else {
            temp = minimo(no->sad);
            no->value = temp->value;
            no->sad = remover(no->sad, temp->value);
        }
    }

    return no;
}