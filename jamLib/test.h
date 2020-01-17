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

   SharedPointer< Array<int> > sp1 = g.DFS(0);

    for(int i=0; i<sp1->length(); i++)
    {
         cout<< (*sp1)[i] << ' ';
    }
    cout << endl;


    SharedPointer< Array<int> > sp = g.DFSByRecursion(0);

    for(int i=0; i<sp->length(); i++)
    {
         cout<< (*sp)[i] << ' ';
    }
    cout << endl;


}

void testPrim()
{
//// 矩阵图测试
//    MatrixGraph<4, int, int> g;
//    g.setEdge(0, 1, 1);
//    g.setEdge(1, 0, 1);

//    g.setEdge(0, 2, 3);
//    g.setEdge(2, 0, 3);

//    g.setEdge(1, 2, 1);
//    g.setEdge(2, 1, 1);

//    g.setEdge(1, 3, 4);
//    g.setEdge(3, 1, 4);

//    g.setEdge(2, 3, 1);
//    g.setEdge(3, 2, 1);


    //邻接图测试
    LinkGraph<int,int> g(9);

    g.setEdge(0, 1, 10);
    g.setEdge(1, 0, 10);

    g.setEdge(0, 5, 11);
    g.setEdge(5, 0, 11);

    g.setEdge(1, 2, 18);
    g.setEdge(2, 1, 18);

    g.setEdge(1, 8, 12);
    g.setEdge(8, 1, 12);

    g.setEdge(1, 6, 16);
    g.setEdge(6, 1, 16);

    g.setEdge(2, 3, 22);
    g.setEdge(3, 2, 22);

    g.setEdge(2, 8, 8);
    g.setEdge(8, 2, 8);

    g.setEdge(3, 8, 21);
    g.setEdge(8, 3, 21);

    g.setEdge(3, 6, 24);
    g.setEdge(6, 3, 24);

    g.setEdge(3, 7, 16);
    g.setEdge(7, 3, 16);

    g.setEdge(3, 4, 20);
    g.setEdge(4, 3, 20);

    g.setEdge(4, 5, 26);
    g.setEdge(5, 4, 26);

    g.setEdge(4, 7, 7);
    g.setEdge(7, 4, 7);

    g.setEdge(5, 6, 17);
    g.setEdge(6, 5, 17);

    g.setEdge(6, 7, 19);
    g.setEdge(7, 6, 19);


//    SharedPointer< Array<Edge<int>> > sp = g.Prim(999);
    SharedPointer< Array<Edge<int>> > sp = g.Kruskal();

    int index = 0;
    for(int i=0; i<(*sp).length(); i++)
    {
        index +=  (*sp)[i].data ;
        cout << (*sp)[i].m_start << "->" << (*sp)[i].m_end << " w = " << (*sp)[i].data << endl;
    }
    cout << "w = " << index << endl;
}

void testDijkstra()
{

    LinkGraph<int, int> g(5);

    g.setEdge(0, 1, 10);
    g.setEdge(0, 3, 30);
    g.setEdge(0, 4, 100);

    g.setEdge(1, 2, 50);

    g.setEdge(2, 4, 10);

    g.setEdge(3, 2, 20);
    g.setEdge(3, 4, 60);

    SharedPointer< Array<int> > p = g.dijkstra(0, 4, 65535);


    for(int i=0; i<p->length(); i++)
    {
        cout << (*p)[i] << " ";
    }

    cout << endl;

}

void testFloyd()
{
    LinkGraph<int, int> g(3);

    g.setEdge(0, 1, 4);
    g.setEdge(0, 2, 11);

    g.setEdge(1, 2, 2);
    g.setEdge(1, 0, 6);

    g.setEdge(2, 0, 3);

    SharedPointer< Array<int> > p = g.floyd(0, 2, 65535);

    for(int i=0; i<p->length(); i++)
    {
       cout << (*p)[i] << " ";
    }

    cout << endl;
}

//最长不下降序列
//创建根据数组创建图，数值小的元素，指向大的元素
template<typename V>
SharedPointer< Graph<V, int> > create_graph(V* v, int len)
{
     LinkGraph<V, int>* ret = new LinkGraph<V, int>(len);

     for(int i=0; i<len; i++)
     {
         ret->setVertex(i, v[i]);

         for(int j=i+1; j<len; j++)
         {
             if(v[i] < v[j])
             {
                 ret->setEdge(i, j, 1);
             }
         }
     }

     return ret;
}

//寻找最大的路径
template<typename V>
int search_max_path(Graph<V, int>& g, int v, Array<int>& count, Array< LinkList<int>* >& path, Array<bool>& mark)
{
    int ret = 0;

    SharedPointer< Array<int> > aj = g.getAdjacent(v);

    for(int i=0; i<aj->length(); i++)
    {
        int num = 0;

        if( !mark[(*aj)[i]] )
        {
            num = search_max_path(g, (*aj)[i], count, path, mark);
        }
        else
        {
            num = count[(*aj)[i]];
        }

        if( ret < num )
        {
            ret = num;
        }
    }

    for(int i=0; i<aj->length(); i++)
    {
        if( ret == count[(*aj)[i]] )
        {
            path[v]->insert((*aj)[i]);
        }
    }

    ret++;

    count[v] = ret;
    mark[v] = true;

    return ret;
}

template <typename V>
void search_max_path(Graph<V, int>& g, Array<int>& count, Array< LinkList<int>* >& path, Array<bool>& mark)
{
    for (int i=0; i<g.vCount(); i++)
    {
        if( !mark[i] )
        {
           search_max_path(g, i, count, path, mark);
        }

    }
}

//初始化数组
void init_array(Array<int>& count, Array< LinkList<int>* >& path, Array<bool>& mark)
{
    for(int i=0; i<count.length(); i++)
    {
        count[i] = 0;
    }

    for(int i=0; i<path.length(); i++)
    {
        path[i] = new LinkList<int>();
    }

    for(int i=0; i<mark.length(); i++)
    {
        mark[i] = false;
    }
}


//打印
template < typename V >
void print_path(Graph<V, int>& g, int v, Array< LinkList<int>* >& path, LinkList<int>& cp)
{
    cp.insert(v);

    if( path[v]->length() > 0 )
    {
        for(path[v]->move(0); !path[v]->end(); path[v]->next())
        {
            print_path(g, path[v]->current(), path, cp);
        }
    }
    else
    {
        cout << "Element: ";

        for(cp.move(0); !cp.end(); cp.next())
        {
            cout << g.getVertex(cp.current()) << " ";
        }

        cout << endl;
    }

    cp.remove(cp.length() - 1);
}


template<typename V>
void print_max_path(Graph<V, int>& g, Array<int>& count, Array< LinkList<int>* >& path)
{
    int max = 0;

    LinkList<int> cp;

    for(int i=0; i<count.length(); i++)
    {
        if(max < count[i])
        {
            max = count[i];
        }
    }

    cout << "len :" << max << endl;

    for(int i=0; i<count.length(); i++)
    {
        if( max == count[i] )
        {
            print_path(g, i, path, cp);

        }
    }


}

//最长不下降序列,组合方法
template<typename V>
void solution(int* a, int len)
{

    DynamicArray<int> count(len);
    DynamicArray< LinkList<int>* > path(len);
    DynamicArray<bool> mark(len);

    SharedPointer< Graph<V, int> > g;

    g = create_graph<V>(a, len);

    init_array(count, path, mark);

    search_max_path(*g, count, path, mark);

    print_max_path(*g, count, path);

}



#endif // TEST_H
