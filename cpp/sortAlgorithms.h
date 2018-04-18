#include "algorithmsBase.h"

#include <string>

#ifndef SORTALGORITHMS_H
#define SORTALGORITHMS_H

enum SORT_ALGORITHMS
{
    SELECTIONSORT,
    BUBBLESORT,
    INSERTIONSORT,
    MERGESORT,
    QUICKSORT,
    HEAPSORT,
    RADIXSORT,
    COUNTINGSORT,
    BUCKETSORT,
    SHELLSORT
};

class sortAlgorithms : public algorithmsBase
{
public:
    sortAlgorithms();

    // override base class
    void printList();

    void sort( SORT_ALGORITHMS alg );

private:
    std::vector<int> sortedList;

    std::string getAlgStr( SORT_ALGORITHMS alg );
    void reinitVector();
    void bubbleSort();
    void selectionSort();
    void insertionSort();

    // return pivot position
    int quickSortPartition( int left, int right );
    void mergeSort( int left, int right );
    void mergeLists( int left, int mid, int right );
    void heapSort();
    void quickSort( int left, int right );
    void copyVector();
};

#endif // SORTALGORITHMS_H
