#ifndef BTREEEXAMPLE_H
#define BTREEEXAMPLE_H
#include "BTreeNode.h"
#include "BTree.h"
using namespace std;
using namespace jamLib;

template< typename T>
class BTreeExample
{
public:
    //创建一个树，在静态区
    static BTreeNode<T>* createBTree()
    {
        static BTreeNode<int> bn[9];
        for(int i=0; i<9; i++)
        {
            bn[i].value = i;
            bn[i].parent = NULL;
            bn[i].m_left = NULL;
            bn[i].m_right = NULL;
        }

        bn[0].m_left = &bn[1];
        bn[0].m_right = &bn[2];
        bn[1].parent = &bn[0];
        bn[2].parent = &bn[0];

        bn[1].m_left = &bn[3];
        bn[3].parent = &bn[1];

        bn[2].m_left = &bn[4];
        bn[2].m_right = &bn[5];
        bn[4].parent = &bn[2];
        bn[5].parent = &bn[2];

        bn[3].m_right = &bn[6];
        bn[6].parent = &bn[3];

        bn[4].m_left = &bn[7];
        bn[7].parent = &bn[4];

        bn[5].m_left = &bn[8];
        bn[8].parent = &bn[5];

        return bn;
    }

    //删除度为1的节点
    static  BTreeNode<T>* delNode(BTreeNode<T>*& node)
    {

        if(node != NULL)
        {
            if( ((node->m_left != NULL) && (node->m_right == NULL)) || ((node->m_left == NULL) && (node->m_right != NULL)) )
            {

                BTreeNode<T>* parent = dynamic_cast<BTreeNode<T>*>(node->parent);
                BTreeNode<T>* nchild = (node->m_left != NULL) ? node->m_left : node->m_right ;

                if( parent != NULL)
                {

                   BTreeNode<T>*& parentChild = parent->m_left == node ? parent->m_left : parent->m_right; //这是使用指针的引用，相当于直接操作上一级节点的子节点
                   parentChild = nchild;

                   // BTreeNode<T>** parentChild = &(parent->m_left == node ? parent->m_left : parent->m_right);
                   // *parentChild = nchild;
                    nchild->parent = parent;

                }else
                {
                   nchild->parent = NULL;
                }

                if(node->flag())
                {
                    delete node;
                }

                delNode(nchild);
            }
            else
            {
                delNode(node->m_left);
                delNode(node->m_right);
            }
        }

        return node;
    }

    //删除度为1的节点，没有parent指针
    static void delNode2(BTreeNode<T>*& node)
    {
        if(node != NULL)
        {
            if( ((node->m_left != NULL) && (node->m_right == NULL)) || ((node->m_left == NULL) && (node->m_right != NULL)) )
            {
                BTreeNode<T>* node_child = (node->m_left != NULL) ? (node->m_left) : (node->m_right);

                if(node->flag())
                {
                    delete node;
                }

                node = node_child;

                delNode2(node);

            }else {
                delNode2(node->m_left);
                delNode2(node->m_right);
            }
        }
    }

    //中序遍历
    static  void printInOrder(BTreeNode<T>* node)
    {
        if(node != NULL)
        {
            printInOrder( node->m_left );
            cout << node->value << " " ;
            printInOrder( node->m_right );
        }

    }

    //打印双向链表
    static void printDualLink(BTreeNode<T>* node)
    {
        while( node!= NULL )
        {
            cout << node->value << " ";
            node = node->m_right;
        }

    }

    //test
    static void delBTreeNodeSingle()
    {
        BTreeNode<int>* n = createBTree();

        printInOrder(n);
        cout << endl;
        /*
        delNode2(n);
        printInOrder(n);
        */

        printInOrder( delNode(n) );

        cout << endl;

        n = Thread(n);

        printDualLink(n);

        cout << endl;
    }


   static BTreeNode<T>* Thread(BTreeNode<T>* node)
    {
        BTreeNode<T>* pre = NULL;
        InOderThread(node, pre);

        while( (node != NULL) && (node->m_left != NULL) )
        {
            node = node->m_left;
        }
        return node;
    }

   static void InOderThread(BTreeNode<T>* node, BTreeNode<T>*& pre)
    {
        if( node != NULL)
        {
            InOderThread(node->m_left, pre);
            node->m_left = pre;

            if(pre != NULL)
            {
                 pre->m_right = node;
            }

            pre = node;
            InOderThread(node->m_right, pre);
        }

    }

   static void InOderThreads(BTreeNode<T>* node, BTreeNode<T>*& head, BTreeNode<T>*& tail)
   {
       if( node != nullptr )
       {
           BTreeNode<T>* h = nullptr;
           BTreeNode<T>* t = nullptr;

           InOderThreads(node->m_left, h , t);
           node->m_left = t;
           if( t != nullptr)
           {
                t->m_right = node;
           }


           head = (h != nullptr) ? h : node;          

           h = nullptr;
           t = nullptr;

           InOderThreads(node->m_right, h ,t);

           node->m_right = h;
           if( h!= nullptr )
           {
                h->m_left = node;
           }
           tail = (t != nullptr) ? t : node;
       }
   }

   static BTreeNode<T>* InOderThread2(BTreeNode<T>* node)
   {
       BTreeNode<T>* head = NULL;
       BTreeNode<T>* tail = NULL;

       InOderThreads(node, head, tail);

       return head;
   }

};

#endif // BTREEEXAMPLE_H
