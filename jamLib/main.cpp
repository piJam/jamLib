#include <iostream>
#include <cstring>
#include <cstdlib>
#include "JString.h"
using namespace std;
using namespace jamLib;

struct Node
{
    int m_value;
    Node* next;
};

Node* create_list(int v, int len)
{
    Node* ret = NULL;
    Node* slider =NULL;

    for(int i=0; i<len; i++)
    {
        Node* n = new Node();
        n->m_value = v++;
        n->next = NULL;

        if( slider == NULL)
        {
            slider = n;
            ret = n;
        }
        else
        {
            slider->next = n;
            slider = n;
        }
    }
    return ret;
}

void print_list(Node* list)
{
    while(list)
    {
        cout << list->m_value << " -> ";

        list = list->next;
    }
    cout << "NULL" << endl;
}

void delete_list(Node* list)
{
    while(list)
    {
        Node* temp = list;
        list = list->next;
        delete temp;
    }
}

Node* reverse(Node* list)
{
    if( list == NULL || list->next == NULL )
    {
        return list;
    }
    else
    {
        Node* guard = list->next;
        Node* ret = reverse(list->next);

        guard->next = list;

        list->next = NULL;
        return ret;
    }


}
int sum(int num)
{

    if( num == 1)
    {
       num = 1;
    }else
    {
       num += sum(num - 1);
    }
    return num;
}

int main()
{

    Node* node = create_list(0, 10);
    print_list(node);

    print_list(reverse(node));
    delete_list(node);
    return 0;
}


