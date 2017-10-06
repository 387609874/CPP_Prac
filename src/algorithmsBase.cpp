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

algorithmsBase::~algorithmsBase()
{
    itemList.clear();
}

bool algorithmsBase::pushBack( int item )
{
    itemList.push_back( item );
}

int algorithmsBase::listSize()
{
    return itemList.size();
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