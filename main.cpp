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
    char *buffer = new char[sizeof(Tiktok)]; //precisa receber o tamanho da linha

    fstream arquivoBin;

    arquivoBin.open("tiktok_app_reviews.bin", ios::in | ios::binary);

    arquivoBin.seekg(posicao * sizeof(Tiktok)); //posiciona o cursor no local indicado

    arquivoBin.read(buffer, sizeof(Tiktok));
    arquivoBin.close();

    cout.write(buffer, sizeof(Tiktok));
    delete[] buffer;
}

void testeImportacao()
{
    cout << "Escolha o metodo de teste: " << endl;
    cout << "Digite 1 para pesquisar uma linha" << endl;
    cout << "Digite 2 para imprimir na tela 10 itens" << endl;
    cout << "Digite 3 para salvar 100 itens num txt" << endl;
    cout << "Digite outro para sair" << endl;

    int numeroEscolhido;

    cin >> numeroEscolhido;
    fstream arquivoBin;

    switch (numeroEscolhido)
    {

    case 1:
        cout << "Digite a i-esima posicao que deseja acessar: " << endl;
        int linhaPesquisada;
        cin >> linhaPesquisada;
        acessaRegistro(linhaPesquisada);
        break;

    case 2:
        for (int i = 0; i < 10; i++)
        {
            int posicao = rand() % 10; // Numero de linhas do arquivo csv hardcoded (3660723)
            acessaRegistro(posicao);
        }
        break;

    case 3:
        char *buffer = new char[sizeof(Tiktok)];
        fstream arquivoBin;
        vector<string> tiktokVector;

        arquivoBin.open("tiktok_app_reviews.bin", ios::in | ios::binary);
        for (int i = 0; i < 100; i++)
        {
            int posicao = rand() % 10; // 3660723
            arquivoBin.seekg(posicao * sizeof(Tiktok));

            arquivoBin.read(buffer, sizeof(Tiktok));
            tiktokVector.push_back(buffer);
        }
        delete[] buffer;
        arquivoBin.close();

        std::fstream arqTeste;

        arqTeste.open("teste_importacao.txt", ios::out);

        for (int i = 0; i < tiktokVector.size(); i++)
        {
            arqTeste.write(
                (char *)&tiktokVector[i],
                tiktokVector.size() * sizeof(Tiktok));
        }
        arqTeste.close();
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
    for (int i = 0; i < tiktokVector.size(); i++) //trocar para tiktokVector.size()
    {
        string reviewIdAux = tiktokVector[i].getReviewId();
        string reviewTextAux = tiktokVector[i].getReviewText();
        int upvotesAux = tiktokVector[i].getUpvotes();
        string appVersionAux = tiktokVector[i].getAppVersion();
        string postedDateAux = tiktokVector[i].getPostedDate();

        arqSaida.write(reinterpret_cast<const char *>(reviewIdAux.c_str()), reviewIdAux.length());
        arqSaida.write(reinterpret_cast<const char *>(reviewTextAux.c_str()), reviewTextAux.length());
        arqSaida.write(reinterpret_cast<const char *>(&upvotesAux), sizeof(int));
        arqSaida.write(reinterpret_cast<const char *>(appVersionAux.c_str()), appVersionAux.length());
        arqSaida.write(reinterpret_cast<const char *>(postedDateAux.c_str()), postedDateAux.length());
    }

    arqSaida.close();
    testeImportacao();
}

//Duvidas:
//O arquivo bin agora está salvando corretamente entretanto as leituras do arquivo bin não estão
//funcionando corretamente. Isto está acontecendo, provavelmente, devido aos size_of usados dentro da 
//função "acessaRegistro" que estamos usando de forma incorreta, fazendo que somente pedaços pequenos das linhas 
//sejam capturados. Precisamos ver com o Caniato como fazer essa leitura de forma correta.