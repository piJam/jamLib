#include <iostream>
#include <cstring>
#include <cstdlib>
#include "SmartPoint.h"
#include "DynamicArray.h"
#include "LinkList.h"
#include "SharedPointer.h"
#include "CircleList.h"

using namespace std;
using namespace jamLib;

class Test
{
public:
    int m_value;
public:
    Test(int value = 0)
    {
        this->m_value = value;
    }
};



int main()
{

    LinkList<int>* cl = new CircleList<int>();

    return 0;
}


