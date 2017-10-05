#include <algorithm>
#include <vector>
#include <iostream>


static const int ITEM_NOT_FOUND = -1;
enum IF_ORDERED
{
    NOT_IN_ORDER,
    IN_ORDER
};

class searchAlgorithms
{
public:
    searchAlgorithms();
    searchAlgorithms( std::vector<int> targetList );
    ~searchAlgorithms();

    // add items to list
    // return false if insert not successful
    bool pushBack( int item );
    int listSize();

    // search algorithms
    // return -1 if item not found
    int linearSearch( int target );

    // assume list is sorted
    int binarySearch( int target );
    int binarySearchRecursive( int target, int l, int r );

private:
    std::vector<int> itemList;
};
