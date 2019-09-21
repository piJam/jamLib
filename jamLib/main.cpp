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

using namespace std;
using namespace jamLib;


int main()
{

    BTree<int> bt;

    BTreeNode<int>* node = NULL;

    bt.insert(1, NULL);

    bt.insert(2, bt.find(1));
    bt.insert(3, bt.find(1));

    node = bt.find(2);
    bt.insert(4,node);
    bt.insert(5,node);

    node = bt.find(3);
    bt.insert(6,node);
    bt.insert(7,node);

    node = bt.find(6);
    bt.insert(8,node);
    bt.insert(9,node);

    node = bt.find(7);
    bt.insert(10,node);
    bt.insert(11,node);

    node = bt.find(10);
    bt.insert(12, node);

    int index[] = {4, 5, 8, 9, 10, 11, 12};

    for(int i=0; i<7; i++)
    {
        TreeNode<int>* node = bt.find(index[i]);
        while(node)
        {
            cout<< node->value << " ";
            node = node->parent;
        }
        cout << endl;
    }

    cout<< "bt count is "<< bt.count() << endl;
/*
    SharedPointer< Tree<int> > sp = bt.remove(6);

    cout << endl;

    for(int i=0; i<6; i++)
    {
        TreeNode<int>* node = bt.find(index[i]);

        while(node)
        {

            cout<< node->value << " ";
            node = node->parent;
        }

        cout << endl;
    }
       cout<< "bt count is "<< bt.count() << endl;
       cout<< "bt height is "<< bt.height() << endl;
       cout<< "bt degree is "<< bt.degree() << endl;
*/
       for(bt.begin(); !bt.end(); bt.next())
       {
           cout<< bt.current() << " ";
       }

       cout << endl;
    return 0;
}


