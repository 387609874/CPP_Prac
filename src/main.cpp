#include <iostream>
#include "searchAlgorithms.h"
#include "sortAlgorithms.h"

int main()
{
    searchAlgorithms a;
    sortAlgorithms b;

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
    return 0;
}