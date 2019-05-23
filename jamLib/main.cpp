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


int main()
{



    return 0;
}


