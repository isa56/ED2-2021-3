#include <bits/stdc++.h>

struct NoHeapMinimo
{
    char dado;             // Caractere específico
    int frequencia;             // Frequencia do caractere
    NoHeapMinimo *esquerda, *direita; // Filho da esquerda e direita
     
     NoHeapMinimo(char dado, int frequencia)
    {
        esquerda = NULL;
        direita = NULL;
        this->dado = dado;
        this->frequencia = frequencia;
    }
};

struct comparar
{
    bool operator()(NoHeapMinimo* l, NoHeapMinimo* r)
    {
        return (l->frequencia > r->frequencia);
    }
};

void imprimeCodigo(struct NoHeapMinimo* raiz, string str);
void armazenaCodigos(struct NoHeapMinimo* raiz, string str);
void MontaArvoreHuffman(int size);
void calculaFrequencia(string str, int n);
string descompressao(struct NoHeapMinimo* raiz, string s);

