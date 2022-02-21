#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <time.h>
#include <math.h>
#include <algorithm>

#define TAMANHO_MAX_ARVORE 100

#include "compressaoHuffman.h"

using namespace std;

struct NoHeapMinimo *novoNo(char dado, unsigned frequencia)
{
    struct NoHeapMinimo *temp = (struct NoHeapMinimo *)malloc(sizeof(struct NoHeapMinimo));

    temp->esquerda = NULL;
    temp->direita = NULL;
    temp->dado = dado;
    temp->frequencia = frequencia;

    return temp;
}

struct HeapMinimo *criarHeapMinimo(unsigned capacidade)
{

    struct HeapMinimo *heapMinimo = (struct HeapMinimo *)malloc(sizeof(HeapMinimo));

    heapMinimo->tamanho = 0;
    heapMinimo->capacidadeMaxima = capacidade;

    heapMinimo->arrayNos = (struct NoHeapMinimo **)malloc(heapMinimo->capacidadeMaxima * sizeof(struct NoHeapMinimo *));

    return heapMinimo;
}

void trocaNoHeapMinimo(struct NoHeapMinimo **a, struct NoHeapMinimo **b)
{
    struct NoHeapMinimo *temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct HeapMinimo *minHeap, int idx, int *numComparacoes)
{
    int menor = idx;
    int esq = 2 * idx + 1;
    int dir = 2 * idx + 2;

    if (esq < minHeap->tamanho && minHeap->arrayNos[esq]->frequencia < minHeap->arrayNos[menor]->frequencia)
    {
        menor = esq;
    }

    if (dir < minHeap->tamanho && minHeap->arrayNos[dir]->frequencia < minHeap->arrayNos[menor]->frequencia)
    {
        menor = dir;
    }

    numComparacoes += 3;
    if (menor != idx)
    {
        trocaNoHeapMinimo(&minHeap->arrayNos[menor], &minHeap->arrayNos[idx]);
        minHeapify(minHeap, menor, numComparacoes);
    }
}

int ehUnitario(struct HeapMinimo *minHeap)
{
    return (minHeap->tamanho == 1);
}

struct NoHeapMinimo *extrairMinimo(struct HeapMinimo *minHeap, int *numComparacoes)
{
    struct NoHeapMinimo *temp = minHeap->arrayNos[0];
    minHeap->arrayNos[0] = minHeap->arrayNos[minHeap->tamanho - 1];

    --(minHeap->tamanho);

    minHeapify(minHeap, 0, numComparacoes);

    return temp;
}

void inserirHeapMinimo(struct HeapMinimo *minHeap, struct NoHeapMinimo *noHeap)
{
    ++(minHeap->tamanho);
    int i = minHeap->tamanho - 1;

    while (i && noHeap->frequencia < minHeap->arrayNos[(i - 1) / 2]->frequencia)
    {
        minHeap->arrayNos[i] = minHeap->arrayNos[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->arrayNos[i] = noHeap;
}

void montaHeapMinimo(struct HeapMinimo *minHeap, int *numComparacoes)
{
    int n = minHeap->tamanho - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
    {
        minHeapify(minHeap, i, numComparacoes);
    }
}

void imprimeArray(int arr[], int n)
{
    int i = 0;
    for (; i < n; ++i)
    {
        cout << arr[i];
    }
    cout << endl;
}

int ehFolha(struct NoHeapMinimo *raiz)
{
    return (!(raiz->esquerda) && !(raiz->direita));
}

struct HeapMinimo *criaMontaHeapMin(char dados[], int frequencia[], int tamanho, int *numComparacoes)
{
    struct HeapMinimo *minHeap = criarHeapMinimo(tamanho);

    for (int i = 0; i < tamanho; ++i)
    {
        minHeap->arrayNos[i] = novoNo(dados[i], frequencia[i]);
    }

    minHeap->tamanho = tamanho;
    montaHeapMinimo(minHeap, numComparacoes);

    return minHeap;
}

struct NoHeapMinimo *montaArvoreHuffman(char dados[], int frequencia[], int tamanho, int *numComparacoes)
{
    struct NoHeapMinimo *esq, *dir, *acima;

    struct HeapMinimo *minHeap = criaMontaHeapMin(dados, frequencia, tamanho, numComparacoes);

    while (!ehUnitario(minHeap))
    {

        esq = extrairMinimo(minHeap, numComparacoes);
        dir = extrairMinimo(minHeap, numComparacoes);

        acima = novoNo('$', esq->frequencia + dir->frequencia);

        acima->esquerda = esq;
        acima->direita = dir;

        inserirHeapMinimo(minHeap, acima);
    }

    return (extrairMinimo(minHeap));
}

void imprimeCodigos(struct NoHeapMinimo *raiz, int arr[], int acima)
{

    if (raiz->esquerda)
    {
        arr[acima] = 0;
        imprimeCodigos(raiz->esquerda, arr, acima + 1);
    }

    if (raiz->direita)
    {
        arr[acima] = 1;
        imprimeCodigos(raiz->direita, arr, acima + 1);
    }

    if (ehFolha(raiz))
    {
        cout << raiz->dado << ": ";
        imprimeArray(arr, acima);
    }
}

float *calculaTaxaCompressao(int *array, char dados[])
{
    int entrada = strlen(dados) * sizeof(char);
    int saida = sizeof(array) / 8;
    float taxa = ((entrada - saida) / entrada);
    return &taxa;
}

int codigosHuffman(char dados[], int frequencia[], int tamanho, float *taxaCompressao)
{

    int numComparacoes;
    struct NoHeapMinimo *raiz = montaArvoreHuffman(dados, frequencia, tamanho, &numComparacoes);

    int arr[TAMANHO_MAX_ARVORE], acima = 0;

    imprimeCodigos(raiz, arr, acima);

    std::fstream arqSaida;
    arqSaida.open("reviewsComp.bin", ios::out | ios::binary);

    arqSaida.write(reinterpret_cast<const char *>(arr), sizeof(arr));

    taxaCompressao = calculaTaxaCompressao(arr, dados);

    return numComparacoes;
}
