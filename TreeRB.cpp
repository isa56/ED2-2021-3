#include <bits/stdc++.h>

#include "TreeRBNode.h"
#include "TreeRB.h"

using namespace std;

// Construtor:
TreeRB::TreeRB()
{
    root = new TreeRBNode();
    root->changeColor(); // Muda pra preto
    nil.changeColor();   // Muda pra preto
    blackHeight = 0;
}

void TreeRB::insertNode(string infoId, int infoPosition)
{
    TreeRBNode newNode = new TreeRBNode();
    newNode.setInfo(infoId, infoPosition);

    TreeRBNode *r = root;

    while (r != null)
    {
        if (newNode.getInfoID() < r->getInfoID())
        {
            r = r->getLeftChild();
        }
        else
        {
            r = r->getRightChild();
        }
    }

    if(root == null)
    {
        root = newNode;
    }

    checkBalanceTree();

}

TreeRBNode *TreeRB::findNode(string infoId)
{
    TreeRBNode *r = root;

    while (r->getLeftSibling() != null || r->getRightSibling() != null)
    {
        if (infoId == r->getInfoId())
            return r;
        else if (infoId < r->getInfoId())
            r = r->getLeftSibling();
        else
            r = r->getRightSibling();
    }

    return null;
}

void TreeRB::checkBalanceTree()
{
}

void TreeRB::balanceTree()
{
}