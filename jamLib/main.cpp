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
public:
    Test(int i = 0)
    {
        m_index = i;
    }
bool operator ==(const Test& e)
{
    return m_index == e.m_index;
}

};

int main()
{
    LinkList<int> list;

    for(int i = 0;i < 10 ;i++)
    {
        list.insert(i);
    }

    for(list.move(0);!list.end();list.next())
    {
        cout<< list.current() << endl;
    }

}


