#ifndef DUALLINKLIST_H
#define DUALLINKLIST_H
namespace jamLib {
template<typename T>
class DualLinkList : List<T>
{
protected:
    struct Node : public Object
    {
        T value;
        Node* next;
        Node* pre;
    };

   // mutable Node m_header; //const������Ҫ�޸ı�����ֵ��Ҫ��mutable����
    mutable struct : public Object
    {
        char reserved [sizeof(T)];
        Node* next;
        Node* pre;
    } m_header;

    int m_length;
    int m_step;
    Node* m_current;

    Node* position(int i) const //��ȡҪ��ȡԪ��λ�õ���һ��Ԫ�أ�������һ��Ԫ�ص�next�ҵ�Ҫ������Ԫ��λ��
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

                if(current != reinterpret_cast<Node*>(&m_header)) //�ж��ǲ���ͷ�ڵ�
                {
                    node->pre = current;
                }
                else
                {
                    node->pre = NULL;
                }

                if(next != NULL) //�ж�next�Ƿ�Ϊ��
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
            if(m_current == del)
            {
               m_current = del->next;
            }

            current->next = del->next;

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
        while(m_header.next)
        {
            Node* toDel = m_header.next;
            m_header.next = toDel->next;
            m_length--;
            destroy(toDel);
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
