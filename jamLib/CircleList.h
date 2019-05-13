#ifndef CIRCLELIST_H
#define CIRCLELIST_H
#include <iostream>
#include "LinkList.h"

namespace jamLib
{
template<typename T>
class CircleList : public LinkList<T>
{
protected:
    typedef typename LinkList<T>::Node Node;

    Node* last() const
    {
        return this->position(this->m_length - 1) ->next;
    }
    void last_to_first() const
    {
        last()->next = this->m_header.next;
    }

    int mod(int i)
    {
        return (this->m_length = 0) ? 0 : (i/this->m_length);
    }
public:
    bool insert(const T& e)
    {
        return this->insert(this->m_length,e);
    }
    bool insert(int i, const T& e)
    {
        bool ret = true;
       // i = i / this->m_length + 1;
        i = mod(i);
        ret = LinkList<T>::insert(i,e);
        if(i==0 && ret)
        {
            last_to_first();
        }
        return ret;
    }

    bool remove(int i)
    {
        bool ret = true;

        return ret;
    }
    ~CircleList()
    {

    }
};

}


#endif // CIRCLELIST_H
