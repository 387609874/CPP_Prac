#include "algorithmsBase.h"

algorithmsBase::algorithmsBase()
{
    int i = 0;
    // add some random value into the list
    // TODO: make the list more usable
    for( i = 0; i < 10; i++ )
    {
        itemList.push_back( rand() % 100 );
    }
}

algorithmsBase::algorithmsBase( std::vector<int> &v )
{
    itemList = v;
}

bool algorithmsBase::pushBack( int item )
{
    itemList.push_back( item );
}

int algorithmsBase::listSize()
{
    return itemList.size();
}

void algorithmsBase::swapVals( int& a, int &b )
{
    int temp = a;
    a = b;
    b = temp;
}

void algorithmsBase::printList()
{
    int i = 0;
    std::cout << className << " Current list consists: ";
    for( i = 0; i < itemList.size(); ++i )
    {
        std::cout << itemList[i] << " ";
    }
    std::cout << std::endl;
}

IF_ORDERED algorithmsBase::isSorted( std::vector<int> list )
{
    int i = 0;
    int size = list.size() - 1;
    for( i = 0; i < size; i++ )
    {
        if( list[i] > list[i+1] )
            return NOT_IN_ORDER;
    }

    return IN_ORDER;
}