#include "searchAlgorithms.h"

searchAlgorithms::searchAlgorithms()
{
    int i = 0;
    // add some random value into the list
    // TODO: make the list more usable
    for( i = 0; i < 6; i++ )
    {
        itemList.push_back(i);
    }
}

searchAlgorithms::searchAlgorithms( std::vector<int> targetList )
{
    itemList = targetList;
}

searchAlgorithms::~searchAlgorithms()
{
    itemList.clear();
}

bool searchAlgorithms::pushBack( int item )
{
    itemList.push_back( item );
}
int searchAlgorithms::listSize()
{
    return itemList.size();
}

int searchAlgorithms::linearSearch( int target )
{
    for( int i = 0; i < itemList.size(); i++ )
    {
        if( itemList[i] == target )
        {
            return i;
        }
    }
    return ITEM_NOT_FOUND;
}

int searchAlgorithms::binarySearch( int target )
{
    int l = 0;
    int m = 0;
    int r = itemList.size();
    while( l < r )
    {
        m = (l + r) / 2;
        if( itemList[m] == target )
        {
            return m;
        }
        else if( itemList[m] < target )
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return ITEM_NOT_FOUND;
}

int searchAlgorithms::binarySearchRecursive( int target, int l, int r )
{
    if( l > r )
    {
        return ITEM_NOT_FOUND;
    }
    int m = ( l + r ) / 2;
    if( target == itemList[m] )
    {
        return m;
    }
    else if( target < itemList[m] )
    {
        binarySearchRecursive( target, l, m - 1 );
    }
    else
    {
        binarySearchRecursive( target, m + 1, r );
    }
}
