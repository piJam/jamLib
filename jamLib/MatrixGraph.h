#ifndef MATRIXGRAPH_H
#define MATRIXGRAPH_H
#include "Graph.h"
#include "DynamicArray.h"

template < int N, typename E, typename V >
class MatrixGraph : public Graph<V, E>
{
protected:
    V* m_vertexes[N];
    E* m_edges[N][N];
    int m_eCount;
public:
    MatrixGraph()
    {
        for(int i=0; i<N ; i++)
        {
            m_vertexes[i] = nullptr;
            for(int j=0; j<N; j++)
            {
                m_edges[i][j] = nullptr;
            }
        }
        m_eCount = 0;
    }

    V getVertex(int i)
    {
        V* ret;
        bool i = ((0<=i) && (i < eCount()));

        if( i )
        {
            ret = m_vertexes[i];
        }
        return *ret;
    }
    virtual bool getVertex(int i, V& value) = 0;

    virtual bool getVertex(int i, const V& value) = 0; //���ö�����ص�Ԫ��ֵ
    virtual SharePoint< Array<int> > getAdjacent(int i) = 0; //��ȡ�����Ӷ���

    virtual E getEdge(int i, int j) = 0; //��ȡ����ص�Ԫ��ֵ
    virtual bool getEdge(int i, int j, E& value) = 0;
    virtual bool getEdge(int i, int j, const E& value) = 0;

    virtual bool removeEdge(int i, int j) = 0; //ɾ��i��j�ı�


    int vCount()
    {
        return N;
    }
    virtual int eCount()
    {
        return m_eCount;
    }
    virtual int OD(int i) = 0;  //��ȡ����ĳ���
    virtual int ID(int i) = 0;  //��ȡ��������

    ~ MatrixGraph()
    {
        for(int i=0; i<N ; i++)
        {
            m_vertexes[i] = nullptr;
            for(int j=0; j<N; j++)
            {
                m_edges[i][j] = nullptr;
            }
        }
    }
};

#endif // MATRIXGRAPH_H
