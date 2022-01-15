#ifndef TREERB_H_INCLUDED
#define TREERB_H_INCLUDED

#include <bits/stdc++.h>

#include "TreeRBNode.h"

using namespace std;

class TreeRB
{
    // Atributos:
private:
    TreeRBNode *root;
    int blackHeight;
    void balanceTree();

    // Métodos:
public:
    TreeRB();
    void insertNode(string infoId, int infoPosition);
    void findNode(string infoId);
}

#endif