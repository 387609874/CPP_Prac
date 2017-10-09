#include "binarySearchTree.h"
#include "searchAlgorithms.h"
#include "sortAlgorithms.h"

#include <iostream>
#include <string>

int main()
{
    searchAlgorithms a;
    sortAlgorithms b;
    binarySearchTree c( "num.txt" );

    // tests for sorting algorithms
    a.printList();
    std::cout<< "item found in pos: " << a.linearSearch( 83 ) << std::endl;
    std::cout<< "item found in pos: " << a.binarySearch( 83 ) << std::endl;
    std::cout<< "item found in pos: " << a.binarySearchRecursive( 83, 0, a.listSize() ) << std::endl;

    // tests for storting algorithms
    b.sort( SELECTIONSORT );
    b.sort( BUBBLESORT );
    b.sort( INSERTIONSORT );
    b.sort( QUICKSORT );
    b.sort( MERGESORT );

    c.printbinarySearchTree();
    return 0;
}