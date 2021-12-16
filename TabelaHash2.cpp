#include <bits/stdc++.h>
#include <list>

using namespace std;

// referencia para a classe:  https://www.youtube.com/watch?v=2_3fR-k-LzI
// referencia para a funcao hash: https://stackoverflow.com/questions/98153/whats-the-best-hashing-algorithm-to-use-on-a-stl-string-when-using-hash-map

class TabelaHash2
{

private:
    static const int gruposHash = 10;   // tamanho da tabela hash
    list<pair<string, int>> tabela[gruposHash]; // chave: versão do app, valor: vezes que aparece

public:
    bool estaVazia() const;
    int funcaoHash(string chave);
    void inserirItem(string chave, int valor);
    void removerItem(string chave);
    void imprimeTabela();
    void maisFrequentes(int numeroImpressoes);

}

bool TabelaHash2::estaVazia()
{
    int soma{};

    for (int i{}; i < gruposHash; i++)
    {
        soma += tabela[i].size();
    }

    if (!soma)
        return true;

    return false;
}

int TabelaHash2::funcaoHash(string chave)
{

    int hash = 0;
    const char *s = chave.c_str();

    while (*s)
        hash = hash * 71 + *s++;

    return hash % gruposHash;
}

void TabelaHash2::inserirItem(string chave, int valor)
{

    int valorHash = funcaoHash(chave);
    string& celula = tabela[valorHash];
    int iteradorInicio = begin(celula);
    bool chaveExiste = false;
    
    for(; iteradorInicio != end(celula); iteradorInicio++) {    // Checa se a chave já existe
        if(iteradorInicio->first == chave) {
            chaveExiste = true;
            iteradorInicio->second = valor;
            break;
        }
    }

    if(!chaveExiste) {
        celula.emplace_back(chave, valor);
    }

    return;

}

void TabelaHash2::removerItem(string chave)
{
    int valorHash = funcaoHash(chave);
    string& celula = tabela[valorHash];
    int iteradorInicio = begin(celula);
    bool chaveExiste = false;
    
    for(; iteradorInicio != end(celula); iteradorInicio++) {    // Checa se a chave já existe
        if(iteradorInicio->first == chave) {
            chaveExiste = true;
            iteradorInicio = cell.erase(iteradorInicio);
            break;
        }
    }

    return;
}

void TabelaHash2::imprimeTabela() { 

    
}