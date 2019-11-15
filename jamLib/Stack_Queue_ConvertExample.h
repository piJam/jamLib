#ifndef STATCK_QUEUE_CONVERT_H
#define STATCK_QUEUE_CONVERT_H
#include "Exception.h"
#include "Queue.h"
#include "LinkQueue.h"
#include "Stack.h"
#include "LinkStack.h"

namespace jamLib
{
template < typename T >
class StackToQueue : public Queue<T>
{
protected:
 mutable  LinkStack<T> m_stack_in;
 mutable  LinkStack<T> m_stack_out;

    void move() const
    {
        if (m_stack_out.size() == 0)
        {
           while( m_stack_in.size() > 0)
           {
               m_stack_out.push(m_stack_in.top());
               m_stack_in.pop();
           }

        }
    }

public:
    void add(const T& e)
    {
        m_stack_in.push(e);
    }

    void remove()
    {
        move();

        if( m_stack_out.size() > 0)
        {
            m_stack_out.pop();
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "no elelment in Queue ...");
        }
    }

    void clear()
    {

        m_stack_in.clear();
        m_stack_out.clear();


    }

    T front() const
    {
        move();
        if( m_stack_out.size() > 0)
        {
           return m_stack_out.top();
        }
        else
        {
             THROW_EXCEPTION(InvalidOperationException, "no elelment in Queue ...");
        }
    }

    int lenght() const
    {
        return m_stack_in.size() + m_stack_out.size();
    }

};

template < typename T>
class QueueToStack : public Stack<T>
{
protected:
    LinkQueue<T> m_linkQueue_1;
    LinkQueue<T> m_linkQueue_2;

    LinkQueue<T>* m_linkQueue_in;
    LinkQueue<T>* m_linkQueue_out;

    void move() const
    {
        if( m_linkQueue_out->lenght() == 0)
        {
            int n = m_linkQueue_in->lenght() - 1;
            for( int i = 0; i < n ; i++ )
            {
                T temp = m_linkQueue_in->front();

                m_linkQueue_out->add( temp );
                m_linkQueue_in->remove();
            }
        }
    }

    void swap()
    {
        LinkQueue<T>* temp = NULL;
        temp = m_linkQueue_in;
        m_linkQueue_in = m_linkQueue_out;
        m_linkQueue_out = temp;
    }

public:
    QueueToStack()
    {
        m_linkQueue_in = &m_linkQueue_1;
        m_linkQueue_out = &m_linkQueue_2;

    }
    void push(const T& e)
    {
        m_linkQueue_in->add(e);
    }
    void pop()
    {
        if( m_linkQueue_in->lenght() > 0 )
        {
             move();

             m_linkQueue_in->remove();

             swap();
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "no element in queue ...");
        }
    }

    T top() const
    {
        if( m_linkQueue_in->lenght() > 0 )
        {
             move();

             return m_linkQueue_in->front();
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "no element in queue ...");
        }
    }

    void clear()
    {
        m_linkQueue_1.clear();
        m_linkQueue_2.clear();
    }

    int size() const
    {
        return m_linkQueue_1.lenght() + m_linkQueue_2.lenght();
    }

};

}


#endif // STATCK_QUEUE_CONVERT_H
