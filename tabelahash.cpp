#include <bits/stdc++.h>
#include "TabelaHash.h"

using namespace std;

// Construtor e Destrutor:
TabelaHash::TabelaHash()
{
    tamanhoTabela = TAMANHO_TABELA_INICIAL;
    nivelTabela = 0;
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
    return hash % (TAMANHO_TABELA_INICIAL * pow(2, nivelTabela));
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
            qtdPreenchida++;
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
        if (tabela[i].getAppVersion() == "")
            continue;
        cout << tabela[i].getAppVersion() << endl;
    }
}

void TabelaHash::aumentaTabela()
{

    if (qtdPreenchida / tamanhoTabela >= FATOR_CARGA)
    {
        DadoHash novaTabela[tamanhoTabela * 3];
        nivelTabela++;
        // tabela = novaTabela;
    }
    else
    {
        return;
    }
}