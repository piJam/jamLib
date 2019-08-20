#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "JString.h"
#include "LinkList.h"
#include "Sort.h"
#include "QueenPosition.h"
#include "Proxy.h"
#include "GTreeNode.h"
#include "GTree.h"

using namespace std;
using namespace jamLib;


int main()
{
    GTree<int> gt;
    GTreeNode<int> l;

    GTreeNode<int>* gn = NULL;

    gt.insert(1, NULL);

    gn = gt.find(1);

    gt.insert(2, gn);
    gt.insert(3, gn);
    gt.insert(4, gn);

    gn = gt.find(2);
    gt.insert(5, gn);
    gt.insert(6, gn);

    gn = gt.find(5);
    gt.insert(11, gn);

    gt.remove(2);
    cout<< "-------------" << endl;

    for(gt.begin(); !gt.end(); gt.next())
    {
        cout<< gt.current() << endl;
    }

    return 0;
}


