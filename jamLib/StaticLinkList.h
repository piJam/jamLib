#ifndef STATICLINKLIST_H
#define STATICLINKLIST_H
#include "LinkList.h"
namespace jamLib
{
template<typename T,int N>
class StaticLinkList : public LinkList<T>
{
protected:
    typedef typename LinkList<T>::Node Node;
    struct SNode : public Node
    {
    public:
        void* operator new(unsigned int size, void* location)
        {
            (void) size;
            return location;
        }
    };

    T m_space[sizeof(SNode) * N];
    int m_index[N];

    virtual Node* createNode()
    {
       SNode* ret = NULL;
        for(int i = 0;i < N; i++)
        {
            if( !m_index[i] )
            {
                m_index[i] = 1;
                ret = reinterpret_cast<SNode*>(m_space) + i ;
                ret = new(ret) SNode();
                break;
            }
        }
        return ret;
    }

    virtual void destory(Node* pn)
    {
        SNode* space = reinterpret_cast<SNode*>(m_space);
        SNode* spn = dynamic_cast<SNode*>(pn);
        for(int i = 0; i < N; i++)
        {
            if(spn == (space + i))
            {
                m_index[i] = 0;
                spn->~SNode();
            }
        }

    }
public:
    StaticLinkList()
    {
        for(int i = 0;i<N;i++)
        {
            m_index[i] = 0;
        }
    }

    int capacity()
    {
        return N;
    }

};
}

#endif // STATICLINKLIST_H
