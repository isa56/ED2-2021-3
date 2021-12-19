#ifndef TABELAHASH_H_INCLUDED
#define TABELAHASH_H_INCLUDED

#include <bits/stdc++.h>
#include "DadoHash.h"

class TabelaHash
{

private:
    static const int TAMANHO_TABELA_INICIAL = 114397; // tamanho da tabela hash - 32 avos do número de linhas do csv
    static const float FATOR_CARGA = 0.35;            // fator de carga
    DadoHash *tabela[TAMANHO_TABELA_INICIAL];
    int tamanhoTabela;
    int qtdPreenchida;
    int nivelTabela;
    void ordenaTabela();
    int rehash();
    int funcaoHash(string chave);
    void aumentaTabela();

public:
    TabelaHash();
    ~TabelaHash();
    bool estaVazia();
    void inserirItem(string chave);
    void imprimirTabela(int qtdImpressa);
};

#endif // TABELAHASH_H_INCLUDED