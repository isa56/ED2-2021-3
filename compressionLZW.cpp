#ifndef COMPRESSIONLZW_CPP_INCLUDED
#define COMPRESSIONLZW_CPP_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <initializer_list>
#include <unordered_map>
#include <bits/stdc++.h>

#include "compressionLZW.h"

using namespace std;

//Algumas coisas rodam apenas no C++ versão 11!!!!!!!!!
vector<int> codificar(string str)
{
    cout << "Codificando..." << endl;

    map<string, int> tabela; //Se utilizar o unordered_map, VSCode (?) não reconhece o tipo

    for(int i = 0; i <= 255; i++) {
        string ch = "";
        ch += char(i);
        tabela[ch] = i;
    }

    string p, c;
    p = "";
    c = "";

    p += str[0];

    int codigo;
    codigo = 256;

    vector<int> saida_codigo;

    cout << "String \t Saida de Codigo \t Adicionar" << endl;

    for(int i = 0; i < str.length(); i++) {
        if(i != str.length() - 1) {
            c += str[i + 1];
        }

        else if(tabela.find(p + c) != tabela.end()) {
            p = p + c;
        }

        else {
            cout << p << "\t" << tabela[p] << "\t\t" << p + c << "\t" << codigo << endl;
            saida_codigo.push_back(tabela[p]);

            tabela[p + c] = codigo;
            codigo++;
            p = c;
        }

        c = "";
    }

    cout << p << "\t" << tabela[p] << endl;
    saida_codigo.push_back(tabela[p]);

    return saida_codigo;
}

void decodificar(vector<int> op)
{
    cout << endl;
    cout << "Decodificando" << endl;

    map<int, string> tabela;

    for(int i = 0; i < 255; i++) {
        string str = "";
        str += char(i);
        tabela[i] = str;
    }

    int antigo = op[0];
    int n;

    string str = tabela[antigo];
    string c = "";

    c += str[0];
    cout << str << endl;

    int contar;
    contar = 256;

    for(int i = 0; i < op.size() - 1; i++) {
        n = op[i + 1];

        if(tabela.find(n) == tabela.end()) {
            str = tabela[antigo];
            str = str + c;
        }

        else {
            str = tabela[n];
        }

        cout << str << endl;

        c = "";
        c += str[0];
        tabela[contar] = tabela[antigo] + c;

        contar++;
        antigo = n;
    }
}

#endif