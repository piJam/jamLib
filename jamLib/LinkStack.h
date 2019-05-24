#ifndef LINKSTACK_H
#define LINKSTACK_H
#include "Exception.h"
#include "Object.h"
#include "Stack.h"
#include "LinkList.h"

namespace jamLib
{

template< typename T>
class LinkStack : public Stack<T>
{
protected:
    LinkList<T> m_stack;
public:
    void push(const T& e)
    {
        m_stack.insert(0, e);
    }

    void pop()
    {
        if(m_stack.length() > 0)
        {
            m_stack.remove(0);
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"No element in stack...");
        }
    }

    T top() const
    {
        if(m_stack.length() > 0)
        {
            return m_stack.get(0);
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"No element in stack...");
        }
    }
    void clear()
    {
        if(m_stack.length() > 0)
        {
            return m_stack.clear();
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"No element in stack...");
        }
    }

    int size() const
    {
        return m_stack.length();
    }

};
}

#endif // LINKSTACK_H
