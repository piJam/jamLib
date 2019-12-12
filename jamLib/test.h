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
//    LinkGraph<char, int> g(4);
//    g.setVertex(0, 'A');
//    g.setVertex(1, 'B');
//    g.setVertex(2, 'C');
//    g.setVertex(3, 'D');

    LinkGraph<char, int> g;
    g.addVertex('A');
    g.addVertex('B');
    g.addVertex('C');
    g.addVertex('D');

//  g.removeVertex();

    for( int i=0; i<g.vCount(); i++)
    {
        cout << "Vertex is" << g.getVertex(i) << endl;
    }

    g.setEdge(0, 1, 5);
    g.setEdge(0, 3, 5);
    g.setEdge(1, 2, 8);
    g.setEdge(2, 3, 2);
    g.setEdge(3, 1, 9);
    cout << "vCount = " << g.vCount() << "  eCount = " << g.eCount() << endl;

    cout << "w(0, 1)" << g.getEdge(0, 1) << endl;
    cout << "w(0, 3)" << g.getEdge(0, 3) << endl;
    cout << "w(1, 2)" << g.getEdge(1, 2) << endl;
    cout << "w(2, 3)" << g.getEdge(2, 3) << endl;
    cout << "w(3, 1)" << g.getEdge(3, 1) << endl;

    //删除边，然后获取边，抛异常
    //g.removeEdge(3, 1);
    //cout << "w(3, 1)" << g.getEdge(3, 1) << endl;

    //删除边，然后获取边的个数
    cout << "del Before : "<< g.eCount() << endl;
    g.removeEdge(3, 1);
    cout << "del After :"<< g.eCount() << endl;

    //获取0的邻接顶点
    SharedPointer< Array<int> > sp = g.getAdjacent(0);
    for(int i = 0; i<sp->length(); i++)
    {
        cout << "0 adjacent = " <<  (*sp)[i] << endl;
    }

    //1的入度和出度
    cout << "ID(1) = " << g.ID(1) << endl;
    cout << "OD(1) = " << g.OD(1) << endl;
    cout << "TD(1) = " << g.TD(1) << endl;

    //删除一条边
    g.removeVertex();
    cout << "eCount = " << g.eCount() << endl;
    cout << "w(0, 1)" << g.getEdge(0, 1) << endl;
    cout << "w(1, 2)" << g.getEdge(1, 2) << endl;
}
#endif // TEST_H
