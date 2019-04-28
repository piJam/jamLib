#include <iostream>
#include <cstring>
#include <cstdlib>
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

int main()
{
    LinkList<int> list;
    list.insert(1);
    list.insert(1);
    list.insert(1);
    list.insert(3,5);

    for(int i = 0; i<list.length(); i++)
    {
        cout << list.get(i) << endl;
    }

    cout<< "position :"<< list.find(5) <<endl;


}


