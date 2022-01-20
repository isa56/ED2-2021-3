#include <bits/stdc++.h>


#include "TreeRB.h"

using namespace std;

// Construtor:
TreeRB::TreeRB()
{
    cout << "Criando Arvore Rubro-Negra..." << endl;
    root = new TreeRBNode();
    root->changeColor(); // Muda pra preto
}

TreeRBNode *TreeRB::getRoot() { 
    return root;
}

TreeRBNode *TreeRB::insertNodeAux(TreeRBNode *father, TreeRBNode *pointer)
{
    if(father == NULL)
        return pointer;
    
    if(pointer->getInfoID() < father->getInfoID())
    {
        father->setLeftChild( insertNodeAux(father->getLeftChild(), pointer) );
        father->getLeftChild()->setFather( father );
    }
    else if (pointer->getInfoID() > father->getInfoID())
    {
        father->setRightChild( insertNodeAux(father->getRightChild(), pointer) );
        father->getRightChild()->setFather( father );
    }

    return root;

}

void TreeRB::insertNode(string infoId, int infoPosition)
{
    cout << "Inserindo No..." << endl;

    TreeRBNode *newNode = new TreeRBNode(infoId, infoPosition);

    root = insertNodeAux(root, newNode);

    balanceTree(root, newNode);
}

void TreeRB::balanceTree(TreeRBNode *&rootR, TreeRBNode *&r)
{

    TreeRBNode *father = NULL;
    TreeRBNode *grandfather = NULL;

    while ((r != root) && (r->getColor() != 1) && (r->getFather()->getColor() == 0))
    {

        father = r->getFather();
        grandfather = father->getFather();

        if (father == grandfather->getLeftChild())
        {

            TreeRBNode *uncle = grandfather->getRightChild();

            if (uncle != NULL && uncle->getColor() == 0)
            {
                grandfather->setColor(0);
                father->setColor(1);
                uncle->setColor(1);
                r = grandfather;
            }
            else
            {

                if (r == father->getRightChild())
                {
                    rotateLeft(rootR, father);
                    r = father;
                    father = r->getFather();
                }

                rotateRight(rootR, grandfather);
                father->changeColor();
                grandfather->changeColor();
                r = father;
            }
        }
        else
        {

            TreeRBNode *uncle = grandfather->getLeftChild();

            if ((uncle != NULL) && uncle->getColor() != 0)
            {
                grandfather->changeColor();
                father->changeColor();
                uncle->changeColor();
                r = grandfather;
            }
            else
            {

                if (r == father->getLeftChild())
                {
                    rotateRight(rootR, father);
                    r = father;
                    father = r->getFather();
                }

                rotateLeft(rootR, grandfather);
                father->changeColor();
                grandfather->changeColor();

                r = father;
            }
        }
    }

    root->setColor(1);
}

TreeRBNode *TreeRB::findNode(string infoId)
{
    TreeRBNode *r = root;

    while (r->getLeftChild() != NULL || r->getRightChild() != NULL)
    {
        if (infoId == r->getInfoID())
            return r;
        else if (infoId < r->getInfoID())
            r = r->getLeftChild();
        else
            r = r->getRightChild();
    }

    return NULL;
}

void TreeRB::rotateLeft(TreeRBNode *rootR, TreeRBNode *pointer)
{
    // rotação simples à esquerda
    TreeRBNode *pointerRight = pointer->getRightChild();

    pointer->setRightChild(pointerRight->getLeftChild());

    if (pointer->getRightChild() != NULL)
    {
        pointer->getRightChild()->setFather(pointer);
    }

    pointerRight->setFather(pointer->getFather());

    if (pointer->getFather() == NULL)
    {
        rootR = pointerRight;
    }
    else if (pointer == pointer->getFather()->getLeftChild())
    {
        pointer->getFather()->setLeftChild(pointerRight);
    }
    else
    {
        pointer->getFather()->setRightChild(pointerRight);
    }

    pointerRight->setLeftChild(pointer);
    pointer->setFather(pointerRight);
}

void TreeRB::rotateRight(TreeRBNode *rootR, TreeRBNode *pointer)
{
    // rotação simples à direita
    TreeRBNode *pointerLeft = pointer->getLeftChild();

    pointer->setLeftChild(pointerLeft->getRightChild());

    if (pointer->getLeftChild() != NULL)
    {
        pointer->getLeftChild()->setFather(pointer);
    }

    pointerLeft->setFather(pointer->getFather());

    if (pointer->getFather() == NULL)
    {
        rootR = pointerLeft;
    }
    else if (pointer == pointer->getFather()->getLeftChild())
    {
        pointer->getFather()->setLeftChild(pointerLeft);
    }
    else
    {
        pointer->getFather()->setRightChild(pointerLeft);
    }

    pointerLeft->setRightChild(pointer);
    pointer->setFather(pointerLeft);
}

void TreeRB::printTree(TreeRBNode *r) // percurso em ordem
{
    if (r == NULL)
    {
        return;
    }
    else
    {
        printTree(r->getLeftChild());
        cout << r->getInfoID() << " ";
        printTree(r->getRightChild());
    }
    cout << endl << endl;
}