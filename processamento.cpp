#include <vector>
#include <sstream>

#include "tiktok.h"
#include "processamento.h"

#define SORT_SAIDA "arquivosaida.txt"

int *preprocessar(vector<Tiktok> tiktokvector, int numDados)
{
    int *sortingArray = new int[numDados];

    for (int i = 0; i < numDados; i++)
    {
        int randNumber = rand() % 3660723; // Numero de linhas do arquivo csv hardcoded (3660723)
        sortingArray[i] = tiktokvector[randNumber].getUpvotes();
    }

    return sortingArray;
}

double *salvarDadosRun(int comparacoes, int trocas, double tempo)
{
    double dadosDaRun[3];
 
    dadosDaRun[0] = comparacoes;
    dadosDaRun[1] = trocas;
    dadosDaRun[2] = tempo;
    
    return dadosDaRun;
}


/*
void insereTxt(int vetor[]) // faz a inserção dos elementos do vetor no txt
{
    std::fstream arqSaida;

    arqSaida.open(SORT_SAIDA, ios::out);

    // Code protection pro txt:
    if (!arqSaida.is_open())
    {
        cout << "Impossivel abrir o arquivo de saída!" << endl;
        exit(-2);
    }

    for (int i = 0; i < vetor.size(); i++)
    {
        arqSaida.write(reinterpret_cast<const char *>(&vetor[i]), sizeof(int));
    }

    arqSaida.close();
}
*/