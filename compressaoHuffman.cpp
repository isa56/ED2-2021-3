#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <algorithm>

#include "compressaoHuffman.h"

using namespace std;

NoHeapMinimo *novoNo(char dado, unsigned freq)
{
    NoHeapMinimo *temp = (NoHeapMinimo *)malloc(sizeof(NoHeapMin));

    temp->esquerda = NULL;
    temp->direita = NULL;
    temp->dado = dado;
    temp->frequencia = freq;

    return temp;
}

HeapMinimo *criarHeapMinimo(unsigned capacidade)
{

    HeapMinimo *heapMinimo = (struct HeapMinimo *)malloc(sizeof(HeapMinimo));

    heapMinimo->tamanho = 0;
    heapMinimo->capacidadeMaxima = capacidade;

    heapMinimo->arrayNos = (NoHeapMinimo **)malloc(heapMinimo->capacidadeMaxima * sizeof(NoHeapMinimo *));

    return heapMinimo;
}

void trocaNoHeapMinimo(NoHeapMinimo **a, NoHeapMinimo **b)
{
    NoHeapMinimo *temp = *a;
    *a = *b;
    *b = t;
}

void minHeapify(HeapMinimo *minHeap, int idx)
{
    int menor = idx;
    int esq = 2 * idx + 1;
    int dir = 2 * idx + 2;

    if (esq < minHeap->tamanho && minHeap->arrayNos[esq]->freq < minHeap->arrayNos[menor]->freq)
    {
        menor = esq;
    }

    if (dir < minHeap->tamanho && minHeap->arrayNos[dir]->freq < minHeap->arrayNos[menor]->freq)
    {
        menor = dir;
    }

    if (menor != idx)
    {
        trocaNoHeapMinimo(&minHeap->arrayNos[menor], &minHeap->arrayNos[idx]);
        minHeapify(minHeap, menor);
    }
}

int ehUnitario(HeapMinimo *minHeap)
{
    return (minHeap->tamanho == 1);
}

NoHeapMinimo *extrairMinimo(HeapMinimo *minHeap)
{
    NoHeapMinimo *temp = minHeap->arrayNos[0];
    minHeap->arrayNos[0] = minHeap->arrayNos[minHeap->tamanho - 1];

    --(minHeap->tamanho);

    minHeapify(minHeap, 0);

    return temp;
}

void inserirHeapMinimo(HeapMinimo *minHeap, NoHeapMinimo *noHeap)
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

void montaHeapMinimo(HeapMinimo *minHeap)
{
    int n = minHeap->tamanho - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
    {
        minHeapify(minHeap, i);
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

int ehFolha(NoHeapMinimo *raiz)
{
    return (!(raiz->esquerda) && !(raiz->direita));
}

HeapMinimo *criaMontaHeapMin(char dados[], int freq[], int tamanho)
{
    HeapMinimo *minHeap = criarHeapMinimo(tamanho);

    for (int i = 0; i < tamanho; ++i)
    {
        minHeap->arrayNos[i] = novoNo(dados[i], freq[i]);
    }

    minHeap->tamanho = tamanho;
    montaHeapMinimo(minHeap);

    return minHeap;
}

NoHeapMinimo *montaArvoreHuffman(char dados[], int freq[], int tamanho)
{
    NoHeapMinimo *esq, *dir, *acima;

    HeapMinimo *minHeap = criaMontaHeapMin(dados, freq, tamanho);

    while (!ehUnitario(minHeap))
    {

        esq = extrairMinimo(minHeap);
        dir = extrairMinimo(minHeap);

        acima = novoNo('$', esq->freq + dir->freq);

        acima->esquerda = esq;
        acima->direita = dir;

        inserirHeapMinimo(minHeap, acima);
    }

    return (extrairMinimo(minHeap));
}

void imprimeCodigos(NoHeapMinimo *raiz, int arr[], int acima)
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

void codigosHuffman(char dados[], int freq[], int tamanho)
{

    NoHeapMinimo *raiz = montaArvoreHuffman(dados, freq, tamanho);

    int arr[TAMANHO_MAX_ARVORE], acima = 0;

    imprimeCodigos(raiz, arr, acima);

}
