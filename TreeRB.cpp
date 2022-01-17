#include <bits/stdc++.h>

#include "TreeRBNode.h"
#include "TreeRB.h"

using namespace std;

// Construtor:
TreeRB::TreeRB()
{
    root = new TreeRBNode();
    root->changeColor(); // Muda pra preto
    // nil.changeColor();   // Muda pra preto
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

    balanceTree(newNode, previous);


}

void TreeRB::balanceTree(TreeRBNode* r, TreeRBNode* previous)
{
    
    if(previous->getColor() == 1)   // pai é preto
        recolor(raise);
    else {  // pai é vermelho

        if(previous->getFather()->getLeftChild() ==  && previous->getLeftChild() == r)
        {

        }
        else if(previous->getLeftChild() == r)
        {

        }

    }
}

void TreeRB::recolor(TreeRBNode* r)
{
    TreeRBNode *father = r->getFather();
    TreeRBNode *grandfather = father->getFather();
    TreeRBNode *uncle;

    if (father->getLeftChild() == r)
        uncle = grandfather->getRightChild();
    else
        uncle = grandfather->getLeftChild();

    if (uncle->getColor() == 0) // tio é vermelho
    {
        uncle->changeColor();
        parent->changeColor();
        grandfather->changeColor();
    }
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

void TreeRB::rotateLeftSimple(TreeRBNode *p)
{
    // rotação simples à esquerda
    p = p->getParent();
    TreeRBNode *q;
    q = p->getRightSibling();
    p->setRightChild(q->getLeftSibling());
    q->setLeftChild(p);
}

void TreeRB::rotateLeftSimple(TreeRBNode *p)
{
    // rotação simples à direita
    p = p->getParent();
    TreeRBNode *q;
    q = p->getLeftSibling();
    p->setLeftChild(q->getRightSibling());
    q->setRightChild(p);
}

void TreeRB::rotateLeftDouble(TreeRBNode *p)
{
    // rotação dupla à esquerda
    r = r->getParent();
    TreeRBNode *q, *r;

    q = p->getRightSibling();
    r = q->getLeftSibling();

    p->setRightChild(r->getLeftSibling());
    q->setLeftChild(r->getRightSibling());

    r->setLeftChild(p);
    r->setRightChild(q);
}

void TreeRB::rotateRightDouble(TreeRBNode *p)
{
    // rotação dupla à direita
    r = r->getParent();
    TreeRBNode *q, *r;

    q = p->getLeftSibling();
    r = q->getRightSibling();

    p->setLeftChild(r->getRightSibling());
    q->setRightChild(r->getLeftSibling());

    r->setRightChild(p);
    r->setLeftChild(q);
}