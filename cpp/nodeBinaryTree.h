#include "nodeBase.h"

#include <cstddef>

#ifndef NODEBINARYTREE_H
#define NODEBINARYTREE_H

class nodeBinaryTree : public nodeBase
{
public:
    nodeBinaryTree() { leftChild = NULL; rightChild = NULL; }
    nodeBinaryTree( int n, nodeBinaryTree* l, nodeBinaryTree* r ) :
        nodeBase( n ),
        leftChild( l ),
        rightChild( r ) {}
    nodeBinaryTree( int n ) :
        nodeBase( n ) { leftChild = NULL; rightChild = NULL; }

    ~nodeBinaryTree() { leftChild = NULL; rightChild = NULL; delete leftChild; delete rightChild; }
    nodeBinaryTree* getLeftChild() { return leftChild; }
    nodeBinaryTree* getRightChild() { return rightChild; }
    void setLeft( nodeBinaryTree* l ) { leftChild = l; }
    void setRight( nodeBinaryTree* r ) { rightChild = r; }

private:
    nodeBinaryTree* leftChild;
    nodeBinaryTree* rightChild;
};

#endif // NODEBINARYTREE_H
