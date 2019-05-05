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



}


