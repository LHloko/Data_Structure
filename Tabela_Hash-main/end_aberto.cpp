#include "end_fechado.h"

int Hash::hash(int valor){
    return valor%cap;
}

Hash::Hash(int tamanho){
    cap = tamanho;
    vector<vector<int>> t(cap, vector<int>(0, 0));
    tabela = t;
}

Hash::~Hash(){
    for(int i=0; i<cap; i++)
        for(int j=0; j<tabela[i].size(); j++)
            tabela[i].pop_back();
}

bool Hash::buscar(int valor){
    int chave = hash(valor);
    
    if(tabela[chave].empty()) //retorna falso caso nao tenha nenhum item na lista
        return false;

    for(int i=0; i<tabela[chave].size(); i++)
        if(tabela[chave][i] == valor)
            return true;    

    return false;
}

bool Hash::inserir(int valor){
    int chave = hash(valor);
    tabela[chave].push_back(valor);
    return true;
}

bool Hash::remover(int valor){
    int chave = hash(valor);
    
    if(tabela[chave].empty()) //retorna falso caso nao tenha nenhum item na lista
        return false;

    for(int i=0; i<tabela[chave].size(); i++)
        if(tabela[chave][i] == valor){
            tabela[chave].erase(tabela[chave].begin()+i); //tem jeito melhor de fazer isso ? 
            return true;
        }

    return false;
}

bool Hash::exibir(){
    //vou fazer o algoritmo virar n², infelizmente :D 
    for(int i=0; i<cap; i++){
        cout<<"[ %i ] ",i;
        
        for(auto j: tabela[i])
            cout<<j<<" ";
        cout<<endl;
    }
}
