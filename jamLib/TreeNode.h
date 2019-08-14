#ifndef TREENODE_H
#define TREENODE_H

#include "Object.h"
namespace jamLib
{
template <typename T>
class TreeNode : public Object
{
protected:
    bool m_flag;
    TreeNode<T>(const TreeNode<T>&);
    TreeNode<T>& operator=(const TreeNode<T>&);

    void* operator new(size_t size) throw()
    {
        return Object::operator new(size);
    }

public:
    T value;
    TreeNode<T>* parent;

    bool flag()
    {
        return this->m_flag;
    }

    TreeNode()
    {
        m_flag = false;
        parent = NULL;
    }

    virtual ~TreeNode() = 0;
};

template <typename T>
TreeNode<T>::~TreeNode(){}
}

#endif // TREENODE_H
