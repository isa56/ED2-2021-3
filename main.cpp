#include <bits/stdc++.h>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "tiktok.h"

using namespace std;

std::fstream arqEntrada;

void acessaRegistro(int posicao)
{
    char *buffer = new char[sizeof(Tiktok)];

    fstream arquivoBin;

    arquivoBin.open("tiktok_app_reviews.bin", ios::in | ios::binary);

    arquivoBin.seekg(posicao * sizeof(Tiktok));

    arquivoBin.read(buffer, sizeof(Tiktok));
    arquivoBin.close();

    cout.write(buffer, sizeof(Tiktok));
    delete[] buffer;
}

void testeImportacao()
{
    cout << "Escolha o metodo de teste: " << endl;
    cout << "Digite 1 para imprimir na tela 10 itens" << endl;
    cout << "Digite 2 para salvar 100 itens num txt" << endl;
    cout << "Digite 0 para sair" << endl;

    int numeroEscolhido;

    cin >> numeroEscolhido;
    fstream arquivoBin;

    switch (numeroEscolhido)
    {

    case 1:
        char *buffer = new char[sizeof(Tiktok)];

        arquivoBin.open("tiktok_app_reviews.bin", ios::in | ios::binary);

        for (int i = 0; i < 10; i++)
        {
            
            int posicao = rand()%sizeof(Tiktok);
            arquivoBin.seekg(posicao * sizeof(Tiktok));

            arquivoBin.read(buffer, sizeof(Tiktok));

            cout.write(buffer, sizeof(Tiktok));
            delete[] buffer;
        }

        arquivoBin.close();
        break; // prints "1",
    case 2:

        break;
    }
}

int main(int argc, char const *argv[])
{
    //Code Protection: Numero de parametros insuficiente
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

    Tiktok auxiliar;

    vector<Tiktok> tiktokVector;
    string linha;

    if (arqEntrada.is_open())
    {
        // Loop para ler e armazenar cada linha em um elemento do tiktokVector:
        while (getline(arqEntrada, linha))
        {
            // Ver se a linha está vazia:
            if (linha == "")
            {
                continue;
            }
            else
            {
                // Setta stream de input:
                istringstream dadosDaLinha(linha);

                // Faz o getline de cada linha, usando o separador ',':
                getline(dadosDaLinha, reviewId, ',');
                getline(dadosDaLinha, reviewText, ',');
                getline(dadosDaLinha, upvotes, ',');
                getline(dadosDaLinha, appVersion, ',');
                getline(dadosDaLinha, postedDate, ',');

                // Setta usando a função auxiliar:
                auxiliar.setDados(reviewId, reviewText, atoi(upvotes.c_str()), appVersion, postedDate);

                // Usando o vector:
                tiktokVector.push_back(auxiliar);
            }
        }
        arqEntrada.close();
    }

    // Impressão de teste:
    // for (int j = 0; j < 5; j++)
    // {
    //     cout << "Tiktok " << j << ":" << endl;
    //     cout << tiktokVector[j].getReviewId() << endl;
    //     cout << tiktokVector[j].getReviewText() << endl;
    //     cout << tiktokVector[j].getUpvotes() << endl;
    //     cout << tiktokVector[j].getAppVersion() << endl;
    //     cout << tiktokVector[j].getPostedDate() << endl;
    //     cout << "--------" << endl;
    // }

    // Tamanho da tabela
    int tamTabela = tiktokVector.size();

    // Saída:
    std::fstream arqSaida;

    arqSaida.open("tiktok_app_reviews.bin", ios::out | ios::binary);

    // Code protection pro arquivo de saída:
    if (!arqSaida.is_open())
    {
        cout << "Impossivel abrir o arquivo de saída!" << endl;
        exit(-2);
    }

    // Gravar cada objeto do tiktokVector no binário:
    for (int i = 0; i < 10; i++)
    {
        arqSaida.write(
            (char *)&tiktokVector[i],
            tamTabela * sizeof(Tiktok));
    }
    arqSaida.close();

    int linhaPesquisada;

    cout << "Digite a i-esima posicao que deseja acessar: " << endl;
    cin >> linhaPesquisada;

    acessaRegistro(linhaPesquisada);
}