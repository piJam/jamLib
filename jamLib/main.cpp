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
#ifndef offset
#define offset(type,member)  (size_t)&(((type*) 0)-> member)
#endif

#ifndef container_of
#define  container_of(ptr,type,member) ({                \
         const typeof(((type*)0)->member)*  m_ptr = (ptr);\
         (type*)((char*)m_ptr - offset(type,member));    \
                                       })
#endif

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

    Node node;
    list_head* head = &node.list;

    Node* node1 = reinterpret_cast<Node*>(head);
    Node* node2 = container_of(head, Node, list);

    printf("node1 = %p, node2 = %p",node1, node2);


    return 0;
}


