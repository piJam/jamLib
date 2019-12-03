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
#include "MatrixGraph.h"

using namespace std;


int main()
{
    MatrixGraph<3, int, int> g;

    g.setEdge(0, 1, 1);
    g.setEdge(1, 0, 2);
    g.setEdge(1, 2, 3);

    cout<< "vCount:" << g.vCount() << endl;
    cout<< "eCount:" << g.eCount() << endl;
    cout<< "ID(1):" << g.ID(1) << endl;
    cout<< "OD(1):" << g.OD(1) << endl;
    cout<< "TD(1):" << g.TD(1) << endl;
    return 0;
}


