#include <iostream>
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
        while (getline(arqEntrada, line))
        {
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

    cout << "Tiktok 1:" << endl;
    cout << tiktokVector[0].getReviewId() << endl;
    cout << tiktokVector[0].getReviewText() << endl;
    cout << tiktokVector[0].getUpvotes() << endl;
    cout << tiktokVector[0].getAppVersion() << endl;
    cout << tiktokVector[0].getPostedDate() << endl;
    cout << "--------" << endl;
}