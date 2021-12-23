#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <algorithm>


void troca(int *e1, int *e2);
int particionamentoQuickSort(int vetor[], int a, int b, int *contadorTroca, int *contadorComparacao);
void ordenacaoQuickSort(int vetor[], int a, int b);

#endif