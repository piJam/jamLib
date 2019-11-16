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
        cout << "node adr: "<< &node << endl;
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

    //test
    static void delBTreeNodeSingle()
    {
        BTreeNode<int>* n = BTreeExample<int>::createBTree();
        cout << "n ard:" << &n << endl;
        BTreeExample<int>::printInOrder(n);
        cout << endl;
        /*
        BTreeExample<int>::delNode2(n);
        BTreeExample<int>::printInOrder(n);
        */

        BTreeExample<int>::printInOrder(BTreeExample<int>::delNode(n));
        cout << endl;

    }


};

#endif // BTREEEXAMPLE_H
