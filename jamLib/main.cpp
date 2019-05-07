#include <iostream>
#include <cstring>
#include <cstdlib>

#include "DynamicArray.h"
#include "LinkList.h"

using namespace std;
using namespace jamLib;

class Test : public Object
{
    int m_index;
    SmartPoint<Test> m_test;
public:
    Test(int i = 0)
    {
        m_index = i;
        this->m_test = NULL;
    }
bool operator ==(const Test& e)
{
    return m_index == e.m_index;
}

};

int main()
{
    LinkList<int> link;

    for(int i = 0;i < 10;i++)
    {
        link.insert(i);
    }
for(link.move(0);!link.end();link.next())
{
    cout<< link.current() <<endl;
}

}


