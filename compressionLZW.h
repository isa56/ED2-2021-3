#ifndef COMPRESSIONLZW_H_INCLUDED
#define COMPRESSIONLZW_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <initializer_list>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

vector<int> codificar(string str);
void decodificar(vector<int> op);

#endif