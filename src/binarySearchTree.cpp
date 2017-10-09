#include "binarySearchTree.h"

#include <stdexcept>

binarySearchTree::binarySearchTree()
{
    root = NULL;
}

binarySearchTree::binarySearchTree( std::string fileName )
{
    readFIleToVector( fileName );
    nodeBinaryTree rootNode( fileData[0], NULL, NULL );
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

void binarySearchTree::deleteNode( binarySearchTree* parent )
{
    if( parent->getLeftChild() != NULL )
        deleteNode( parent->getLeftChild() );
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

void binarySearchTree::printbinarySearchTree()
{
    for( std::vector<int>::const_iterator v = fileData.begin(); v != fileData.end(); ++v )
    {
        std::cout << *v << ' ';
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
    if( parent->getData() <= node->getData() )
    {
        if( parent->getLeftChild() == NULL )
        {
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
            parent->setRight( node );
        }
        else
        {
            insert( node, parent->getRightChild() );
        }
    }
}
