#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <algorithm>

using namespace std;

void ordenacaoCombSort(int vetor[])
{
    int troca, comparacao, qnt_troca, tamanho_vetor, intervalo;
    float tempo;

    troca = 0;
    comparacao = 0;
    qnt_troca = 0;
    tamanho_vetor = sizeof(vetor) / sizeof(int);
    intervalo = (int)(tamanho_vetor / 1.3);
    tempo = 0.0;

    while(intervalo > 0 && troca != tamanho_vetor - 1) {
        troca = 0;
        for(int i = 0; (i + intervalo) < tamanho_vetor; i++){
            comparacao += 1;
            if(vetor[i] > vetor[i + intervalo]){
                int aux = vetor[i];
                vetor[i] = vetor[i + intervalo];
                vetor[i + intervalo] = aux;
                troca = 1;
                qnt_troca += troca;
            }
        }
        intervalo = (int)(intervalo / 1.3);
        tempo = clock();
    }

    for(int i = 0; i < tamanho_vetor; i++){
        cout << " " << vetor[i];
    }
    cout << endl;

    cout << "Quantidade de trocas => " << qnt_troca << endl;
    cout << "Quantidade de comparacoes => " << comparacao << endl;
    cout << "Tempo de execucao => " << tempo << endl;
}