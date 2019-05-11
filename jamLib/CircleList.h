#ifndef CIRCLELIST_H
#define CIRCLELIST_H
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
public:
    bool insert(const T& e)
    {
        return this->insert(this->m_length,e);
    }
    bool insert(int i, const T& e)
    {
        bool ret = true;


        return ret;
    }

};



}


#endif // CIRCLELIST_H
