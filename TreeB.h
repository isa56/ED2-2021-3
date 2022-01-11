#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <sys/stat.h>
#include <algorithm>

#include "TreeBNo.h" //incluindo o '.h' do Nó da Árvore B

using namespace std;

class TreeB {
    private:
        TreeBNo *raiz; //Ponteiro para o nó raiz
        int t; //grau minimo

    public:
        TreeB(int grau); //Construtor

        //Função para percorrer a árvore
        void percorrer()
        { if(raiz != NULL) raiz->percorrer(); }

        //Função para buscar chave na árvore
        TreeBNo *buscar(int k)
        {return (raiz == NULL)? NULL : raiz->buscar(k); }

        // A função main que insere uma nova chave
        void inserir(int k); 
};