#ifndef DUALCIRCLELIST_H
#define DUALCIRCLELIST_H
#include "Exception.h"
#include "DualLinkList.h"
#include "Object.h"
#include "LinuxList.h"
using namespace std;

namespace jamLib {

template<typename T>
class DualCircleList : public DualLinkList<T>
{
protected:
    struct Node : public Object
    {
        list_head head;
        T value;
    };

    list_head m_header;
    list_head* m_current;

    int mod(int i)
    {
        return ( this->m_length == 0 ) ? 0 :( i % this->m_length) ;
    }

    list_head* position(int i) const
    {
        list_head* ret = const_cast<list_head*>(&m_header);
        i = mod(i);
        for(int j = 0 ;j < i ; j++)
        {
            ret = ret->next;

        }
        if( ret == &list_head)
        {
            cout<< "current is head!" << endl;
             ret = ret->next;
        }
        return ret;
    }


public:
    DualCircleList()
    {
        this->m_length = 0;
        m_current = NULL;
        this->m_step = 1;
        INIT_LIST_HEAD(&m_header.head);
    }

    bool insert(const T& e)
    {
        return insert(this->m_length, e);
    }

    bool insert(int i,const T& e)
    {
        bool ret = false;
        i = i % (this->m_length + 1);
        Node* node = new Node();
        if(node != NULL)
        {
            node->value = e;

            list_add_tail(&node->head, position(i)->next);

            this->m_length ++;
            ret = true;
        }else
        {
              THROW_EXCEPTION(NoEnoughMemoryException,"no memory to new Elements...");
        }
        return ret;
    }

    bool remove(int i)
    {
        bool ret = true;
        i = mod(i);

        ret = (i < this->m_length) && (i >= 0);
        if( ret )
        {
            list_head* toDel = position(i)->next;

            if(m_current == toDel)
            {
                m_current = toDel->next;
            }

            list_del(toDel);


            this->m_length-- ;
            destroy( reinterpret_cast<Node*>(toDel) );

        }else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException,"no elements...");
        }

        return ret;
    }

    bool set(int i,const T& e)
    {
        bool ret = true;
        i = mod(i);

        ret = (0 <= i)&&(i < m_length);

        if(ret)
        {
           // reinterpret_cast<Node*>(position(i)->next)->value = e;
            list_entry(position(i)->next, Node, head)->value = e;  //宏转换
        }
        return ret;

    }

    T get(int i) const
    {
        T ret;
        if( get(i, ret) )
        {
            return ret;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException,"Invalid parament...");
        }

        return ret;
    }

    bool get(int i,T& e) const
    {
        i = mod(i);
        bool ret = (0 <= i) && (i < m_length);
        if(ret)
        {

            e = list_entry(position(i)->next, Node, head)->value;
        }
        return ret;
    }


     int find(const T& obj) const
      {
          int ret = -1;
          list_head* silder = NULL;
          int i = 0;

          list_for_each(silder,&m_header)
          {
              if(list_entry(silder, Node, head)->value == obj)
              {
                    ret = i;
                    break;
              }

              i++;
          }
          return ret;
      }

     // int lenght() const 使用父类的

     void clear()
     {
         while(this->m_length > 0)
         {
             remove(0);
             this->m_length--;
         }

     }

    bool move(int i, int step = 0)
    {
        bool ret = ( step > 0 );

        i = mod(i);

        ret = (i >= 0) && (i < this->m_length);

        if(ret)
        {
            m_current = position(i)->next;

            this->m_step = step;

         }

        return ret;
    }

    bool end()
    {
        return (m_current == &m_header) || (this->m_length == 0);
    }

    bool next()
    {
        for(int i = 0; (i < this->m_step) && (!end()); i++)
        {
            m_current = m_current->next;
            if(m_current == &m_header)
            {
                m_current = m_current->next;
            }
        }

        if(m_current == &m_header)
        {
            m_current = m_current->next;
        }
        return i == this->m_step;
    }

    bool pre()
    {
        for(int i = 0; (i < this->m_step) && (!end()); i++)
        {
            m_current = m_current->prev;
            if(m_current == &m_header)
            {
                m_current = m_current->prev;
            }
        }

        if(m_current == &m_header)
        {
            m_current = m_current->prev;
        }
        return i == this->prev;
    }

    T current()
    {
        if(!end())
        {
             return list_entry(m_current, Node, head)->value;
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"No value ...");
        }
    }

    ~DualCircleList()
    {
        clear();
    }
};

}
#endif // DUALCIRCLELIST_H
