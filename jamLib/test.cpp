#include <iostream>
#include <cstring>
#include <cstdlib>
#include "SmartPoint.h"
#include "Exception.h"
#include "StaticList.h"
#include "DynamicList.h"
#include "SeqList.h"

using namespace std;
using namespace jamLib;

int main()
{

    StaticList<int,10> list;
    for(int i = 0; i < list.capacity(); i++)
    {
       list.insert(0,i);
    }
    cout << endl;
    list.remove(5);
    for(int i = 0; i < list.length(); i++)
    {
        cout<< list[i] << endl;
    }

    DynamicList<int> dy(10);
    for(int i = 0;i < dy.capacity();i++)
    {
        dy.insert(i,i);
    }
    cout << endl;

    for(int i = 0; i < dy.length(); i++)
    {
        cout<< dy[i] << endl;
    }

    dy.resize(2000000);
    cout << endl << dy.capacity() << endl << dy.length();
    cout << endl;
    dy.remove(5);
    for(int i = 0; i < dy.length(); i++)
    {
        cout<< dy[i] << endl;
    }

    return 0;
}

