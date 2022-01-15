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

void TreeRB::findNode(string infoId)
{
    TreeRBNode *r = root;

    while (r->getLeftSibling() != null || r->getRightSibling() != null)
    {
        
    }
}

void TreeRB::balanceTree()
{

}