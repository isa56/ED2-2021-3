#ifndef TABELAHASH_H_INCLUDED
#define TABELAHASH_H_INCLUDED

#include <bits/stdc++.h>
#include "DadoHash.h"

class TabelaHash
{

private:
    static const unsigned long int TAMANHO_TABELA_INICIAL = 10003073; //  tamanho da tabela hash: numLinhas total / 32 = 114397, número próximo a isso
    DadoHash tabela[TAMANHO_TABELA_INICIAL];
    int tamanhoTabela;
    int qtdPreenchida;
    void ordenaTabela();
    int funcaoHash(string chave);

public:
    TabelaHash();
    ~TabelaHash();
    bool estaVazia();
    void inserirItem(string chave);
    void imprimirTabela(int qtdImpressa);
};

#endif // TABELAHASH_H_INCLUDED