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
    GTree<int> st;
    GTreeNode<int> gn;

    st.find(12);
    st.find(&gn);
    return 0;
}


