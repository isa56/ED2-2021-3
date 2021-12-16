#include <bits/stdc++.h>
#include "TabelaHash.h"

using namespace std;

// Construtor e Destrutor:
TabelaHash::TabelaHash()
{
    tamanhoTabela = TAMANHO_TABELA_INICIAL;
}
TabelaHash::~TabelaHash() {}

bool TabelaHash::estaVazia()
{
    for (int i = 0; i < tamanhoTabela; i++)
    {
        if (tabela[i].getAppVersion() != "")
            return false;
    }
    return true;
}

int TabelaHash::funcaoHash(string chave)
{
    int tamS = strlen(chave.c_str());
    unsigned int hash = 0;

    for (int i = 0; i < tamS; i++)
    {
        hash += chave[i] * (i + 1);
    }
    return hash % tamanhoTabela;
}

void TabelaHash::inserirItem(string chave)
{
    int indiceSondagem = 0;
    int posicao = funcaoHash(chave);
    bool inserido = false;

    do
    {
        if (tabela[posicao].getAppVersion() == "")
        {
            tabela[posicao].setDados(chave);
            // qtdPreenchida++;
            inserido = true;
        }
        else
        {
            if (tabela[posicao].getAppVersion() == chave)
            {
                tabela[posicao].incrementNVezes();
                inserido = true;
            }
            else
            {
                indiceSondagem++;
                posicao += indiceSondagem;
            }
        }
    } while (!inserido);
}

void TabelaHash::ordenaTabela()
{
    // chama a função de ordenação
}

void TabelaHash::imprimirTabela()
{
    ordenaTabela();

    int tamanho = sizeof(tabela) / sizeof(tabela[0]);

    for (int i = 0; i < tamanho; i++)
    {
        if (tabela[i].getAppVersion() == "")
            continue;
        cout << tabela[i].getAppVersion() << endl;
    }
}

/* MAIN PARA TESTE

int main()
{

    TabelaHash tb;

    if (tb.estaVazia())
        cout << "A tabela esta vazia" << endl;
    else
        cout << "a tabela nao esta vazia" << endl;

    tb.inserirItem("11111");
    tb.inserirItem("2165");
    tb.inserirItem("2165");
    tb.inserirItem("564531");
    tb.inserirItem("2684");
    tb.inserirItem("5431");
    tb.inserirItem("518");
    tb.inserirItem("518");

    tb.imprimirTabela();

    if (tb.estaVazia())
    {
        cout << "A tabela está vazia" << endl;
    }
    else
    {
        cout << "a tabela não está vazia" << endl;
    }

    return 0;
}
*/