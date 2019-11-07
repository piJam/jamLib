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
    bt.insert(6,node);
    bt.insert(7,node);

    node = bt.find(4);
    bt.insert(8, node);
    bt.insert(9, node);

    node = bt.find(5);
    bt.insert(10, node);

    for(bt.begin(); !bt.end();bt.next())
    {
        cout << bt.current() << ",";
    }
    cout<< endl;



    SharedPointer< BTree<int> > sp = bt.clone();

    for((*sp).begin(); !(*sp).end(); (*sp).next())
    {
        cout << (*sp).current() << ",";
    }
    cout<< endl;


    return 0;
}


