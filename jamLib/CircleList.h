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

    int mod(int i) const
    {
        return (this->m_length == 0) ? 0 : (i % this->m_length);
    }
public:
    bool insert(const T& e)
    {
        return this->insert(this->m_length,e);
    }
    bool insert(int i, const T& e)
    {
        bool ret = true;
//        if(this->m_length == i )
//        {
//            i = i %( this->m_length + 1);
//        }else
//        {
//            i = mod(i);
//        }
        i = i %( this->m_length + 1);
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
        i = mod(i);
        if(i == 0)
        {
            Node* toDel = this->m_header.next;
            if(toDel != NULL)
            {
                this->m_header.next = toDel->next;
                this->m_length--;
                if(this->m_length > 0)
                {
                    last_to_first();
                    if(this->m_current == toDel)
                    {
                        this->m_current = this->m_current->next;
                    }
                }else
                {
                    this->m_header.next = NULL;
                    this->m_current = NULL;
                }

                this->destroy(toDel);
            }else
            {
                ret = false;
            }

        }
        else
        {
           ret = LinkList<T>::remove(i);
        }
        return ret;
    }

    bool set(int i,const T& e)
    {
        return LinkList<T>::set(mod(i),e);
    }

    bool get(int i,T& e) const
    {
        return LinkList<T>::get(mod(i),e);
    }

    T get(int i) const
    {
        return LinkList<T>::get(mod(i));
    }

    int find(const T& obj) const
    {
        int ret = -1;
        Node* slider = this->m_header.next;
        for(int i = 0;i < this->m_length; i++)
        {
            if( slider->value == obj)
            {
                ret = i;
                break;
            }
                slider = slider->next;
        }
        return ret;
    }

    void clear()
    {
        while( this->m_length > 1)
        {
            remove(1);
        }

        if(this->m_length == 1)
        {
            Node* toDel = this->m_header.next;
            this->m_header.next = NULL;
            this->m_length = 0;
            this->m_current = NULL;
            this->destroy(toDel);
        }
    }
    bool move(int i ,int step = 1)
    {

        return LinkList<T>::move(mod(i),step);

    }

    bool end()
    {
        //std::cout<< "this->m_header.next:"<<this->m_header.next<<"---this->m_current :"<< this->m_current <<std::endl;
        return (this->m_length == 0) || (this->m_current == NULL) ;

    }
    ~CircleList()
    {
        clear();
    }
};

}


#endif // CIRCLELIST_H
