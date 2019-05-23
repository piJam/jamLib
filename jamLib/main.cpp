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

<<<<<<< HEAD
#define offset_of(TYPE, MEMBER)  (void*)(&((TYPE*)0->MEMBER))

#define container_of(PTR, TYPE, MEMBER) ({\
const typeof( (TYPE*)0 ->MEMBER )* _mPTR = PTR;\
(TYPE*)( (void *)_mPTR - offset_of(TYPE, MEMBER); ) })

struct list_head
{
    list_head* next;
    list_head* pre;
};
struct Node
{
    list_head list;
    int value;
};
=======
>>>>>>> d9ba4fb0e4fdf28167da7025ce1bb797ec17ec10


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


