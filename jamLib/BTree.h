#ifndef BTREE_H
#define BTREE_H
#include "BTreeNode.h"
#include "Tree.h"
#include "Exception.h"
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

    virtual bool insert( BTreeNode<T>* n, BTreeNode<T>* np, BTNodePos pos)
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

    virtual bool insert(TreeNode<T>* node, BTNodePos pos)
    {
        bool ret = true;
        if( node != NULL)
        {
            if( root() != NULL)
            {
                node->parent = NULL;
                this->m_root = node;
            }
            else
            {
                BTreeNode<T>* np = this->find(node->parent);
                if( np != NULL)
                {
                    ret = insert( dynamic_cast<BTreeNode<T>*>(node), np, pos);
                }
                else
                {
                    THROW_EXCEPTION( InvalidParameterException, "invalid parent tree node ...");
                }
            }
        }
        else
        {
            THROW_EXCEPTION( InvalidParameterException ," This paramter is NULL ...");
        }
        return ret;
    }

    virtual  bool insert(const T& value, TreeNode<T>* parent, BTNodePos pos)
    {
          bool ret = true;
          BTreeNode<T>* node = BTreeNode::NewNode();

          if( node != NULL)
          {
              node->parent = dynamic_cast<BTreeNode<T>*>(parent);
              node->value = value;

              ret = insert(node, pos);

              if( !ret )
              {
                  delete node; //插入不成功要删除，否则会引起内存泄漏！
              }
          }
          else
          {
              THROW_EXCEPTION(NoEnoughMemoryException, "no enought memory for BTreeNode...");
          }

          return ret;
     }

    bool insert(TreeNode<T>* node)
    {
        return insert(node, ANY);
    }

    bool insert(const T& value, TreeNode<T>* parent)
    {
        return insert( value, parent, ANY );
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
