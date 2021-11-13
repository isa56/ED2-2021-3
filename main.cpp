#include <bits/stdc++.h>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "tiktok.h"

using namespace std;

std::fstream arqEntrada;

int main(int argc, char const *argv[])
{
    //code protection: Numero de parametros insuficiente
    if (argc != 2)
    {
        cout << "Erro! Os seguintes parametros eram esperados ./<nome do executavel> <arquivo de entrada>" << endl;
        return 0;
    }

    arqEntrada.open(argv[1], ios::in); // Leitura do Arquivo de Entrada

    if (!arqEntrada)
    {
        cout << "Impossivel abrir o arquivo de entrada!" << endl;
        exit(-1);
    }

    //Leitura do arquivo csv:
    string reviewId;
    string reviewText;
    string upvotes;
    string appVersion;
    string postedDate;

    vector<Tiktok> tiktokVector;
    string line;

    if (arqEntrada.is_open())
    {
        // Loop para ler e armazenar cada linha em um elemento do tiktokVector:
        while (getline(arqEntrada, line))
        {
            // Ver se a linha está vazia:
            if (line == "")
            {
                continue;
            }
            else
            {
                istringstream dataFromLine(line);
                getline(dataFromLine, reviewId, ',');
                getline(dataFromLine, reviewText, ',');
                getline(dataFromLine, upvotes, ',');
                getline(dataFromLine, appVersion, ',');
                getline(dataFromLine, postedDate, ',');
                Tiktok auxiliar(reviewId, reviewText, atoi(upvotes.c_str()), appVersion, postedDate);
                tiktokVector.push_back(auxiliar);

                //TODO: deletar auxiliar?
            }
        }
        arqEntrada.close();
    }

    // Impressão de teste:
    for(int j = 0; j<5; j++){
        cout << "Tiktok " << j << ":" << endl;
        cout << tiktokVector[j].getReviewId() << endl;
        cout << tiktokVector[j].getReviewText() << endl;
        cout << tiktokVector[j].getUpvotes() << endl;
        cout << tiktokVector[j].getAppVersion() << endl;
        cout << tiktokVector[j].getPostedDate() << endl;
        cout << "--------" << endl;
    }
}