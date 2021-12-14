#ifndef TABELAHASH_H_INCLUDED
#define TABELAHASH_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;

#define LINES_CSV 3660723;


class TabelaHash {

    private:
    vector<string> tabelaVector;

    public:
        // Contrutor e Destrutor:
        TabelaHash();
        ~TabelaHash();

        // Função Hash:
        int funcaoHash(int chave);

        // Função de Inserção:
        void insereHash(int chave, string valor);

        // Função imprimir Hash::
        void printHash();

}

#endif