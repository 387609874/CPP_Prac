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
    INORDERTRAVERSAL,
    PREORDERTRAVERSAL,
    POSTORDERTRAVERSAL
};

class binarySearchTree
{
public:
    binarySearchTree();
    binarySearchTree( std::string fileName );
    ~binarySearchTree();

    // TODO: print out the tree
    void printbinarySearchTree();

private:
    nodeBinaryTree* root;
    std::vector<int> fileData;

    void readFIleToVector( std::string fileName );
    void insert( nodeBinaryTree* node, nodeBinaryTree* parent );
    void deleteNode();
};

#endif // BINARYSEARCHTREE_H
