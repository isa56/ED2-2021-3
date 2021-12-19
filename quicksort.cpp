#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <algorithm>

using namespace std;

void ordenacaoQuickSort(int vetor[], int a, int b)
{
    if (a < b)
    {

        int indiceParticionamento = particionamentoQuickSort(vetor, a, b);

        // Faz o sort dos elementos em separado, de cada partição
        ordenacaoQuickSort(vetor, a, indiceParticionamento - 1);
        ordenacaoQuickSort(vetor, indiceParticionamento + 1, b);
    }
}

int particionamentoQuickSort(int vetor[], int a, int b)
{
    int pivo = vetor[b]; // pivô
    int i = (a - 1);     // Índice do elemento menor

    for (int j = a; j <= b - 1; j++)
    {
        //Se o elemento atual é menor ou igual ao pivô
        if (vetor[j] <= pivo)
        {
            i++; // aumenta o índice do elemento menor
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i + 1], &vetor[b]);
    return (i + 1);
}

void troca(int *e1, int *e2)
{
    int t = *e1;
    *e1 = *e2;
    *e2 = t;
}