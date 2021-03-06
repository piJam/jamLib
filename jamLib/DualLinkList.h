#ifndef DUALLINKLIST_H
#define DUALLINKLIST_H
#include "List.h"
#include "Exception.h"
namespace jamLib {
template<typename T>
class DualLinkList :public List<T>
{
protected:
    struct Node : public Object
    {
        T value;
        Node* next;
        Node* pre;
    };

   // mutable Node m_header; //const方法中要修改变量的值，要加mutable修饰
    mutable struct : public Object
    {
        char reserved [sizeof(T)];
        Node* next;
        Node* pre;
    } m_header;

    int m_length;
    int m_step;
    Node* m_current;

    Node* position(int i) const //获取要获取元素位置的上一个元素，利用上一个元素的next找到要操作的元素位置
    {
        Node* ret = reinterpret_cast<Node*>(&m_header);

        for(int p = 0; p < i ;p++)
        {
            ret = ret->next;
        }
        return ret;
    }

    virtual Node* createNode()
    {
        return new Node();
    }
    virtual void destroy(Node* pn)
    {
        delete pn;
    }

public:
    DualLinkList()
    {
        this->m_header.next = NULL;
        this->m_header.pre = NULL;

        this->m_length = 0;
        this->m_step = 0;
        this->m_current = NULL;
    }

    virtual  bool insert(int i,const T& e)
    {
        bool ret = (0 <= i) && (i <= m_length);
        if(ret)
        {
            Node* node = createNode();
            if(node)
            {
                Node* current = position(i);
                Node* next = current->next;

                node->value = e;
                node->next = next;

                current->next = node;

                if(current != reinterpret_cast<Node*>(&m_header)) //判断是不是头节点
                {
                    node->pre = current;
                }
                else
                {
                    node->pre = NULL;
                }

                if(next != NULL) //判断next是否为空
                {
                    next->pre = node;
                }
                m_length++;
             }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException,"no memory to new Elements...");
            }
        }
        return ret;
    }

    virtual  bool insert(const T& e)
    {
        return insert(m_length,e);
    }

    virtual bool remove(int i)
    {
        bool ret = (0 <= i)&&( i < m_length);
        if(ret)
        {
            Node* current = position(i);
            Node* del = current->next;
            Node* next = del->next;
            if(m_current == del)
            {
                m_current = next;
            }
            current->next = next;

            if(next != NULL)
            {
                next->pre = current;
            }
            m_length--;
            destroy(del);
        }
        return 0;
    }

    virtual T get(int i) const
    {
        T ret;
        if(get(i,ret))
        {
            return ret;
        }else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException,"index out if bounds...");
        }
    }

    virtual bool get(int i,T& e) const
    {
        bool ret = (0 <= i)&&(i < m_length);
        if(ret)
        {
            Node* current = position(i);
            e = current->next->value;
        }
        return ret;
    }

    virtual bool set(int i,const T& e)
    {
        bool ret = (0 <= i)&&(i < m_length);
        if(ret)
        {
            Node* current = position(i);

            current->next->value = e;
        }
        return ret;
    }

    virtual int length() const
    {
         return m_length;
    }

    virtual void clear()
    {
        while(m_length > 0)
        {
            remove(0);
        }

    }

    virtual int find(const T& obj) const
    {
        int ret = -1;
        Node* node = m_header.next;
        int i = 0;
        while(node)
        {
            if(node->value == obj)
            {
                ret = i;
                break;
            }else
            {
                node = node->next;
                i++;
            }
        }
        return ret;
    }

    virtual bool move(int i ,int step = 1)
   {
        bool ret = (0 <= i) && (i < m_length) && ( step > 0);
        if(ret)
        {
            m_current = position(i)->next;
            m_step = step;
        }else
        {
             THROW_EXCEPTION(IndexOutOfBoundsException,"index out if bounds...");
        }

        return ret;
   }

    virtual bool end()
   {
       return (m_current == NULL);
   }

    virtual bool next()
   {
       int i = 0;
       while ( (i < m_step) && !end() )
       {
            m_current = m_current->next;
            i++;
       }
       return i == m_step;
   }
    virtual bool pre()
   {
        int i = 0;
        while ( (i < m_step) && !end() )
        {
            m_current = m_current->pre;
            i++;
        }
        return i == m_step;
   }

    virtual T current()
   {
       if(!end())
       {
            return m_current ->value;

       }else{

           THROW_EXCEPTION(InvalidOperationException,"no data at current position");
       }

   }

    ~DualLinkList()
    {
        clear();
    }
};

}

#endif // DUALLINKLIST_H
