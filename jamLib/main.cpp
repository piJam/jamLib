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

void jose(int n,int s,int m)
{
    CircleList<int> cl;
    for(int i =1;i <= n;i++)
    {
        cl.insert(i);
    }

    cout<< cl.get(0) <<endl;
    cl.move(s-1,m-1);
    while(cl.length() > 0)
    {
       cl.next();
       cout << cl.current() << endl;
       cl.remove(cl.find(cl.current()));
    }
}

int main()
{

    jose(41,1,3);
    return 0;
}


