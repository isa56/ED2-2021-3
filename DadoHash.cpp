#ifndef DADOHASH_H_INCLUDED
#define DADOHASH_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;

class DadoHash {

    private:
    string chave;
    int valor;
    int proximo = -2;

    public:
    DadoHash() { 
        chave = null;
        valor = 0;
    }
    ~DadoHash();

    // Getters e Setters:
    string getChave() { return chave; }
    int getValor() { return valor; }
    
    void setElemento(string key, int value) { 
        chave = key; 
        valor = value; 
        incrementaValor();
    }
    
    // void setChave(string key) { chave = key; }
    // void setValor(string value) { valor = value; }

    void incrementaValor() { valor++; }

}

#endif // DADOHASH_H_INCLUDED