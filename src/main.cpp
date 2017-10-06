#include <iostream>
#include "searchAlgorithms.h"
#include "sortAlgorithms.h"

int main()
{
    searchAlgorithms a;
    sortAlgorithms b;
    a.printList();
    std::cout<< "item found in pos: " << a.linearSearch( 83 ) << std::endl;
    std::cout<< "item found in pos: " << a.binarySearch( 83 ) << std::endl;
    std::cout<< "item found in pos: " << a.binarySearchRecursive( 83, 0, a.listSize() ) << std::endl;

    return 0;
}