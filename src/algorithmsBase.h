#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#ifndef ALGORITHMSBASE_H
#define ALGORITHMSBASE_H

static const int ITEM_NOT_FOUND = -1;
enum IF_ORDERED
{
    NOT_IN_ORDER,
    IN_ORDER
};

class algorithmsBase
{
public:
    algorithmsBase();
    algorithmsBase( std::vector<int> &targetList );
    virtual ~algorithmsBase();

    // add items to list
    // return false if insert not successful
    bool pushBack( int item );

    int listSize();
    void printList();
    std::vector<int> itemList; // Should be private only for practice
    std::string className; // Should be private only for practice
};

#endif // ALGORITHMSBASE_H
