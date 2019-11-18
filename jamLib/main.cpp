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
    BTreeNode<int>* bn = BTreeExample<int>::createBTree();
    BTreeExample<int>::printInOrder(bn);
    cout << endl;
    BTreeExample<int>::printDualLink(BTreeExample<int>::InOderThread2(bn));
    return 0;
}


