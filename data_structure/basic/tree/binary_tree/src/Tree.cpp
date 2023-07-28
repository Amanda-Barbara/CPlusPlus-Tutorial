#include "Tree.h"
#include <stdio.h>

Tree::Tree()
{
    m_pRoot = new Node();
}

Node* Tree::SearchNode(int nodeIndex)
{
    return m_pRoot->SearchNode(nodeIndex);
}

bool Tree::AddNode(int nodeIndex, int direction, Node* pNode)
{
    Node* temp = SearchNode(nodeIndex);
    if(temp == NULL)
        return false;
    
    Node* newNode = new Node();
    if(newNode == NULL)
        return false;
    newNode->index = pNode->index;
    newNode->data = pNode->data;
    
    if(direction == 0)
    {
        temp->pLChild = newNode;
    }

    if(direction == 1)
    {
        temp->pRChild == newNode;
    }
    
    return true;

}

bool Tree::DeleteNode(int nodeIndex, Node* pNode)
{
    Node* temp = SearchNode(nodeIndex);
    if(temp == NULL)
        return false;
    
}