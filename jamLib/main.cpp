#include <iostream>
#include <cstring>
#include <cstdlib>
#include "SmartPoint.h"
#include "DynamicArray.h"
#include "LinkList.h"
#include "SharedPointer.h"
#include "DualLinkList.h"
#include "DualCircleList.h"

using namespace std;
using namespace jamLib;



int main()
{
     //DualLinkList<int> list;
    DualCircleList<int> list;

    for(int i = 0; i < 10; i++)
    {
        list.insert(i);
    }
    list.remove(2);

    int i = 0;
    for(list.move(0,1);(i < list.length() && !list.end()); i++,list.next())
    {
        cout << list.current() << endl;

    }



    return 0;
}


