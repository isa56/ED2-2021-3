#ifndef TREERB_H_INCLUDED
#define TREERB_H_INCLUDED

#include <bits/stdc++.h>

#include "TreeRBNode.h"

using namespace std;

class TreeRB
{

private:
    TreeRBNode *root;
    int blackHeight;
    void recolor(TreeRBNode *r);
    void rotateLeftSimple(TreeRBNode *r);
    void rotateRightSimple(TreeRBNode *r);
    void rotateLeftDouble(TreeRBNode *r);
    void rotateRightDouble(TreeRBNode *r);

    public : TreeRB();
    void insertNode(string infoId, int infoPosition);
    TreeRBNode *findNode(string infoId);
}

#endif