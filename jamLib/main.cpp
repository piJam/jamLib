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
    LinkList<int> lk;
    for(int i=0; i<1010; i++)
    {
         lk.insert(i);
    }

    for(lk.move(1); !lk.end(); lk.next())
    {
        cout << lk.current() << endl;
    }

    return 0;
}


