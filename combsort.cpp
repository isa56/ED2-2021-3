#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <algorithm>

using namespace std;

//Para encontrar a lacuna entre os elementos 
int getProximoGap(int gap)
{ 
    gap = (gap * 10) / 13;

    if(gap < 1) {
        return 1;
    }

    return gap;
}

void ordCombSort(int vetor[], int N)
{
    int gap;
    bool trocar;
    int comparar, qnt_troca, troque;
    float tempo;

    gap = N;

    //Inicialize trocado como verdadeiro para garantir que o loop seja executado
    trocar = true;

    comparar = 0;
    qnt_troca = 0;
    tempo = 0.0;

    //Continue executando enquanto a lacuna é maior que 1 e a última iteração causou uma troca 
    while(gap != 1 || trocar == true){
        //Encontre a próxima lacuna 
        gap = getProximoGap(gap);

        //Inicialize trocado como falso para que possamos verificar se a troca aconteceu ou não
        trocar = false;
        troque = 0;

        //Compare todos os elementos com a lacuna atual
        for(int i = 0; i < N - gap; i++){
            if(vetor[i] > vetor[i + gap]){
                comparar += 1;
                swap(vetor[i], vetor[i + gap]);
                trocar = true;
                troque = 1;
                qnt_troca += troque;
            }
        }

        tempo = clock();
    }
}