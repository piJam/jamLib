#ifndef BTREE_H
#define BTREE_H
#include "BTreeNode.h"
#include "Tree.h"
#include "Exception.h"
#include "LinkQueue.h"
#include "Array.h"
#include "DynamicArray.h"

namespace jamLib {

enum BTtraversal
{
    PreOrder,
    InOrder,
    PostOrder,
    LevelOrder
};

template<typename T>
class BTree : public Tree<T>
{
protected:
    LinkQueue< BTreeNode<T>* > m_queue;

    virtual BTreeNode<T>* find(BTreeNode<T>* node, const T& value) const
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
        bool ret = true;

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
            if( np->m_right == NULL)
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

    virtual void remove( BTreeNode<T>* node, BTree<T>*& ret)
    {
        ret = new BTree<T>();

        if( ret != NULL)
        {
            if( node == this->root() )
            {
                this->m_root = NULL;
            }
            else
            {
                BTreeNode<T>* parent = dynamic_cast<BTreeNode<T>*>(node->parent);

                if(parent->m_left == node)
                {
                    parent->m_left = NULL;
                }
                else if(parent->m_right == node)
                {
                    parent->m_right = NULL;
                }

                node->parent = NULL;
            }

            ret->m_root = node; //作为子树返回
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, " no memory create ret...");
        }

    }

    virtual void free( BTreeNode<T>* node)
    {
        if( node != NULL)
        {
            free(node->m_left);
            free(node->m_right);

            if( node->flag() )
            {
                delete node;
            }

        }
    }

    int count( BTreeNode<T>* node ) const
    {
        int ret = 0;

        if(node != NULL)
        {
           ret = count(node->m_left) + count(node->m_right) + 1;
        }

        return ret;
    }

    int height( BTreeNode<T>* node ) const
    {
        int ret = 0;
        if(node != NULL)
        {
            int lh = height(node->m_left);
            int rh = height(node->m_right);

            ret = ((lh > rh)? lh : rh) + 1;
        }

        return ret;
    }

    int degree( BTreeNode<T>* node) const
    {
        int ret = 0;

        if( node != NULL)
        {
            BTreeNode<T>* child[] = {node->m_left, node->m_right};

            ret = (!!node->m_left) + (!!node->m_right);

            for(int i=0; (i<2) && (ret<2); i++)
            {
                int d = degree( child[i] );

                if(d > ret)
                {
                    ret = d;
                }
            }

          /*
           * 不够高效
           * int ld = degree(node->m_left);
           int rd = degree(node->m_right);

           ret = (!!node->m_left + !!node->m_right);

           if( ld > ret )
           {
               ret = ld;
           }

           if( rd > ret )
           {
               ret = rd;
           }*/
        }
        return ret;
    }

    void preOrderTraversal(BTreeNode<T>* node, LinkQueue< BTreeNode<T>* >& queue)
    {
        if(node != NULL)
        {
            queue.add(node);
            preOrderTraversal(node->m_left, queue);
            preOrderTraversal(node->m_right,queue);
        }
    }

    void inOrderTraversal(BTreeNode<T>* node, LinkQueue< BTreeNode<T>* >& queue)
    {
        if(node != NULL)
        {
            inOrderTraversal(node->m_left, queue);
            queue.add(node);
            inOrderTraversal(node->m_right, queue);
        }
    }

    void postOrderTraversal(BTreeNode<T>* node, LinkQueue< BTreeNode<T>* >& queue)
    {
        if(node != NULL)
        {
            postOrderTraversal(node->m_left,queue);
            postOrderTraversal(node->m_right,queue);
            queue.add(node);
        }
    }

    void levelOrderTraversal(BTreeNode<T>* node, LinkQueue< BTreeNode<T>* >& queue)
    {
        if(node != NULL)
        {
            LinkQueue<BTreeNode<T>*> temp;

            temp.add(node);

            while (temp.lenght() > 0)
            {
                BTreeNode<T>* n = temp.front();

                if(n->m_left != NULL)
                {
                    temp.add(n->m_left);
                }

                if(n->m_right != NULL)
                {
                    temp.add(n->m_right);
                }

                temp.remove();
                queue.add(n);
            }
        }
    }

    BTreeNode<T>* clone(BTreeNode<T>* node) const
    {
        BTreeNode<T>* ret =  NULL;
        if( node != NULL)
        {
            ret =BTreeNode<T>::NewNode();

            if( ret != NULL)
            {
                ret->value = node->value;

                ret->m_left = clone(node->m_left);
                ret->m_right = clone(node->m_right);

                if( ret->m_left != NULL)
                {
                    ret->m_left->parent = ret;
                }

                if(ret->m_right != NULL)
                {
                    ret->m_right->parent = ret;
                }

            }else
            {
                THROW_EXCEPTION(NoEnoughMemoryException,"no enough memory create BTreeNode...");
            }
        }

        return ret;
    }

    bool equal(BTreeNode<T>* lh, BTreeNode<T>* rh) const
    {

        if( lh == rh)
        {
            return true;

        }else if( ( lh != NULL ) && ( rh != NULL ) )
        {
            return (lh->value == rh->value) && equal(lh->m_left, rh->m_left) && equal(lh->m_right, rh->m_right);

        }else
        {
            return false;
        }
    }

    BTreeNode<T>* add( BTreeNode<T>* lh,  BTreeNode<T>* rh) const
    {
        BTreeNode<T>* ret = NULL;

        if( (lh != NULL) && (rh == NULL) )
        {
            ret = clone(lh);

        }else if ( (lh == NULL) && (rh != NULL) ){

            ret = clone(rh);

        }else if( (lh != NULL) && (rh != NULL) )
        {
            ret =  BTreeNode<T>::NewNode();

            if( ret != NULL)
            {
                ret->value = ( lh->value) + ( rh->value );

                ret->m_left = add(lh->m_left, rh->m_left);
                ret->m_right = add(lh->m_right, rh->m_right);

                if(ret->m_left != NULL)
                {
                    ret->m_left->parent = ret;
                }
                if(ret->m_right != NULL)
                {
                    ret->m_right->parent = ret;
                }
             }else{

                THROW_EXCEPTION(NoEnoughMemoryException, "no enough memory ....");
            }

        }
        return ret;
    }

    void traversal(BTtraversal order, LinkQueue< BTreeNode<T>* >& queue)
    {

        switch (order) {
            case PreOrder:
                preOrderTraversal(root(), queue);
                break;

            case InOrder:
                inOrderTraversal(root(), queue);
                break;

            case PostOrder:
                postOrderTraversal(root(), queue);
                break;

            case LevelOrder:
                levelOrderTraversal(root(), queue);
                break;

            default:
                THROW_EXCEPTION(InvalidParameterException,"paramter is invalid...");
                break;
        }

    }
public:

    virtual bool insert(TreeNode<T>* node, BTNodePos pos)
    {
        bool ret = true;
        if( node != NULL)
        {
            if( root() == NULL)
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
          BTreeNode<T>* node = BTreeNode<T>::NewNode();

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
        BTree<T>* ret = NULL;

        BTreeNode<T>* node = find(value);

        if( node != NULL)
        {
            remove(node, ret);
            m_queue.clear();
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, " paramter value is invalid..." );
        }
        return ret;
    }

    SharedPointer< Tree<T> > remove(TreeNode<T>* node)
    {
        BTree<T>* ret = NULL;

        node = this->find(node);

        if( node != NULL)
        {
            remove(dynamic_cast<BTreeNode<T>*>(node), ret);
             m_queue.clear();
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, " parameter node is invalid...");
        }

        return ret;
    }

    BTreeNode<T>* find(const T& value) const
    {
        return find(root(), value);
    }

    BTreeNode<T>* find(TreeNode<T> * node) const
    {
        return find(root(), dynamic_cast<BTreeNode<T>*>(node));
    }

    BTreeNode<T>* root() const
    {
        return dynamic_cast< BTreeNode<T>* >(this->m_root);
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
        free(root());
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
            BTreeNode<T>* node = m_queue.front();

            m_queue.remove();

            if(node->m_left != NULL)
            {
                m_queue.add(node->m_left);
            }

            if(node->m_right != NULL)
            {
                m_queue.add(node->m_right);
            }

        }

        return ret;
    }

    SharedPointer< Array<T> > traversal(BTtraversal order)
    {
        SharedPointer< Array<T> > ret = NULL;
        LinkQueue< BTreeNode<T>* > queue;

        traversal(order, queue);

        ret = new DynamicArray<T>(queue.lenght());

        if(ret != NULL)
        {
            for(int i=0; i<ret->length(); i++, queue.remove())
            {
                ret->set(i, queue.front()->value);
            }

        }else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"no memory create to DynamicArray...");
        }

        return ret;
    }

    SharedPointer< BTree<T> > clone()
    {
        BTree<T>* ret = new BTree<T>();

        if( ret != NULL)
        {
            ret->m_root = clone(root());

        }else{

            THROW_EXCEPTION(NoEnoughMemoryException,"no memory create tree...");

        }


        return ret;
    }

    SharedPointer< BTree<T> > add(const BTree<T>& btree) const
    {
        BTree<T>* ret = new BTree<T>();
        if( ret != NULL )
        {
            ret->m_root = add(root(), btree.root());
        }else {
            THROW_EXCEPTION(NoEnoughMemoryException,"no enough memory...");
        }
        return ret;
    }

    bool operator == (const BTree<T>& tree)
    {

        return  equal(this->root(), tree.root());
    }

    bool operator != (const BTree<T>& tree)
    {
        return !( *this == tree );
    }

    //将队列转换为双向链表
    BTreeNode<T>* connect(LinkQueue<BTreeNode<T>*>& queue)
    {

        BTreeNode<T>* ret = NULL;
        if( queue.lenght() > 0)
        {
            ret = queue.front();
            BTreeNode<T>* slider = queue.front();
            ret->m_left = NULL;
            queue.remove();

            while(queue.lenght() > 0)
            {
                slider->m_right = queue.front();

                queue.front()->m_left = slider;

                slider = queue.front();

                queue.remove();
            }
            slider->m_right = NULL;

        }
        return ret;
    }

    //二叉树线索化
    BTreeNode<T>* thread(BTtraversal Order)
    {
        BTreeNode<T>* ret = NULL;
        LinkQueue<BTreeNode<T>*> queue;

        traversal(Order, queue);   
        ret = connect(queue);
        this->m_root = NULL; //将二叉树置为空

        queue.clear(); //  可不执行这一步，在connect函数中已经对每一个元素remove了

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
    ~BTree()
    {
        clear();
    }

};
}

#endif // BTREE_H
