#ifndef GTREE_H
#define GTREE_H
#include "GTreeNode.h"
#include "Tree.h"
namespace jamLib
{
template<typename T>
class GTree : public Tree<T>
{
public:
    bool insert(TreeNode<T>* node)
    {
        bool ret = true;

        return ret;
    }
    bool insert(const T& value, TreeNode<T>* parent)
    {

        bool ret = true;

        return ret;
    }

    SharedPointer< Tree<T> > remover(const T& value)
    {
        return NULL;
    }
    SharedPointer< Tree<T> > remover(TreeNode<T>* node)
    {
        return NULL;
    }

    GTreeNode<T>* find(const T& value) const
    {
        return NULL;
    }
    GTreeNode<T>* find(TreeNode<T> * node) const
    {
        return NULL;
    }

    GTreeNode<T>* root() const
    {
        return dynamic_cast< GTreeNode<T>* >(this->m_root);
    }

    int degree() const
    {
        return 0;
    }
    int count() const
    {
        return 0;
    }
    int height() const
    {
        return 0;
    }
    void clear()
    {

    }

};
}
#endif // GTREE_H
