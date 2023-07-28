 #include <iostream>
 #include "Tree.h"

 int main(void)
 {
    Node* node1 = new Node();
    node1->index = 1;
    
    Tree* tree = new Tree();
    delete tree;

    return 0;
 }