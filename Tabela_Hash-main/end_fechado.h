#ifndef HASH_FECHADO
#define HAHS_FECHADO

#include <vector>
#include <iostream>

using namespace std;

class Hash{
    private:
        vector<vector<int>> tabela;
        int cap;
        int hash(int valor);

    public:
        Hash(int tamanho);
        ~Hash();
        bool buscar(int valor);
        bool inserir(int valor);
        bool remover(int valor);
        bool exibir();
};

#endif