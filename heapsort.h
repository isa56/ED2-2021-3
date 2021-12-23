#ifndef HEAPSORT_H_INCLUDED
#define HEAPSORT_H_INCLUDED

#include <algorithm>
#include <time.h>
using namespace std;

void heapficar(int vetor[], int n, int i, int *comparacoes, int *trocas);
void construirHeap(int vetor[], int tamanhoVetor, int *comparacoes, int *trocas);
void heapsort(int vetor[], int tamanhoVetor);

#endif