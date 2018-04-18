#include "binarySearchTree.h"

#include <stdexcept>

binarySearchTree::binarySearchTree()
{
    root = NULL;
}

binarySearchTree::binarySearchTree( std::string fileName )
{
    readFIleToVector( fileName );
    root = new nodeBinaryTree( fileData[0], NULL, NULL );
    nodeBinaryTree* node;
    for( std::vector<int>::const_iterator v = fileData.begin() + 1; v != fileData.end(); ++v )
    {
        node = new nodeBinaryTree( *v );
        insert( node, root );
    }

}

binarySearchTree::~binarySearchTree()
{
    fileData.clear();

    deleteNode( root );
}

void binarySearchTree::deleteNode( nodeBinaryTree* parent )
{
    if( parent->getLeftChild() != NULL )
    {
        deleteNode( parent->getLeftChild() );
    }
    else if( parent-> getRightChild() != NULL )
    {
        deleteNode( parent->getRightChild() );
    }
    else
    {
        parent = NULL;
        delete parent;
    }
}

void binarySearchTree::printbinarySearchTree( TRAVERSALORDER order )
{
    std::cout << "File data: ";
    for( std::vector<int>::const_iterator v = fileData.begin(); v != fileData.end(); ++v )
    {
        std::cout << *v << " ";
    }
    std::cout << std::endl;
    switch( order )
    {
        case INORDERTRAVERSAL:
            std::cout << "in order travesal: ";
            printInorder( root );
            break;
        case PREORDERTRAVERSAL:
            std::cout << "pre order travesal: ";
            printPreorder( root );
            break;
        case POSTORDERTRAVERSAL:
            std::cout << "post order travesal: ";
            printPostorder( root );
            break;
        default:
            throw std::runtime_error( "Invalid travesal order\n" );
            break;
    }
    std::cout << std::endl;
}

void binarySearchTree::readFIleToVector( std::string fileName )
{
    std::ifstream inFile;
    inFile.open( fileName.c_str() );
    if( !inFile )
    {
        throw std::runtime_error( "binarySearchTree:: line 26: Can't open file\n" );
    }

    int x = 0;
    // TODO: catch exception if it not valid input
    while( inFile >> x )
    {
        fileData.push_back( x );
    }

    inFile.close();
}

void binarySearchTree::insert( nodeBinaryTree* node, nodeBinaryTree* parent )
{
    // std::cout << "node: " << node->getData() << " parent: " << parent->getData() << std::endl;
    if( parent->getData() >= node->getData() )
    {
        if( parent->getLeftChild() == NULL )
        {
            std::cout << "left child node: " << node->getData() << " parent: " << parent->getData() << std::endl;
            parent->setLeft( node );
        }
        else
        {
            insert( node, parent->getLeftChild() );
        }
    }
    else if( parent->getData() < node->getData() )
    {
        if( parent->getRightChild() == NULL )
        {
            std::cout << "right child node: " << node->getData() << " parent: " << parent->getData() << std::endl;
            parent->setRight( node );
        }
        else
        {
            insert( node, parent->getRightChild() );
        }
    }
}

void binarySearchTree::printInorder( nodeBinaryTree* parent )
{
    //std::cout << &parent << std::endl;
    if( parent == NULL )
        return;
    printInorder( parent->getLeftChild() );
    std::cout << parent->getData() << " ";
    printInorder( parent->getRightChild() );
}
void binarySearchTree::printPreorder( nodeBinaryTree* parent )
{
    if( parent == NULL )
        return;
    std::cout << parent->getData() << " ";
    printPreorder( parent->getLeftChild() );
    printPreorder( parent->getRightChild() );

}
void binarySearchTree::printPostorder( nodeBinaryTree* parent )
{
    if( parent == NULL )
        return;
    printPreorder( parent->getLeftChild() );
    printPreorder( parent->getRightChild() );
    std::cout << parent->getData() << " ";
}


