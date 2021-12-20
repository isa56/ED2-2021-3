#include <vector>
#include "tiktok.h"

int *preprocessar(vector<Tiktok> tiktokvector, int numDados)
{   
    int *sortingArray = new int[numDados];

    for (int i = 0; i < numDados; i++)
        ;
    {
        int randNumber = rand() % 3660723; // Numero de linhas do arquivo csv hardcoded (3660723)
        sortingArray[i] = tiktokvector[randNumber].getUpvotes();
    }

    return sortingArray;
}