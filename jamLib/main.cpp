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

     bt.insert(4, NULL);


    return 0;
}


