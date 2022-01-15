#include <bits/stdc++.h>

#include "TreeRB.h"

using namespace std;

// Construtor:
TreeRB::TreeRB()
{
    root = new TreeRBNode();
    root->changeColor();
    blackHeight = 0;
}

void TreeRB::insertNode(string infoId, int infoPosition)
{
}

TreeRBNode* TreeRB::findNode(string infoId)
{
    TreeRBNode *r = root;

    while (r->getLeftSibling() != null || r->getRightSibling() != null)
    {
        if(infoId == r->getInfoId())
            return r;
        else if (infoId < r->getInfoId())
            r = r->getLeftSibling();
        else
            r = r->getRightSibling();
    }

    return null;

}

void TreeRB::balanceTree()
{

}