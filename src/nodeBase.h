#ifndef NODEBASE_H
#define NODEBASE_H

class nodeBase
{
public:
    nodeBase() { num = 0; }
    nodeBase( int n ) { num = n; }
    int getData() { return num; }
    void setDate( int n ) { num = n; }

private:
    // TODO: use template
    int num;
};

#endif // NODEBASE_H
