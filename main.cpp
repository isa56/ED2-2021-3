#include <bits/stdc++.h>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <sys/stat.h>
#include <algorithm>

// #include <filesystem>
#include "processamento.h"
#include "tiktok.h"
#include "TabelaHash.h"
#include "heapsort.h"
#include "quicksort.h"
#include "combsort.h"

// Parte 3:
#include "TreeRB.h"
#include "TreeB.h"

// Parte 4:
#include "compressaoHuffman.h"

// Contantes:
#define BINARY_NAME "tiktok_app_reviews.bin"
#define TEXT_NAME "teste_importacao.txt"
#define TXT_NAME_PART2 "teste.txt"
#define INPUT_NAME "input.dat"
#define STRING_MEDIUM_SIZE 320
#define LINES_CSV 3660723

using namespace std;

std::fstream arqEntrada;

void testaArvoreRubroNegra(vector<Tiktok> &tiktokVector)
{

    unsigned int N = 1000000;
    int B = 100;
    string reviewId;

    TreeRB *arvoreVP = new TreeRB();

    // Encontra reviews aleatórias e dá push:
    for (int i = 0; i < N; i++)
    {
        int posicao = rand() % LINES_CSV;
        reviewId = tiktokVector[posicao].getReviewId();
        arvoreVP->insertNode(reviewId, posicao);
    }

    arvoreVP->printTree(arvoreVP->getRoot());
}

void testaArvoreB(vector<Tiktok> &tiktokVector)
{

    unsigned int N = 1000000;
    int B = 100;
    string reviewId;

    TreeB *arvB = new TreeB(N);

    // Encontra reviews aleatórias e dá push:
    for (int i = 0; i < N; i++)
    {
        int posicao = rand() % LINES_CSV;
        reviewId = tiktokVector[posicao].getReviewId();
        arvB->inserir(posicao);
    }
    arvB->percorrer();

    int x;

    cout << "Digite 1 para procurar na arvore " << endl;
    cout << "Outro para sair " << endl;

    cin >> x;

    switch (x)
    {
    case 1:
        int procurar;
        cout << "Digite um numero de 0 a 100 para procurar na arvore => ";
        cin >> procurar;

        (arvB->buscar(procurar) != NULL) ? cout << "Esta na arvore!" : cout << "Ausente" << endl;
        break;
    }
}

void testeArvores(vector<Tiktok> &tiktokVector)
{
    cout << "Escolha uma Arvore para montar " << endl;
    cout << "Digite 1 para Arvore Rubro Negra" << endl;
    cout << "Digite 2 para Arvore B" << endl;
    cout << "Digite outro para sair" << endl;

    int numeroEscolhido;

    cin >> numeroEscolhido;

    switch (numeroEscolhido)
    {
    case 1:
        testaArvoreRubroNegra(tiktokVector);
        break;
    case 2:
        testaArvoreB(tiktokVector);
        break;
    default:
        break;
    }
}

void manipularHash(vector<Tiktok> &tiktokVector)
{

    int numReviews;
    int qtdImpressa;

    cout << "Digite o numero de Reviews que voce quer importar" << endl;
    cin >> numReviews;
    cout << "Digite o numero de impressoes que voce quer fazer" << endl;
    cin >> qtdImpressa;

    string appVersion;
    TabelaHash *tb = new TabelaHash();

    // Encontra reviews aleatórias e dá push:
    for (int i = 0; i < numReviews; i++)
    {
        int posicao = rand() % LINES_CSV;
        appVersion = tiktokVector[posicao].getAppVersion();
        tb->inserirItem(appVersion);
    }

    tb->imprimirTabela(qtdImpressa);
}

void acessarRegistro(int posicao)
{
    char *buffer = new char[STRING_MEDIUM_SIZE];

    fstream arquivoBin;

    arquivoBin.open(BINARY_NAME, ios::in | ios::binary);

    arquivoBin.seekg(posicao * STRING_MEDIUM_SIZE); // posiciona o cursor no local indicado

    arquivoBin.read(buffer, STRING_MEDIUM_SIZE);
    arquivoBin.close();

    cout.write(buffer, STRING_MEDIUM_SIZE);
    cout << endl;

    delete[] buffer;
}

void testarImportacao()
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
        acessarRegistro(linhaPesquisada);
        break;

    case 2:
        for (int i = 0; i < 10; i++)
        {
            int posicao = rand() % LINES_CSV; // Numero de linhas do arquivo csv hardcoded (3660723)
            acessarRegistro(posicao);
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

void seqCompressoes(vector<Tiktok> &tiktokVector)
{
    char *buffer = new char[LINES_CSV];
    string textToWrite = "";

    int N, M; // sequencia de compressoes
    std::fstream arqTesteCompressao;
    int comparacoes10k, comparacoes100k, comparacoes1m;
    int taxaComp10k, taxaComp100k, taxaComp1m;

    arqTesteCompressao.open(TEXT_NAME, ios::out);

    /*
    cout << "Digite a quantidade de compressoes que precisa fazer => " << endl;
    cin >> N;
    */
    cout << "Digite a quantidade de testes a rodar => ";
    cin >> M;

    if (M < 3)
        M = 3;

    for (int i = 0; i < M; i++)
    {

        cout << "Iniciando o processamento para M = " << i << endl;

        // Primeiro teste, N = 10000
        N = 10000;
        preprocessaCompressao(tiktokVector, N);
        // Computa dados

        // Segundo teste, N = 100000
        N = 100000;
        preprocessaCompressao(tiktokVector, N);

        // Terceiro teste, N = 1000000
        N = 1000000;
        preprocessaCompressao(tiktokVector, N);

        textToWrite.append("M").append(to_string(i)).append(" :\n");
        textToWrite.append("N = 10000 - Comparacoes: ").append(to_string(comparacoes10k)).append("\nTaxa de Compressão: ").append(to_string(taxaComp10k));
        textToWrite.append("\nN = 100000\nComparacoes: ").append(to_string(comparacoes100k)).append("\nTaxa de Compressão: ").append(to_string(taxaComp100k));
        textToWrite.append("\nN = 1000000\nComparacoes: ").append(to_string(comparacoes1m)).append("\nTaxa de Compressão: ").append(to_string(taxaComp1m));

        arqTesteCompressao.write(textToWrite.c_str(), textToWrite.length() * sizeof(char));
        
        cout << textToWrite << endl;
    }

    cout << "Escrita terminada!" << endl;

    arqTesteCompressao.close();
}

int preprocessaCompressao(vector<Tiktok> &tiktokVector, int numReviews)
{

    int contador = 0, numComparacoes;
    string txt;
    char dados[52];
    int frequencias[52];
    vector<string> reviewTexts;

    for (int i = 0; i < numReviews; i++)
    {
        int posicao = rand() % LINES_CSV; // 3660723

        txt = tiktokVector[i].getReviewText();

        for (int j = 0; j < txt.length(); j++)
        {
            if (dados.find(txt.at(j)) == std::string::npos)
            {
                frequencias[contador] = count(txt.begin(), txt.end(), txt.at(j));
                dados[contador] = txt.at(j);
                contador++;
            }
        }
        reviewTexts.push_back(txt);
    }

    numComparacoes = codigosHuffman(dados, frequencias, contador);
    return numComparacoes;
}

int main(int argc, char const *argv[])
{
    // Code Protection: Numero de parametros insuficiente
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

    // Leitura do arquivo csv:
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
        for (int i = 0; i < tiktokVector.size(); i++) // trocar para tiktokVector.size()
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
    int escolheSort;
    int *sortingArray;
    int numDados, numInstancias, numConjuntos;
    int decisao = 0;
    /*
        // Chamada da função de teste:
        while (continuar == 1)
        {

            cout << "Digite 1 se quiser testar a Tabela Hash ou 2 se quiser testar a Ordenacao" << endl;

            cin >> decisao;

            switch (decisao)
            {
            case 1:
                manipularHash(tiktokVector);
                break;
            case 2:
                cout << "Digite 1 para testar o heapsort, 2 para o quicksort, 3 para o combsort e outro para sair" << endl;
                cin >> escolheSort;

                cout << "Digite o numero de conjuntos distintos de N que serao realizados (minimo 3)" << endl;
                cin >> numConjuntos;

                while (numConjuntos < 3)
                {
                    cout << "Numero invalido! Digite um numero maior que 3." << endl;
                    cin >> numConjuntos;
                }

                if (escolheSort == 1)
                {
                    for (int i = 0; i < numConjuntos; i++)
                    {
                        cout << "Digite quantos dados devem ser pre processados: " << endl;
                        cin >> numDados;
                        sortingArray = preprocessar(tiktokVector, numDados);
                        heapsort(sortingArray, numDados);
                    }
                }
                else if (escolheSort == 2)
                    for (int i = 0; i < numConjuntos; i++)
                    {
                        cout << "Digite quantos dados devem ser pre processados: " << endl;
                        cin >> numDados;
                        sortingArray = preprocessar(tiktokVector, numDados);
                        ordenacaoQuickSort(sortingArray, 0, numDados);
                    }
                else if (escolheSort == 3)
                {
                    for (int i = 0; i < numConjuntos; i++)
                    {
                        cout << "Digite quantos dados devem ser pre processados: " << endl;
                        cin >> numDados;
                        sortingArray = preprocessar(tiktokVector, numDados);
                        ordCombSort(sortingArray, numDados);
                    }
                }

                break;
            }
            // testarImportacao();

            cout << "Digite 1 se deseja continuar a fazer testes e qualquer outro valor se deseja parar" << endl;
            cin >> continuar;
        }
        */

    int continuarComp;
    continuarComp = 1;

    int decisaoComp;
    decisaoComp = 0;

    int *tam, freq;
    char *Tiktok;

    cout << "Qual eh o tamanho da compreesao desejada? ";
    cin >> *tam;

    cout << "E qual a frequencia? ";
    cin >> freq;

    int numReviews;

    while (continuarComp == 1)
    {

        cout << "Digite 1 se quiser comprimir um conjunto, 2 se quiser descomprimir o arquivo ou 3 para teste" << endl;

        cin >> decisaoComp;

        switch (decisaoComp)
        {
        case 1:
            cout << "Digite o numero de reviews que deseja importar: ";
            cin >> numReviews;
            preprocessaCompressao(tiktokVector, numReviews);
            break;
        case 2:
            // Descomprimir o arquivo binário
            break;
        case 3:
            seqCompressoes(tiktokVector);
            break;
        }

        cout << "Digite 1 se deseja continuar a fazer compressoes, descompressões e testes, e qualquer outro valor se deseja parar" << endl;
        cin >> continuarComp;
    }

    // testeArvores(tiktokVector);
}