#include <iostream>
#include "searchAlgorithms.h"

int main()
{
    searchAlgorithms a;
    std::cout<< "item found in pos: " << a.linearSearch( 1 ) << std::endl;
    std::cout<< "item found in pos: " << a.binarySearch( 1 ) << std::endl;
    std::cout<< "item found in pos: " << a.binarySearchRecursive( 1, 0, a.listSize() ) << std::endl;
    std::cout<< "item found in pos: " << a.binarySearchRecursive( 6, 0, a.listSize() ) << std::endl;

    return 0;
}