#ifndef COMPRESSAOHUFFMAN_H_INCLUDED
#define COMPRESSAOHUFFMAN_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <algorithm>

#define TAMANHO_MAX_ARVORE 100

using namespace std;

typedef struct
{
    char dado;
    unsigned frequencia;
    NoHeapMinimo *esquerda, *direita;
} NoHeapMinimo;

typedef struct
{
    unsigned tamanho, capacidadeMaxima;
    NoHeapMinimo **arrayNos;
} HeapMinimo;


NoHeapMinimo *novoNo(char dado, unsigned freq);

void trocaNoHeapMinimo(NoHeapMinimo** a, NoHeapMinimo** b);

void minHeapify(HeapMinimo* minHeap, int idx);

int ehUnitario(HeapMinimo* minHeap);

NoHeapMinimo* extrairMinimo(HeapMinimo* minHeap);

void inserirHeapMinimo(HeapMinimo* minHeap, NoHeapMinimo* noHeap);

void montaHeapMinimo(HeapMinimo *minHeap);

int ehFolha(NoHeapMinimo* raiz);

HeapMinimo *criaMontaHeapMin(char dados[], int freq[], int tamanho);


HeapMinimo *criarHeapMinimo(unsigned capacidade);

void imprimeArray(int arr[], int n);

NoHeapMinimo *montaArvoreHuffman(char dados[], int freq[], int tamanho);

void imprimeCodigos(NoHeapMinimo *raiz, int arr[], int top);

void codigosHuffman(char dados[], int freq[], int tamanho);


#endif