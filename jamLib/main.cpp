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

    SharedPointer<Array<int>> btsp = bt.traversal(preOrder);
    for(int i=0; i<(*btsp).length(); i++)
    {
        cout << (*btsp)[i] <<" ";
    }
    cout<< endl;


    BTree<int> bs;
    bs.insert(10, NULL);

    node = bs.find(10);
    bs.insert(9 ,node);
    bs.insert(8, node);

    node = bs.find(9);
    bs.insert(7, node);

    node = bs.find(8);
    bs.insert(6, node);

    SharedPointer< BTree<int> > ss = bs.clone();
    SharedPointer<Array<int>> ssp = (*ss).traversal(preOrder);
    for(int i=0; i<(*ssp).length(); i++)
    {
        cout << (*ssp)[i] <<" ";
    }
    cout<< endl;



    SharedPointer<Array<int>> bssp = bs.traversal(preOrder);
    for(int i=0; i<(*bssp).length(); i++)
    {
        cout << (*bssp)[i] <<" ";
    }
    cout<< endl;

    SharedPointer< BTree<int> > bb = bs.add(*ss);

    //---add 加法有问题
    SharedPointer<Array<int>> bbsp = (*bb).traversal(preOrder);
    for(int i=0; i<(*bbsp).length(); i++)
    {
        cout << (*bbsp)[i] <<" ";
    }
    cout<< endl;



    return 0;
}


