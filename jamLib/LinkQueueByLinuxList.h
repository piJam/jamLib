#ifndef LINKQUEUEBYLINUXLIST_H
#define LINKQUEUEBYLINUXLIST_H

#ifndef LINKQUEUE_H
#define LINKQUEUE_H
#include "Exception.h"
#include "Queue.h"
#include "LinuxList.h"
#include "Object.h"
namespace jamLib
{
template < typename T >
class LinkQueueByLinuxList :  public Queue<T>
{
protected:
    struct Node : public Object
    {
        list_head head;
        T value;
    };

 //   LinkList<T> m_list:
    list_head m_head;
    int m_lengh;

public:
    LinkQueueByLinuxList()
    {
        m_lengh = 0;
        INIT_LIST_HEAD(&m_head);
    }
    void add(const T& e)
    {

        Node* node = new Node();
        node->value = e;

        list_add_tail(&node->head, &m_head);
        m_lengh++;

    }

    void remove()
    {
        if(m_lengh > 0)
        {
            list_head* toDel = m_head.next;

            list_del( toDel);
            m_lengh--;

            delete list_entry(toDel, Node, head);
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"No element in space...");
        }
    }

    void clear()
    {
        while (m_lengh > 0)
        {
           remove();
        }
    }

    T front() const
    {
        if( m_lengh > 0)
        {
             Node* node =  list_entry (m_head.next, Node, head);
             return node->value;
        }
        else
        {
             THROW_EXCEPTION(InvalidOperationException,"No element in space...");
        }

    }

    int lenght() const
    {
        return m_lengh;
    }

    ~LinkQueue()
    {
        clear();
    }
};

}

#endif // LINKQUEUE_H



#endif // LINKQUEUEBYLINUXLIST_H
