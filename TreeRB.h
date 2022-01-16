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
    TreeRBNode nil;
    int blackHeight;
    void balanceTree(TreeRBNode *r);
    boolean checkProperties(TreeRBNode *r);

    // Métodos:
public:
    TreeRB();
    void insertNode(string infoId, int infoPosition);
    TreeRBNode *findNode(string infoId);
}

#endif