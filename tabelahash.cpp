#include <bits/stdc++.h>

using namespace std;

#define LINES_CSV 3660723;
#define INITIAL_SIZE 10000;

    // Contrutor e Destrutor:
    TabelaHash(){}
    ~TabelaHash(){}

    // Função Hash:
    int funcaoHash(int chave) {
        return (chave) % INITIAL_SIZE;
    }

    // Função de Inserção:
    void insereHash(int chave, string valor) {
        int posicao = funcaoHash(chave);
        if(tabelaVector[posicao] = null || tabelaVector[posicao] == "") tabelaVector[posicao] = valor;
        else {
            // recalcula a posicao
        }
    }

    // Função imprimir Hash::
    void printHash() { 
        for(int i = 0; i < tabelaVector.size(); i++) 
            cout << tabelaVector[i] << endl;
    }


