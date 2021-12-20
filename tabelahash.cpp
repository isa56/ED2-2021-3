#include <bits/stdc++.h>
#include "TabelaHash.h"

using namespace std;

// Construtor e Destrutor:
//TabelaHash::TabelaHash(){}

//TabelaHash::~TabelaHash(){}

bool TabelaHash::estaVazia()
{
    for (int i = 0; i < TAMANHO_TABELA_INICIAL; i++)
    {
        if (tabela[i].getAppVersion() != "")
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
    return hash % TAMANHO_TABELA_INICIAL;
}

void TabelaHash::inserirItem(string chave)
{

    int indiceSondagem = 0; // Índice de Sondagem para recálculo de posição
    int posicao = funcaoHash(chave);
    bool inserido = false;

    do
    {
        if (tabela[posicao].getAppVersion() == "")
        { // Posição vazia, então insere
            tabela[posicao].setDados(chave);
            qtdPreenchida++;
            inserido = true;
        }
        else
        {
            if (tabela[posicao].getAppVersion() == chave) // Posição com a chave, então incrementa o nº de vezes que aparece
            {
                tabela[posicao].incrementNVezes();
                inserido = true;
            }
            else // Significa que a posição está preenchida por um valor diferente da chave
            {
                indiceSondagem++;
                posicao += indiceSondagem;
            }
        }
        if(posicao == TAMANHO_TABELA_INICIAL - 1 || qtdPreenchida == TAMANHO_TABELA_INICIAL)
        {
            cout << "Não é possível inserir um novo elemento" << endl;
            continue;
        }
    } while (!inserido);

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
