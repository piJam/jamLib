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
    LinkList<Test> list;
    Test test;
    Test test1(1);
    Test test2(2);
    Test test3(3);
    Test test4(4);

    list.insert(test);
    list.insert(test1);
    list.insert(test2);
    list.insert(test3);
    list.insert(test4);




   cout<< "position :"<< list.find(test1) <<endl;


}


