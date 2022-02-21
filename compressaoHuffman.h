#ifndef COMPRESSAOHUFFMAN_H_INCLUDED
#define COMPRESSAOHUFFMAN_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <time.h>
#include <math.h>
#include <algorithm>

using namespace std;


struct NoHeapMinimo
{
    char dado;
    unsigned frequencia;
    struct NoHeapMinimo *esquerda, *direita;
};

struct HeapMinimo
{
    unsigned tamanho, capacidadeMaxima;
    struct NoHeapMinimo **arrayNos;
};


struct NoHeapMinimo *novoNo(char dado, unsigned frequencia);
struct HeapMinimo *criarHeapMinimo(unsigned capacidade);
void trocaNoHeapMinimo(struct NoHeapMinimo **a, struct NoHeapMinimo **b);
void minHeapify(struct HeapMinimo *minHeap, int idx);
int ehUnitario(struct HeapMinimo *minHeap);
struct NoHeapMinimo *extrairMinimo(struct HeapMinimo *minHeap);
void inserirHeapMinimo(struct HeapMinimo *minHeap, struct NoHeapMinimo *noHeap);
void montaHeapMinimo(struct HeapMinimo *minHeap);
void imprimeArray(int arr[], int n);
int ehFolha(struct NoHeapMinimo *raiz);
struct HeapMinimo *criaMontaHeapMin(char dados[], int frequencia[], int tamanho);
struct NoHeapMinimo *montaArvoreHuffman(char dados[], int frequencia[], int tamanho);
void imprimeCodigos(struct NoHeapMinimo *raiz, int arr[], int acima);
int codigosHuffman(char dados[], int frequencia[], int tamanho);

#endif