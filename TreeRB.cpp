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
    TreeRBNode *previous = null;

    // Encontrar posição:
    while (r != null)
    {
        previous = r;
        if (newNode.getInfoID() < r->getInfoID())
        {
            r = r->getLeftChild();
        }
        else
        {
            r = r->getRightChild();
        }
    }

    // Inserir:
    if (root == null)
    {
        root = newNode;
    }
    else if (infoId < previous->getInfoId())
    {
        previous->setLeftChild(newNode);
    }
    else
    {
        previous->setRightChild(newNode);
    }

    if (!checkProperties(newNode))
        balanceTree(newNode);
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

boolean TreeRB::checkProperties(TreeRBNode *r)
{
    // Propriedade 1 ok
    // Propriedade 2: A raiz é preta
    if (root->getColor() != 1)
        return false;

    // Propriedade 3 ok
    // Propriedade 4: Se um nó é vermelho, seus filhos são pretos
    TreeRBNode father = r->getFather();
    if (father.getColor() == 0) // pai é vermelho, como r foi inserido agora, também é vermelho
        return false;

    // Propriedade 5
    return true;
}

void TreeRB::balanceTree(TreeRBNode *r)
{
    // rotação simples à esquerda
    r = r->getParent();
    TreeRBNode *q;
    q = p->getRightSibling();
    p->setRightChild(q->getLeftSibling());
    q->setLeftChild(p);
}