#ifndef TEST_H
#define TEST_H
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
#include "LinkGraph.h"
using namespace std;

void testMatrixGraph()
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

    cout<< "W(0, 1):" << g.getEdge(0, 1) << endl;
    cout<< "w(1, 0):" << g.getEdge(1, 0) << endl;
    cout << "w(1, 2):" << g.getEdge(1, 2) << endl;

    SharedPointer< Array<int> > aj = g.getAdjacent(2);

    for(int i=0; i<aj->length(); i++)
    {
        cout << (*aj)[i] << " ";
    }
    cout << endl;

    cout<< "delete Edge:" << endl;

    g.removeEdge(0, 1);

    cout<< "eCount:" << g.eCount() << endl;

    g.setVertex(0, 100);

    cout << "v(0)" << g.getVertex(0) << endl;

    cout<< "W(0, 1):" << g.getEdge(0, 1) << endl; //边删除后，重新使用这条边会报错
}

void testLinkGarph()
{
    LinkGraph<char, int> g(4);
    g.setVertex(0, 'A');
    g.setVertex(1, 'B');
    g.setVertex(2, 'C');
    g.setVertex(3, 'D');


}
#endif // TEST_H
