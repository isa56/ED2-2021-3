#include <bits/stdc++.h>
#include "descompressaoHuffman.h"

#define TAMANHO_MAX_ARVORE 256
using namespace std;
  
// armazenar seu valor huffman
map<char, string> codes;
  
// armazenar a frequencia do caractere inserido
map<char, int> freq;


  
// imprime o valor junto de seu valor de huffman
void imprimeCodigo(struct NoHeapMinimo* raiz, string str)
{
    if (!raiz)
        return;
    if (raiz->dado != '$')
        cout << raiz->dado << ": " << str << "\n";
    imprimeCodigo(raiz->esquerda, str + "0");
    imprimeCodigo(raiz->direita, str + "1");
}
  

void armazenaCodigos(struct NoHeapMinimo* raiz, string str)
{
    if (raiz==NULL)
        return;
    if (raiz->dado != '$')
        codes[raiz->dado]=str;
    armazenaCodigos(raiz->esquerda, str + "0");
    armazenaCodigos(raiz->direita, str + "1");
}
  
// armazena arvore heap de acordo com a ordem de prioridade
priority_queue<NoHeapMinimo*, vector<NoHeapMinimo*>, comparar> minHeap;
  

void MontaArvoreHuffman(int size)
{
    struct NoHeapMinimo *left, *right, *top;
    for (map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++)
        minHeap.push(new NoHeapMinimo(v->first, v->second));
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new NoHeapMinimo('$', left->frequencia + right->frequencia);
        top->esquerda = left;
        top->direita = right;
        minHeap.push(top);
    }
    armazenaCodigos(minHeap.top(), "");
}
  

void calculaFrequencia(string str, int n)
{
    for (int i=0; i<str.size(); i++)
        freq[str[i]]++;
}
  

string descompressao(struct NoHeapMinimo* raiz, string s)
{
    string str = "";
    struct NoHeapMinimo* curr = raiz;
    for (int i=0;i<s.size();i++)
    {
        if (s[i] == '0')
           curr = curr->esquerda;
        else
           curr = curr->direita;
  
        // reached leaf node
        if (curr->esquerda==NULL and curr->direita==NULL)
        {
            str += curr->dado;
            curr = raiz;
        }
    }
    // cout<<str<<endl;
    return str+'\0';
}
  
/*int main()
{
    string str = "testeDescompressao";
    string StringCompressa, StringDescompressa;
    calculaFrequencia(str, str.length());
    MontaArvoreHuffman(str.length());
    cout << "Caractere com as frequencias:\n";
    for (auto v=codes.begin(); v!=codes.end(); v++)
        cout << v->first <<' ' << v->second << endl;
  
    for (auto i: str)
        StringCompressa+=codes[i];
  
    cout << "\nDados compressos:\n" << StringCompressa << endl;
  
    StringDescompressa = descompressao(minHeap.top(), StringCompressa);
    cout << "\nDados decompressos:\n" << StringDescompressa << endl;
    return 0;
}*/