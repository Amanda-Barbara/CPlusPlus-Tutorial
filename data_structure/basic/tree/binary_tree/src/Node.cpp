#include "Node.h"
#include <stdio.h>

Node::Node()
{
    index = 0;
    data = 0;
    pLChild = NULL;
    pRChild = NULL;
    pParent = NULL;
}

Node* Node::SearchNode(int nodeIndex)
{
    if(this-index == nodeIndex)
        return this;
    if(this->pLChild != NULL)
    {
        if(this->pLChild->index == nodeIndex)
            return this->pLChild;
    }

    if(this->pRChild != NULL)
    {
        if(this->pRChild->index == nodeIndex)
            return this->pRChild;
    }

    return NULL;
}