#ifndef STATICLINKLIST_H
#define STATICLINKLIST_H
#include "LinkList.h"
namesapce jamLib
{
template<typename T,int N>
class StaticLinkList : public LinkList<T>
{
protected:
    typedef typename LinkList<T>::Node Node;

    T m_space[sizeof(Node) * N];
    int m_index[N];
    virtual Node* createNode()
    {

    }

    virtual void destory(Node* pn)
    {
    }
public:

};
}

#endif // STATICLINKLIST_H
