#include "nodeBinaryTree.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

// TODO: name enumber better
enum TRAVERSALORDER
{
    // left, root, right
    INORDERTRAVERSAL,
    // root, left, right
    PREORDERTRAVERSAL,
    // left, right, root
    POSTORDERTRAVERSAL
};

class binarySearchTree
{
public:
    binarySearchTree();
    binarySearchTree( std::string fileName );
    ~binarySearchTree();

    // TODO: print out the tree
    void printbinarySearchTree( TRAVERSALORDER order );

private:
    nodeBinaryTree* root;
    std::vector<int> fileData;

    void readFIleToVector( std::string fileName );
    void insert( nodeBinaryTree* node, nodeBinaryTree* parent );
    void deleteNode( nodeBinaryTree* parent );
    void printInorder( nodeBinaryTree* parent );
    void printPreorder( nodeBinaryTree* parent );
    void printPostorder( nodeBinaryTree* parent );
};

#endif // BINARYSEARCHTREE_H
