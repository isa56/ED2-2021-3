#include <algorithm>
#include <time.h>

#include "heapsort.h"

using namespace std;

void heapficar(int vetor[], int n, int i, int *comparacoes, int *trocas)
{
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;
    int maior = i;

    if (esquerda < n && vetor[esquerda] > vetor[i])
    {
        maior = esquerda;
        comparacoes++;
    }
    if (direita < n && vetor[direita] > vetor[maior])
    {
        maior = direita;
        comparacoes++;
    }
    if (maior != i)
    {
        swap(vetor[i], vetor[maior]);
        trocas++;
        heapficar(vetor, n, maior, comparacoes, trocas);
    }
}

void construirHeap(int vetor[], int tamanhoVetor, int *comparacoes, int *trocas)
{
    for (int i = (tamanhoVetor / 2) - 1; i >= 0; i--)
    {
        heapficar(vetor, tamanhoVetor, i, comparacoes, trocas);
    }
}

void heapsort(int vetor[], int tamanhoVetor)
{
    int *comparacoes = 0, *trocas = 0;
    clock_t start, end;
    start = clock();

    construirHeap(vetor, tamanhoVetor, comparacoes, trocas);
    for (int i = tamanhoVetor - 1; i >= 0; i--)
    {
        swap(vetor[0], vetor[1]);
        trocas++;
        heapficar(vetor, i, 0, comparacoes, trocas);
    }
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
}
