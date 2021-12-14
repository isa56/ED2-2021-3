#ifndef TABELAHASH_H_INCLUDED
#define TABELAHASH_H_INCLUDED

#include <bits/stdc++.h>

#define FATOR_CARGA 0.35;
#define TAMANHO_INICIAL 127; // numero primo

using namespace std;

class TabelaHash {

    // Tabela Hash: a chave é a app_version. Deve contar quantas vezes cada version existe... seria esse o valor?

    private:
    DadoHash dados[TAMANHO_INICIAL];
    int tamanho;
    int numeroEntradas = 0;

    public:
        // Contrutor e Destrutor:
        TabelaHash();
        ~TabelaHash();

        // Função Hash:
        int funcaoHash(string chave) {
            return (chave) % tamanho;
        }

        // Função de Inserção:
        void insereHash(string chave, int valor) {

            if(numeroEntradas / tamanho > FATOR_CARGA)
                rehash();

            int indice = funcaoHash(chave);

            if(dados[indice].getChave() == chave) dados[indice].incrementaValor();  // Já existe, aumenta o número de chaves iguais
            else if(dados[indice].getChave() == null) dados[indice].setElemento(chave, valor);  // Não existe, setta o elemento na posicao
            else    // Já existe mas não é o valor 'chave'

            numeroEntradas++;

        }

        // Função imprimir Hash:
        void printHash() { 
            for(int i = 0; i < numeroEntradas; i++)
                cout << dados[i] << " ";
            cout << endl;
        }

        // Rehash da tabela:
        void rehash() { 

        }

}

#endif