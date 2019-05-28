#ifndef STATICQUEUE_H
#define STATICQUEUE_H
#include "Queue.h"
#include "Exception.h"
namespace jamLib{
template <typename T, int N>
class StaticQueue :  public Queue<T>
{
protected:
    T m_space[N];
    int m_front;
    int m_rear;
    int m_length;
public:
    StaticQueue()
    {
        m_front = 0;
        m_rear = 0;
        m_length = 0;
    }

    void add(T& e)
    {
        if( m_length < N)
        {
            m_space[m_rear] = e;
            m_rear = (m_rear + 1) % N ;

            m_length ++;
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"No sapce in space...");
        }

    }

    void remove()
    {
        if( m_length > 0 )
        {
            m_front = (m_front + 1) % N ;
            m_length --;
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"No element in space...");
        }
    }

    void clear()
    {
        m_front = 0;
        m_rear = 0;
        m_length = 0;
    }

    T front() const
    {
        if(m_length > 0)
        {
            return m_space[m_front];
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"No element in space...");
        }

    }

    int lenght()
    {
        return m_length;
    }

    int capacity()
    {
        return N;
    }

};
}

#endif // STATICQUEUE_H