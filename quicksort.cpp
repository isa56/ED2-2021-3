#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <algorithm>

#include "quicksort.h"

using namespace std;

void troca(int *e1, int *e2)
{
    int t = *e1;
    *e1 = *e2;
    *e2 = t;
}

int particionamentoQuickSort(int vetor[], int a, int b, int *contadorTroca, int *contadorComparacao)
{
    int pivo = vetor[b]; // pivô
    int i = (a - 1);     // Índice do elemento menor

    for (int j = a; j <= b - 1; j++)
    {
        //Se o elemento atual é menor ou igual ao pivô
        if (vetor[j] <= pivo)
        {
            (*contadorComparacao)++; //Conta o numero de comparacoes feitas

            i++; // aumenta o índice do elemento menor
            troca(&vetor[i], &vetor[j]);

            (*contadorTroca)++; // Conta o numero de trocas feitas 
        }
    }
    troca(&vetor[i + 1], &vetor[b]);
    (*contadorTroca)++; //Conta o numero de trocas feitas

    return (i + 1);
}

void ordenacaoQuickSort(int vetor[], int a, int b)
{
    int comparacao;
    int qnt_troca;
    int tempo;
    
    comparacao = 0;
    qnt_troca = 0; 
    tempo = 0;

    if (a < b)
    {

        int indiceParticionamento = particionamentoQuickSort(vetor, a, b, &qnt_troca, &comparacao);

        // Faz o sort dos elementos em separado, de cada partição
        ordenacaoQuickSort(vetor, a, indiceParticionamento - 1);
        ordenacaoQuickSort(vetor, indiceParticionamento + 1, b);


    }

    cout << "Quantidade de troca " << qnt_troca;
    cout << "Comparacao" << comparacao;
    cout << "Tempo em execucao " << tempo;

}



