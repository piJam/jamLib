#ifndef BTREENODE_H
#define BTREENODE_H
#include"TreeNode.h"

namespace jamLib
{
template <typename T>
class BTreeNode : public TreeNode<T>
{
public:
    BTreeNode<T>* m_left;
    BTreeNode<T>* m_right;

    BTreeNode()
    {
        m_left = NULL;
        m_right = NULL;
    }

    static BTreeNode<T>* NewNode()
    {
        BTreeNode<T>* ret = new BTreeNode();
        if(ret != NULL)
        {
              ret->m_flag = true;
        }

        return ret;
    }
};

}

#endif // BTREENODE_H
