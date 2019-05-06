#include <iostream>
#include <cstring>
#include <cstdlib>

#include "LinkList.h"
#include "StaticLinkList.h"

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

    StaticLinkList<int,10> st;

    for(int i = 0; i < 10; i++)
    {
        st.insert(0,i);
    }

    for(st.move(0,5);!st.end();st.next())
    {
        cout << st.current() << endl;
    }

}


