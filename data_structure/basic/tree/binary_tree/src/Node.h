#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node();
    int index;
    int data;
    Node* pLChild;
    Node* pRChild;
    Node* pParent;

public:
    Node* SearchNode(int nodeIndex);
};

#endif