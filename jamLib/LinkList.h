#ifndef LINKLIST_H
#define LINKLIST_H
#include <iostream>
#include "List.h"
#include "Object.h"
#include "Exception.h"

using namespace std;
namespace jamLib
{
template <typename T>
class LinkList : public List<T>
{
protected:
    struct Node : public Object
    {
        T value;
        Node* next;
    };

    mutable Node m_header; //const方法中要修改变量的值，要加mutable修饰
    int m_length;
public:
    LinkList()
    {
        this->m_header.next = NULL;
        this->m_length = 0;
    }

    bool insert(int i,const T& e)
    {
        bool ret = (0 <= i) && (i <= m_length);
        if(ret)
        {
            Node* node = new Node();

            if(node != NULL)
            {
                Node* current = &m_header;

                for(int p = 0; p < i ;p++)
                {
                    current = current->next;
                }

                node->value = e;
                node->next = current->next;
                current->next = node;
                m_length++;
             }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException,"no memory to new Elements...");
            }
        }

        return ret;
    }

    bool insert(const T& e)
    {
        return insert(m_length,e);
    }
    bool remove(int i)
    {
        bool ret = (0 <= i)&&( i < m_length);
        if(ret)
        {
            Node* current = &m_header;
            for(int p = 0;p < i;p++)
            {
                current = current->next;
            }
            Node* del = current->next;
            current->next = del->next;
            delete del;
            m_length--;
        }
        return 0;
    }
    bool get(int i,T& e) const
    {
        bool ret = (0 <= i)&&(i < m_length);
        if(ret)
        {
            Node* current = &m_header;
            for(int p = 0;p < i; i++)
            {
                current = current->next;
            }
            e = current->next->value;
        }
        return ret;
    }
    bool set(int i,const T& e)
    {
        bool ret = (0 <= i)&&(i < m_length);
        if(ret)
        {
            Node* current = &m_header;
            for(int p = 0;p < i; i++)
            {
                current = current->next;
            }
            current->next->value = e;
        }
        return ret;
    }

    int length() const
    {
         return m_length;
    }
    void clear()
    {

        while(m_header.next)
        {
            Node* toDel = m_header.next;
            m_header.next = toDel->next;
            delete toDel;
        }
        m_length = 0;
    }

    ~LinkList()
    {
        clear();
    }
};
}


#endif // LINKLIST_H
