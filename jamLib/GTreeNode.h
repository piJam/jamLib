#ifndef GTREENODE_H
#define GTREENODE_H
#include "TreeNode.h"
#include "LinkList.h"
#include "Object.h"
namespace jamLib
{
template< typename T>
class GTreeNode : public TreeNode<T>
{
protected:
    bool m_flag;
    void* operator new(size_t size) throw()
    {
        return Object::operator new(size);
    }
public:
    LinkList< GTreeNode<T>* > child;

    GTreeNode()
    {
        this->m_flag = false;
    }

    bool flag()
    {
        return this->m_flag;
    }

    static GTreeNode<T>* newNode()
    {

        GTreeNode<T>* ret = new GTreeNode<T>();

        if(ret)
        {
               ret->m_flag = true;
        }

        return ret;
    }
};

}

#endif // GTREENODE_H
