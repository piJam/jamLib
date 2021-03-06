#ifndef GTREE_H
#define GTREE_H
#include "TreeNode.h"
#include "GTreeNode.h"
#include "Tree.h"
#include "Exception.h"
#include "LinkQueue.h"


namespace jamLib

{
template<typename T>
class GTree : public Tree<T>
{
protected:
    LinkQueue< GTreeNode<T>* > m_queue;

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

    void free(GTreeNode<T>* node)
    {
        if( node != NULL)
        {
            for( node->child.move(0); !node->child.end(); node->child.next())
            {
                free(node->child.current());
            }

            if(node->flag())
            {
                delete node;
            }

        }
    }

    void remove(GTreeNode<T>* node, GTree<T>*& ret) //GTree<T>*& 指针类型的别名（引用）
    {
        ret = new GTree<T>();
        if(ret != NULL)
        {
            if(node == root())
            {
                this->m_root = NULL;
            }
            else
            {

                LinkList<GTreeNode<T>*>& childs = dynamic_cast<GTreeNode<T>*>(node->parent)->child;

                childs.remove(childs.find(node));

                node->parent = NULL;
            }

            ret->m_root = node;//作为子树返回
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "no memory create new Tree...");
        }
    }

    int count(GTreeNode<T>* node) const
    {
        int ret = 0;
        if(node != NULL)
        {
            ret = 1;
            for(node->child.move(0); !node->child.end(); node->child.next() )
            {
                ret += count(node->child.current());
            }
        }
        return ret;
    }

    int height(GTreeNode<T>* node) const
    {
        int ret = 0;
        if(node != NULL)
        {
            for(node->child.move(0); !node->child.end(); node->child.next())
            {
                int h = height(node->child.current());

                if(ret < h)
                {
                    ret = h;
                }
            }

            ret = ret + 1;
        }
        return ret;
    }

    int degree(GTreeNode<T>* node) const
    {
        int ret = 0;
        if(node != NULL)
        {
            ret = node->child.length();

            for(node->child.move(0); !node->child.end(); node->child.next())
            {
                int d = degree(node->child.current());

                if(ret < d)
                {
                    ret = d;
                }
            }
        }

        return ret;
    }
public:
    GTree<T>(){}

    bool insert(TreeNode<T>* node)
    {
        bool ret = true;
        if(node != NULL)
        {
            if(this->m_root == NULL) //等于null为首节点
            {
                node->parent = NULL;
                this->m_root = node;
            }
            else
            {
                GTreeNode<T>* np = find(node->parent);
                if( np != NULL)
                {
                    GTreeNode<T>* n = dynamic_cast< GTreeNode<T>* >(node);

                    if(np->child.find(n) < 0) //查找该节点下子节点重不重复
                    {
                        np->child.insert( n );
                    }
                }
                else
                {
                    THROW_EXCEPTION(InvalidOperationException, "parent is null in this tree...");
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
        GTreeNode<T>* gn = GTreeNode<T>::newNode();

        if(gn != NULL)
        {
            gn->parent = parent;
            gn->value = value;
            insert(gn);
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "no memory for gn...");
        }

        return ret;
    }

    SharedPointer< Tree<T> > remove(const T& value)
    {


        GTree<T>* ret = NULL;

        GTreeNode<T>* node = this->find(value);

        if(node != NULL)
        {
            remove(node, ret);
            m_queue.clear();
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "this value is invalid...");
        }

        return ret;
    }

    SharedPointer< Tree<T> > remove(TreeNode<T>* node)
    {
        GTree<T>* ret = NULL;

        node = this->find(node);

        if(node != NULL)
        {
            remove(dynamic_cast<GTreeNode<T>*>(node), ret);
            m_queue.clear();
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "this value is invalid...");
        }

        return ret;
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
        return degree(root());
    }

    int count() const
    {
        return count(root());
    }

    int height() const
    {
        return height(root());
    }
    void clear()
    {
        this->free(root());
        m_queue.clear();

        this->m_root = NULL;


    }

    bool begin()
    {
        bool ret = root();

        if(ret)
        {
            m_queue.clear();
            m_queue.add(root());
        }
        return ret;
    }

    bool end()
    {
        return (m_queue.lenght() == 0);
    }

    bool next()
    {
        bool ret = (m_queue.lenght() > 0);

        if(ret)
        {
            GTreeNode<T>* node = m_queue.front();

            m_queue.remove();

            for(node->child.move(0); !node->child.end(); node->child.next())
            {
                m_queue.add(node->child.current());
            }
        }

        return ret;
    }

    T current()
    {
        if(!end())
        {
            return m_queue.front()->value;
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "queue no elements...");
        }
    }

    ~GTree()
    {
        clear();
    }

};
}
#endif // GTREE_H
