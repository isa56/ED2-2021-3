#include <bits/stdc++.h>
#include <vector>
#include <fstream>

#include "processamento.h"
#include "tiktok.h"

#define SORT_SAIDA "saida.txt"

using namespace std;

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

