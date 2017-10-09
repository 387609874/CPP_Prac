#include "sortAlgorithms.h"

#include <stdexcept>
#include <iostream>
#include <queue>

sortAlgorithms::sortAlgorithms()
{
    className = "sortAlgorithms";
    copyVector();
}

void sortAlgorithms::printList()
{
    int i = 0;
    for( i = 0; i < sortedList.size(); ++i )
    {
        std::cout << sortedList[i] << " ";
    }
}

void sortAlgorithms::bubbleSort()
{
    int i = 0;
    int j = 0;
    int temp = 0;
    int size = sortedList.size();
    int curPos = size - 1; // avoid step out of the bound, since we are checking j+1

    for( i = 0; i < size; ++i )
    {
        for( j = 0; j < curPos; ++j )
        {
            if( sortedList[j] > sortedList[j+1] )
            {
                algorithmsBase::swapVals( sortedList[j], sortedList[j+1] );
            }
        }
        --curPos;
    }
}

void sortAlgorithms::selectionSort()
{
    int i = 0;
    int j = 0;
    int curMin = 100; // largest item is 99
    int minPos = -1;
    int temp = 0;

    for( i = 0; i < sortedList.size(); ++i )
    {
        minPos = -1;
        curMin = 100;
        for( j = i; j < sortedList.size(); ++j )
        {
            if( curMin > sortedList[j] )
            {
                curMin = sortedList[j];
                minPos = j;
            }
        }
        // swap minPos and i
        algorithmsBase::swapVals( sortedList[minPos], sortedList[i] );
    }
}

void sortAlgorithms::insertionSort()
{
    int i = 0;
    int j = 0;
    int min = 100;
    int minPos = -1;
    int size = sortedList.size();
    for( i = 1; i < size; ++i )
    {
        min = 100;
        minPos = -1;
        j = i;
        while( sortedList[j] < sortedList[j-1] && j > 0 )
        {
            algorithmsBase::swapVals( sortedList[j], sortedList[j-1] );
            --j;
        }
    }
}

void sortAlgorithms::mergeSort( int left, int right )
{
    int m = 0;
    if( left < right )
    {
        m = ( left + right ) / 2;
        mergeSort( left, m );
        mergeSort( m + 1, right );
        mergeLists( left, m, right );
    }
}

void sortAlgorithms::mergeLists( int left, int mid, int right )
{
    // std::vector<int> l( sortedList.begin() + left, sortedList.begin() + mid );
    // std::vector<int> r( sortedList.begin() + mid + 1, sortedList.end() );

    std::queue<int> l;
    std::queue<int> r;
    int j = 0;
    for( j = left; j <= mid; ++j )
    {
        l.push( sortedList[j] );
    }
    for( j = mid + 1; j <= right; ++j )
    {
        r.push( sortedList[j] );
    }

    int i = left;
    while( l.empty() == false && r.empty() == false )
    {
        if( l.front() >= r.front() )
        {
            sortedList[i] = r.front();
            r.pop();
            i++;
        }
        else
        {
            sortedList[i] = l.front();
            l.pop();
            i++;
        }
    }
}

void sortAlgorithms::heapSort()
{

}

void sortAlgorithms::quickSort( int left, int right )
{
    int pivotPos = 0;
    if( left < right )
    {
        pivotPos = quickSortPartition( left, right );
        quickSort( left, pivotPos - 1 );
        quickSort( pivotPos + 1, right );
    }

}

int sortAlgorithms::quickSortPartition( int left, int right )
{
    // choose a good pivot can make quick sort a lot faster.
    // I choose the right most item for simplicity reason.
    int pivotVal = sortedList[right];
    int j = left - 1;
    int i = 0;
    for( i = left; i <= right - 1; ++i )
    {
        //  std::cout << sortedList[i] << "    " << pivotIdx << "   " << i << "  " << pivotVal << std::endl;

        if( sortedList[i] <= pivotVal )
        {
            ++j;
            algorithmsBase::swapVals( sortedList[j], sortedList[i] );
        }
    }
    algorithmsBase::swapVals( sortedList[j+1], sortedList[right] );
    return j+1;
}

void sortAlgorithms::sort( SORT_ALGORITHMS alg )
{
    algorithmsBase::printList();
    std::cout << "Algorithms: " << getAlgStr( alg ) << std::endl;
    std::cout << "List before sort: ";
    sortAlgorithms::printList();
    std::cout << std::endl;
    switch( alg )
    {
        case SELECTIONSORT:
            selectionSort();
            break;
        case BUBBLESORT:
            bubbleSort();
            break;
        case INSERTIONSORT:
            insertionSort();
            break;
        case QUICKSORT:
            quickSort( 0, sortedList.size() - 1 );
            break;
        case MERGESORT:
            mergeSort( 0, sortedList.size() -1 );
            break;
        default:
            throw std::invalid_argument( "binarySearchTree:: invalid order\n" );
            std::cout << "Invalid sortAlgorithms.\n";
            break;
    }
    std::cout << "List after sort: ";
    sortAlgorithms::printList();
    std::cout << std::endl;
    if( isSorted( sortedList ) == IN_ORDER )
    {
        std::cout << "List is sorted\n";
    }
    else
    {
        std::cout << "List is not sorted\n";
    }
    std::cout << std::endl << std::endl;
    copyVector();
}

std::string sortAlgorithms::getAlgStr( SORT_ALGORITHMS alg )
{
    std::string algStr = "";
    switch( alg )
    {
        case SELECTIONSORT:
            algStr = "selection sort";
            break;
        case BUBBLESORT:
            algStr = "bubble sort";
            break;
        case INSERTIONSORT:
            algStr = "insertion sort";
            break;
        case MERGESORT:
            algStr = "merge sort";
            break;
        case QUICKSORT:
            algStr = "quick sort";
            break;
        case HEAPSORT:
            algStr = "heap sort";
            break;
        case RADIXSORT:
            algStr = "radix sort";
            break;
        case COUNTINGSORT:
            algStr = "count sort";
            break;
        case BUCKETSORT:
            algStr = "bucket sort";
            break;
        case SHELLSORT:
            algStr = "shell sort";
            break;
        default:
            std::cout << "Invalid sortAlgorithms.\n";
            throw std::invalid_argument( "binarySearchTree:: invalid order\n" );
            break;
    }

    return algStr;
}

void sortAlgorithms::copyVector()
{
    int i = 0;
    sortedList.clear();
    sortedList = itemList;
}
