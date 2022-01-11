#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <sys/stat.h>
#include <algorithm>

#include "TreeBNo.h" //incluindo o '.h' do Nó da Árvore B
#include "TreeB.h" //incluindo o '.h' da Árvore B

using namespace std;

//Construtor da árvore B
TreeB::TreeB(int grau)
{
    //inicializa a árvore vazia
    raiz = NULL;
    t = grau;
}

//Construtor do nó da árvore B
TreeBNo::TreeBNo(int t1, bool folha1)
{
    //Copia o grau mínimo fornecido e a folha
    t = t1;
    folha = folha1;

    //Aloca memória para o número máximo de chaves
    //E ponteiros filhos possíveis
    chave = new int[2 * t - 1];
    C = new TreeBNo *[2 * t];

    //Inicialize o número de chaves como 
    n = 0;
}

//Função para percorrer todos os nós em uma subárvore com raiz neste nó
void TreeBNo::percorrer()
{
    //Exitem n chaves e n+1 filhos
    //Percorra n chaves e os primeiros n filhos
    int i;

    for(i = 0; i < n; i++){
        //Se não for folha, antes de imprimir k[i]
        //percorra a subárvore com filho C[i]
        if(folha == false){
            C[i]->percorrer();
        }
        cout << " " << chave[i];
    }


    //Imprima a subárvore enraizada no último filho
    if(folha == false){
        C[i]->percorrer();
    }
}

//Função para pesquisar a chave k
TreeBNo *TreeBNo::procurar(int k)
{
    //Encontre a primeira chave maior ou igual a k
    int i;
    i = 0;

    while(i < n && k > chave[i]){
        i++;
    }

    //Se a chave encontrada for igual a k
    //retorne esse nó
    if(chave[i] == k){
        return this;
    }

    //Se a chave não for encontrada aqui
    //E este for um nó folha
    if(folha == true){
        return NULL;
    }

    //Vá para o filho apropriado
    return C[i]->procurar(k);
}

void TreeB::inserir(int k)
{
    //Se a árvore estiver vazia
    if(raiz == NULL){
        //Alocar memória para raiz
        raiz = new TreeBNo(t, true);
        raiz->chave[0] = k; //insere chave
        raiz->n = 1; //Atualizar número de chaves na raiz
    }
    else //Se a árvore não estiver vazia
    {
        //Se a raiz está cheia
        //Então a árvore cresce em altura
        if(raiz->n == 2*t-1){
            //Alocar memória para a nova raiz
            TreeBNo *s = new TreeBNo(t, false);

            //Tornar a raiz antiga como filho da nova raiz
            s->C[0] = raiz;

            //Divida a raiz antiga e mova uma chave para a nova raiz
            s->dividirFilho(0, raiz);

            //A nova raiz tem dois filhos
            //Decidir qual das duas folhas
            //Terá uma nova chave
            int i = 0;
            if(s->chave[0] < k){
                i++;
            }
            s->C[i]->inserirNaoCheia(k);

            //Alterar raiz
            raiz = s;
        }
        else //Se raiz não tiver cheio, chame a função inserirNaoCheia
        {
            raiz->inserirNaoCheia(k);
        }
    }
}

//Função para inserir uma nova chave no nó
//O nó não deve está cheia quando a função deve ser chamada
void TreeBNo::inserirNaoCheia(int k)
{
    //Inicialize o índice como índice do elemento mais à direita
    int i;
    i = n - 1;

    //Se este for um nó folha
    if(folha == true){
        //O loop faz duas coisas:
        //1) Encontra a localização da nova chave a ser inserida 
        //2) Moves all greater keys to one place ahead
        while(i >= 0 && chave[i] > k){
            chave[i + 1] = chave[i];
            i--;
        }

        //Insira a nova chave no local encontrado
        chave[i +  1] = k;
        n = n + 1; 
    }
    else //Se este nó não for folha 
    {
        //Encontre o filho que vai ter a nova chave
        while (i >= 0 && chave[i] > k)
        {
            i--;
        }

        //Veja se o filho encontrado está cheio
        if(C[i + 1]->n == 2*t-1){
            //Se o filho estiver cheia, divida-a
            dividirFilho(i + 1, C[i + 1]);

            //Após a divisão, o filho do meio de C[i] sobre
            //C[i] é dividido em dois
            //Veja qual dos dois vai ter a nova chave
            if(chave[i + 1] < k){
                i++;
            }
        }
        C[i + 1]->inserirNaoCheia(k);
    }
}

void TreeBNo::dividirFilho(int i, TreeBNo *y)
{
    //Crie um novo nó que irá armazenar
    //(t - 1) chaves de y
    TreeBNo *z = new TreeBNo(y->t, y->folha);
    z->n = t - 1;

    //Copie as últimas (t - 1) chaves de y para z
    for(int j = 0; j < t - 1; j++){
        z->chave[j] = y->chave[j + t];
    }

    //Copie os últimos t filhos de y para z
    if(y->folha == false){
        for(int j = 0; j < t; j++){
            z->C[j] = y->C[j + t];
        }
    }

    //Reduza o número de chaves em y
    y->n = t - 1;

    //Como este nó terá um novo filho
    //Crie um espaço para o novo filho
    for(int j = n; j >= i + 1; j--){
        C[j + 1] = C[j];
    }

    //Vincule o novo filho a este nó
    C[i + 1] = z;

    //Uma chave de y moverá para este nó
    //Encontre a localização da nova chave
    //E mova todas as chaves maiores um espaço à frente
    for(int j = n - 1; j >= i; j--){
        chave[j + 1] = chave[j];
    }

    //Copie a chave do meio de y para este nó
    chave[i] = y->chave[t - 1];

    //Incrementar a contagem de chaves neste nó
    n = n + 1;
}