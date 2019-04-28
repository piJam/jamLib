#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Object.h"
#include "SmartPoint.h"
#include "Exception.h"
#include "StaticList.h"
#include "DynamicList.h"
#include "SeqList.h"
#include "StaticArray.h"
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
    bool operator ==(const Test& t)
    {
        return (m_index == t.m_index);
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

    test == test1;

   cout<< "position :"<< list.find(test1) <<endl;


}


