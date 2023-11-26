#ifndef HASH_ABERTO
#define HASH_ABERTO

#include <vector>
#include <iostream>

using namespace std;

class Hash{
    private:
        int hash(int valor);
        int cap;
        vector<int> tabela;

    public:
        Hash(int tamanho);
        ~Hash();
        bool buscar(int valor);
        bool inserir(int valor);
        bool remover(int valor);
        void exibir();
};

#endif