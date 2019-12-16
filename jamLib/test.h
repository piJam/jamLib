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
#include "SmartPoint.h"
using namespace std;

void testSmartPoint()
{
    SmartPoint<int> sp = new int[10];

    sp.operator ->()[0] = 1000;
    (&(*sp))[1] = 99; // *sp  取到数组第一个值， &（*sp）则取到数组的首地址，然后[] 运算
    cout << sp.operator ->() << " " << *sp << endl;
    cout << sp.get()[0] << " " << (&(*sp))[1]  << endl;
}

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
    cout<< "w(1, 2):" << g.getEdge(1, 2) << endl;

    SharedPointer< Array<int> > aj = g.getAdjacent(1);

    for(int i=0; i<aj->length(); i++)
    {
        cout << "Adjacent = " << (*aj)[i] << " ";
    }
    cout << endl;

    cout<< "delete Edge:" << endl;

    g.removeEdge(0, 1);

    cout<< "eCount:" << g.eCount() << endl;

    g.setVertex(0, 100);

    cout << "v(0)" << g.getVertex(0) << endl;

//    cout<< "W(0, 1):" << g.getEdge(0, 1) << endl; //边删除后，重新使用这条边会报错
}

void testLinkGarph()
{
    LinkGraph<char, int> g(4);
    g.setVertex(0, 'A');
    g.setVertex(1, 'B');
    g.setVertex(2, 'C');
    g.setVertex(3, 'D');

//    LinkGraph<char, int> g;
//    g.addVertex('A');
//    g.addVertex('B');
//    g.addVertex('C');
//    g.addVertex('D');

  g.removeVertex();

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

void testBFS()
{
    MatrixGraph<9, char, int> g;
    const char* VD = "ABCDEFGHI";

    for(int i=0; i<9; i++)
    {
        g.setVertex(i, VD[i]);

    }

    g.setEdge(0, 1, 0); //无向边用0表示权值
    g.setEdge(1, 0, 0);

    g.setEdge(0, 3, 0);
    g.setEdge(3, 0, 0);

    g.setEdge(0, 4, 0);
    g.setEdge(4, 0, 0);

    g.setEdge(1, 2, 0);
    g.setEdge(2, 1, 0);

    g.setEdge(1, 4, 0);
    g.setEdge(4, 1, 0);

    g.setEdge(2, 5, 0);
    g.setEdge(5, 2, 0);

    g.setEdge(3, 6, 0);
    g.setEdge(6, 3, 0);

    g.setEdge(4, 6, 0);
    g.setEdge(6, 4, 0);

    g.setEdge(6, 7, 0);
    g.setEdge(7, 6, 0);

    g.setEdge(7, 8, 0);
    g.setEdge(8, 7, 0);

   // SharedPointer< Array<int> > sp = g.BFS(0);

   SharedPointer< Array<int> > sp = g.DFS(0);

    for(int i=0; i<sp->length(); i++)
    {
         cout<< (*sp)[i] << ' ';
    }
    cout << endl;

    g.DFSByRecursion(g, 0);
}
#endif // TEST_H
