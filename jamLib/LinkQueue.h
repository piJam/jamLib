#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include "Exception.h"
#include "Queue.h"
#include "LinkList.h"

namespace jamLib
{
template < typename T >
class LinkQueue :  public Queue<T>
{
protected:
    LinkList<T> m_list;

public:
    LinkQueue()
    {

    }

    void add(const T& e)
    {
        m_list.insert(e);
    }

    void remove()
    {
        if( m_list.length() > 0 )
        {
             m_list.remove(0);
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "No element in current queue ...");
        }

    }

    T front() const
    {
        if( m_list.length() > 0 )
        {
            return m_list.get(0);
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "No element in current queue ...");
        }

    }

    void clear()
    {
        m_list.clear();
    }

    int lenght() const
    {
        return m_list.length();
    }

    ~LinkQueue()
    {
        clear();
    }
};

}

#endif // LINKQUEUE_H
