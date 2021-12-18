#include <algorithm>

using namespace std;

void heapsort(int vetor[], int tamanhoVetor)
{
    construirHeap(vetor, tamanhoVetor);
    for (int i = tamanhoVetor - 1; i >= 0; i--)
    {
        swap(vetor[0], vetor[1]);
        heapficar(vetor, i, 0);
    }
}

void construirHeap(int vetor[], int tamanhoVetor)
{
    for (int i = (tamanhoVetor / 2) - 1; i >= 0; i--)
    {
        heapficar(vetor, tamanhoVetor, i);
    }
}

void heapficar(int vetor[], int n, int i)
{
    int esquerda = 2*i +1;
    int direita = 2*i +2;
    int maior = i;

    if(esquerda < n && vetor[esquerda] > vetor[i]){
        maior = esquerda;
    }
    if (direita < n && vetor[direita] > vetor[maior]){
        maior = direita;
    }
    if(maior != i){
        swap(vetor[i], vetor[maior]);
        heapficar(vetor, n, maior);
    }
}