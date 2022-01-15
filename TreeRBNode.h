#ifndef TREERBNODE_H_INCLUDED
#define TREERBNODE_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;

class TreeRBNo
{
    // Atributos:
private:
    TreeRBNode *father;
    string infoID;
    int infoPosition;
    TreeRBNode *leftChild;
    TreeRBNode *rightChild;
    int color; // 0 Red 1 Black

    // Métodos:
public:
    TreeRBNode(string id, int pos)
    {
        father = null;
        color = 0;
        infoID = id;
        infoPosition = pos;
        leftChild = null;
        rightChild = null;
    }

    void changeColor()
    {
        if (color == 0)
            color = 1;
        else
            color = 0;
    }

    TreeRBNode *getFather()
    {
        return father;
    }

    string getInfoID()
    {
        return infoID;
    }

    int getInfoPosition()
    {
        return infoPosition;
    }

    TreeRBNode *getLeftChild()
    {
        return leftChild;
    }

    TreeRBNode *getRightChild()
    {
        return rightChild;
    }

    int getColor()
    {
        return color;
    }

    void setFather(TreeRBNode *father)
    {
        fatherSibling = father;
    }

    void setLeftChild(TreeRBNode *left)
    {
        leftChild = left;
    }

    void setRightChild(TreeRBNode *right)
    {
        rightChild = right;
    }
}

#endif