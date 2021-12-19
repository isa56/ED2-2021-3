#include <bits/stdc++.h>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <sys/stat.h>
#include <algorithm>

// #include <filesystem>

// #include "heapsort.cpp"
#include "tiktok.h"
#include "heapsort.cpp"
#include "quicksort.cpp"
#include "TabelaHash.h"

// Contantes:
#define BINARY_NAME "tiktok_app_reviews.bin"
#define TEXT_NAME "teste_importacao.txt"
#define TXT_NAME_PART2 "teste.txt"
#define STRING_MEDIUM_SIZE 320
#define LINES_CSV 3660723

using namespace std;

std::fstream arqEntrada;

void acessaRegistro(int posicao)
{
    char *buffer = new char[STRING_MEDIUM_SIZE];

    fstream arquivoBin;

    arquivoBin.open(BINARY_NAME, ios::in | ios::binary);

    arquivoBin.seekg(posicao * STRING_MEDIUM_SIZE); //posiciona o cursor no local indicado

    arquivoBin.read(buffer, STRING_MEDIUM_SIZE);
    arquivoBin.close();

    cout.write(buffer, STRING_MEDIUM_SIZE);
    cout << endl;

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
            int posicao = rand() % LINES_CSV; // Numero de linhas do arquivo csv hardcoded (3660723)
            acessaRegistro(posicao);
        }
        break;

    case 3:
        char *buffer = new char[LINES_CSV];
        fstream arquivoBin;
        vector<string> tiktokVector;

        arquivoBin.open(BINARY_NAME, ios::in | ios::binary);
        for (int i = 0; i < 100; i++)
        {
            int posicao = rand() % LINES_CSV; // 3660723
            arquivoBin.seekg(posicao * STRING_MEDIUM_SIZE);

            arquivoBin.read(buffer, STRING_MEDIUM_SIZE);
            tiktokVector.push_back(buffer);
        }
        delete[] buffer;
        arquivoBin.close();

        std::fstream arqTeste;

        arqTeste.open(TEXT_NAME, ios::out);

        for (int i = 0; i < tiktokVector.size(); i++)
        {
            arqTeste.write(
                (char *)&tiktokVector[i], tiktokVector.size() * STRING_MEDIUM_SIZE);
        }
        arqTeste.close();
        break;
    }
}

void manipulaHash(vector<Tiktok> tiktokVector)
{

    int numReviews;
    int qtdImpressa;

    cout << "Digite o número de Reviews que você quer importar" << endl;
    cin >> numReviews;
    cout << "Digite o número de impressões que você quer fazer" << endl;
    cin >> qtdImpressa;

    string appVersion;
    TabelaHash tb;

    // Encontra reviews aleatórias e dá push:
    for (int i = 0; i < numReviews; i++)
    {
        int posicao = rand() % LINES_CSV;
        appVersion = tiktokVector[posicao].getAppVersion();
        tb.inserirItem(appVersion);
    }

    tb.imprimirTabela(qtdImpressa);
}

/*
void ordenacaoQuickSort(int vetor[], int a, int b)
{
    if (a < b)
    {

        int indiceParticionamento = particionamentoQuickSort(vetor, a, b);

        // Faz o sort dos elementos em separado, de cada partição
        ordenacaoQuickSort(vetor, a, indiceParticionamento - 1);
        ordenacaoQuickSort(vetor, indiceParticionamento + 1, b);
    }
}

int particionamentoQuickSort(int vetor[], int a, int b)
{
    int pivo = vetor[b]; // pivô
    int i = (a - 1);     // Índice do elemento menor

    for (int j = a; j <= b - 1; j++)
    {
        //Se o elemento atual é menor ou igual ao pivô
        if (vetor[j] <= pivo)
        {
            i++; // aumenta o índice do elemento menor
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i + 1], &vetor[b]);
    return (i + 1);
}

void troca(int *e1, int *e2)
{
    int t = *e1;
    *e1 = *e2;
    *e2 = t;
}
*/
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
    vector<string> tamanhoAux;
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

    struct stat buf;

    if (!(stat(BINARY_NAME, &buf) != -1))
    {

        // Saída:
        std::fstream arqSaida;

        arqSaida.open(BINARY_NAME, ios::out | ios::binary);

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
    }

    cout << endl;

    int continuar = 1;

    // Chamada da função de teste:
    while (continuar == 1)
    {

        int decisao = 0;

        cout << "Digite 1 se quiser testar a Tabela Hash, 2 se quiser testar a Ordenação e 3 se quiser acessar o Módulo de Teste" << endl;

        switch (decisao)
        {
        case 1:
            manipulaHash(tiktokVector);
            break;
        case 2:
            // chama função que coordena as Ordenações
            break;
        case 3:
            // chama a função de Módulo de Teste
            break;
        }
        // testeImportacao();
        cout << "Digite 1 se deseja continuar a fazer testes e qualquer outro valor se deseja parar" << endl;
        cin >> continuar;
    }
}