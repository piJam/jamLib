#include <iostream>
#include <cstring>
#include <cstdlib>
#include "SmartPoint.h"
#include "DynamicArray.h"
#include "LinkList.h"
#include "SharedPointer.h"
#include "DualLinkList.h"

using namespace std;
using namespace jamLib;


int main()
{
    DualLinkList<int> dual;
    for(int i = 0; i < 10; i++)
    {
        dual.insert(i);
    }

    for(int i = 0; i < 10;i++)
    {
        cout<<  dual.get(i) << endl;
    }
    cout<< endl;
     dual.remove(1);
    for(dual.move(0,1); !dual.end();dual.next() )
    {
        cout<< dual.current() << endl;
    }
    cout << endl;
    dual.clear();
    for(dual.move(0,1); !dual.end(); dual.pre())
    {
        cout << dual.current() << endl;
    }
    return 0;
}


