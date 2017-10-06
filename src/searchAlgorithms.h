#include "algorithmsBase.h"

#ifndef SEARCHALGORITHMS_H
#define SEARCHALGORITHMS_H

class searchAlgorithms : public algorithmsBase
{
public:
    searchAlgorithms();

    // search algorithms
    // return -1 if item not found
    int linearSearch( int target );

    // assume list is sorted
    int binarySearch( int target );
    int binarySearchRecursive( int target, int l, int r );

};

#endif // SEARCHALGORITHMS_H
