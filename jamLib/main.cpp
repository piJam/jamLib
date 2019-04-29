#include <iostream>
#include <cstring>
#include <cstdlib>

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
    for(int i = 0; i<9;i++)
    {
        list.insert(i);
    }
 //   cout << list.get(0) << endl;

 cout << endl;
    for(list.move(0,2); !list.end(); list.next())
    {
        cout << list.current() << endl;
    }






}


