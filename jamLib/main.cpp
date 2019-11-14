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
#include "BTreeExample.h"

using namespace std;


int main()
{

    BTreeNode<int>* n = BTreeExample<int>::createBTree();
    BTreeExample<int>::printInOrder(n);
    cout << endl;
    BTreeExample<int>::printInOrder( BTreeExample<int>::delNode(n) );
    cout << endl;

    return 0;
}


