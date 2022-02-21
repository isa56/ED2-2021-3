#ifndef TREERB_H_INCLUDED
#define TREERB_H_INCLUDED

#include <bits/stdc++.h>

#include "TreeRBNode.h"

using namespace std;

class TreeRB
{

private:
    TreeRBNode *root;
    void rotateLeft(TreeRBNode *r, TreeRBNode *pointer);
    void rotateRight(TreeRBNode *r, TreeRBNode *pointer);
    void balanceTree(TreeRBNode *&rootR, TreeRBNode *&r);
    TreeRBNode *insertNodeAux(TreeRBNode *father, TreeRBNode *pointer, int *comparacoes);

public:
    TreeRB();
    TreeRBNode *getRoot();
    void insertNode(string infoId, int infoPosition);
    TreeRBNode *findNode(string infoId);
    void printTree(TreeRBNode *r);
};

#endif