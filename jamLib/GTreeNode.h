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

public:
    LinkList< GTreeNode<T>* > child;



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
