#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "JString.h"
#include "LinkList.h"
#include "Sort.h"
#include "QueenPosition.h"
#include "Proxy.h"
#include "BTreeNode.h"
#include "BTree.h"
#include "Array.h"
#include "TreeNode.h"

using namespace std;
using namespace jamLib;


int main()
{


    BTree<int> bt;
    BTreeNode<int>* node = NULL;

    bt.insert(1, NULL);

    node = bt.find(1);
    bt.insert(2, node);
    bt.insert(3, node);

    node = bt.find(2);
    bt.insert(4, node);
    bt.insert(5, node);

    node = bt.find(3);
    bt.insert(6, node);
    bt.insert(7, node);

    node = bt.find(4);
    bt.insert(8, node);
    bt.insert(9, node);

    node = bt.find(5);
    bt.insert(10, node);

    cout << "print bt" << endl;
    SharedPointer<Array<int>> btp = bt.traversal(LevelOrder);
    for(int i=0; i<(*btp).length(); i++)
    {
        cout << (*btp)[i] << " ";
    }
    cout << endl;

    BTree<int> bt1;
    bt1.insert(0, NULL);

    node = bt1.find(0);
    bt1.insert(6, node);
    bt1.insert(2, node);

    node = bt1.find(2);
    bt1.insert(7, node);
    bt1.insert(8, node);

    cout << "print bt1" << endl;
    SharedPointer<Array<int>> btp1 = bt1.traversal(PreOrder);
    for(int i=0; i<(*btp1).length(); i++)
    {
        cout << (*btp1)[i] << " ";
    }
    cout << endl;

    SharedPointer<BTree<int>> nTree = bt.add(bt1);

    cout << "print nTree" << endl;
    SharedPointer<Array<int>> nTreep = (*nTree).traversal(LevelOrder);
    for(int i=0; i<(*nTreep).length(); i++)
    {
        cout << (*nTreep)[i] << " ";
    }
    cout << endl;

    BTreeNode<int>* br = bt.thread(LevelOrder);

    while(br->m_right != NULL)
    {
        cout << br->value << " ";

        br = br->m_right;

        if(br->m_right == NULL)
        {
             cout << br->value << " ";
        }

    }
     cout << endl;
    while( br != NULL)
    {
        cout << br->value << " ";
        br = br->m_left;
    }
    cout<< endl;
    return 0;
}


