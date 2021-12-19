#include <bits/stdc++.h>
#include "TabelaHash.h"

using namespace std;

// Construtor e Destrutor:
TabelaHash::TabelaHash()
{
    tamanhoTabela = TAMANHO_TABELA_INICIAL;
    nivelTabela = 0;
}

TabelaHash::~TabelaHash()
{
    delete[] tabela;
}

bool TabelaHash::estaVazia()
{
    for (int i = 0; i < tamanhoTabela; i++)
    {
        if (tabela[i]->getAppVersion() != "")
            return false;
    }
    return true;
}

int TabelaHash::funcaoHash(string chave)
{
    int tamS = strlen(chave.c_str()); // strlen funciona com string do c, então c_str converte para o padrão c
    unsigned int hash = 0;            // como hash chega a valores muito grandes, precisamos que ele não "vire" negativo, por isso unsigned

    for (int i = 0; i < tamS; i++)
    {
        hash += chave[i] * (i + 1);
    }
    return hash % tamanhoTabela;
}

void TabelaHash::inserirItem(string chave)
{
    int indiceSondagem = 0; // Índice de Sondagem para recálculo de posição
    int posicao = funcaoHash(chave);
    bool inserido = false;

    do
    {
        if (tabela[posicao]->getAppVersion() == "")
        { // Posição vazia, então insere
            tabela[posicao]->setDados(chave);
            qtdPreenchida++;
            inserido = true;
        }
        else
        {
            if (tabela[posicao]->getAppVersion() == chave) // Posição com a chave, então incrementa o nº de vezes que aparece
            {
                tabela[posicao]->incrementNVezes();
                inserido = true;
            }
            else // Significa que a posição está preenchida por um valor diferente da chave
            {
                indiceSondagem++;
                posicao += indiceSondagem;
            }
        }
    } while (!inserido);

    if (qtdPreenchida / tamanhoTabela >= FATOR_CARGA)
        aumentaTabela();
}

void TabelaHash::ordenaTabela()
{
    // chama a função de ordenação
}

void TabelaHash::imprimirTabela(int qtdImpressa)
{
    ordenaTabela();

    for (int i = 0; i < qtdImpressa; i++)
    {
        if (tabela[i]->getAppVersion() == "")
            continue;
        cout << tabela[i]->getAppVersion() << endl;
    }
}

void TabelaHash::aumentaTabela()
{

    unsigned int novoTamanho = tamanhoTabela * 3;
    TabelaHash novaTabela;
    string valorInserido;
    nivelTabela++;
    for (int i = 0; i < tamanhoTabela; i++)
    {
        if (tabela[i]->getAppVersion() != "")
        {
            valorInserido = tabela[i]->getAppVersion();
            (novaTabela).inserirItem(valorInserido);
        }
    }
    tabela = novaTabela.getTabela();
    tamanhoTabela *= 3;
}

// DadoHash TabelaHash::*getTabela()
// {
//     return *tabela;
// }
