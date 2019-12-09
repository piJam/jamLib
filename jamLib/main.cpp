#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "test.h"
#include "LinkList.h"
using namespace std;
using namespace jamLib;

class A
{
public:
    A()
    {
        cout << "A init()"<< this << endl;
    }

    A( const A& a)
    {
        cout << "copy A" << this << endl;
    }

};

void show( A a)
{
    cout << &a << endl;
}

int main()
{
    A a;
    show(a);

    return 0;
}


