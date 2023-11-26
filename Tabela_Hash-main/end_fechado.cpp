#include "end_aberto.h"

int Hash::hash(int valor){
    return valor%cap;
}

Hash::Hash(int tamanho){
    cap = tamanho;
    vector<int> tab(cap, -1);
    tabela = tab;
}

Hash::~Hash(){
    for(int i=0; i<cap; i++)
        tabela.pop_back();
}

bool Hash::buscar(int valor){
    int chave = hash(valor);

    //Buscar partindo da chave
    //Encontrar -1 sai, -2 prossegue
    //Voltar para posição chave sai

    while(tabela[chave] != -1){
        if(tabela[chave] == valor)
            return true;
        
        chave = (chave + 1)%cap;

        if(chave == hash(valor))
            break;
    }

    return false;
}

bool Hash::inserir(int valor){
    int chave = hash(valor);

    //Entro na posição chave
    //Se for < 0 saio do loop e insiro na posição
    //Se a chave voltar pro inicio retorno falso

    while(tabela[chave] > 0){
        chave = (chave + 1)%cap;
        
        if(chave == hash(valor))
            return false;
    }
    tabela[chave] = valor;
    return true;
}

bool Hash::remover(int valor){
    int chave = hash(valor);

    //Procuro o valor enquanto não encontrar -1
    //Se achar inserir na posição -2
    //Se chave voltar pro inicio retorna falso

    while(tabela[chave] != -1){
        if(tabela[chave] == valor){
            if(tabela[(chave + 1)%cap] == -1)
                tabela[chave] = -1;
            else
                tabela[chave] = -2;
            
            return true;
        }

        chave = (chave + 1)%cap;

        if(chave == hash(valor))
            break;
    }

    return false;
}

void Hash::exibir(){
    for(auto i: tabela)
        cout<< i<<" ";
    cout<<endl;
    
    return;
}
