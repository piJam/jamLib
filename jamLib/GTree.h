#ifndef GTREE_H
#define GTREE_H
#include "TreeNode.h"
#include "GTreeNode.h"
#include "Tree.h"
#include "Exception.h"


namespace jamLib
{
template<typename T>
class GTree : public Tree<T>
{
protected:
    GTreeNode<T>* find(GTreeNode<T>* node, const T value) const
    {
        GTreeNode<T>* ret = NULL;

        if( node != NULL)
        {
            if(node->value == value)
            {
                return node;
            }else
            {
                for ( node->child.move(0); !node->child.end() && (ret == NULL); node->child.next())
                {
                    ret = find(node->child.current(), value);
                }
            }
        }

        return ret;
    }

    GTreeNode<T>* find(GTreeNode<T>* node, GTreeNode<T>* obj) const
    {
        GTreeNode<T>* ret = NULL;

        if(node == obj)
        {
            return node;
        }
        else
        {
            if(node != NULL)
            {
                for (node->child.move(0); !node->child.end() && (ret == NULL); node->child.next())
                {
                    ret = find(node->child.current(), obj);
                }
            }
        }
        return ret;
    }
public:
    bool insert(TreeNode<T>* node)
    {
        bool ret = true;
        if(node != NULL)
        {
            if(this->m_root == NULL)
            {
                this->m_root = node;
            }
            else
            {
                GTreeNode<T>* np = find(node->parent);
                if( np != NULL)
                {

                }
                else
                {
                    THROW_EXCEPTION(InvalidParameterException, "parent is null in this tree...");
                }
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "node cannot be null...");
        }

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
        return find(this->root(), value);
    }
    GTreeNode<T>* find(TreeNode<T> * node) const
    {
        return find(this->root(), dynamic_cast<GTreeNode<T>*>(node));
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
