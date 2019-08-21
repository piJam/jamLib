#ifndef BTREE_H
#define BTREE_H
#include "BTreeNode.h"

#include "Tree.h"

namespace jamLib {

template<typename T>
class BTree : public Tree<T>
{
protected:
    virtual BTreeNode<T>* find(BTreeNode<T>* node, T& value) const
    {
        BTreeNode<T>* ret = NULL;

        if(node != NULL)
        {
            if(node->value == value)
            {
                ret = node;
            }
            else
            {
                if(ret == NULL)
                {
                    ret = find(node->m_left, value);
                }

                if( ret == NULL)
                {
                      ret = find(node->m_right, value);
                }
            }

        }
        return ret;
    }

    virtual BTreeNode<T>* find( BTreeNode<T>* node, BTreeNode<T>* obj) const
    {
         BTreeNode<T>* ret = NULL;

         if(node == obj)
         {
            ret = node;
         }
         else
         {
             if(node != NULL)
             {
                 if(ret == NULL)
                 {
                     ret =  find(node->m_left, obj);
                 }

                 if(ret == NULL)
                 {
                     ret = find(node->m_right, obj);
                 }
             }
         }

         return ret;
    }

    virtual Bool insert( BTreeNode<T>* n, BTreeNode<T>* np, BTNodePos pos)
    {
        Bool ret = true;

        if( pos == ANY )
        {
            if( np->m_left == NULL)
            {
                np->m_left = n;
            }
            else if( np->m_right == NULL)
            {
                np->m_right = n;
            }
            else
            {
                ret = false;
            }

        }
        else if( pos == LEFT)
        {
            if(np->m_left == NULL)
            {
                np->m_left = n;
            }
            else
            {
                ret = false;
            }
        }
        else if( pos == RIGHT)
        {
            if( np->m_right = NULL)
            {
                np->m_right = n;
            }
            else
            {
                ret = false;
            }

        }else
        {
            ret = false;
        }

        return ret;
    }
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

    SharedPointer< Tree<T> > remove(const T& value)
    {
        return NULL;
    }
    SharedPointer< Tree<T> > remove(TreeNode<T>* node)
    {
        return NULL;
    }

    BTreeNode<T>* find(const T& value) const
    {
        return find(this->root(), value);
    }
    BTreeNode<T>* find(TreeNode<T> * node) const
    {
        return find(this->root(), dynamic_cast<BTreeNode<T>*>(node));
    }

    BTreeNode<T>* root() const
    {
        return dynamic_cast< BTreeNode<T>* >(this->m_root);
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
        this->m_root = NULL;
    }

    ~BTree()
    {
        clear();
    }

};
}

#endif // BTREE_H
