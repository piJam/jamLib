#ifndef MATRIXGRAPH_H
#define MATRIXGRAPH_H
#include "Graph.h"
#include "DynamicArray.h"
#include "Exception.h"

namespace jamLib
{
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
        V ret;

        if( !getVertex(i, ret) )
        {
            THROW_EXCEPTION(InvalidOperationException, "index i is invalid ...");
        }

        return ret;
    }

    bool getVertex(int i, V& value)
    {
        bool ret =( (0<=i) && (i < vCount()) );

        if(ret)
        {
            if(m_vertexes[i] != nullptr)
            {
                value = *(m_vertexes[i]);
            }else
            {
                THROW_EXCEPTION(InvalidOperationException,"No value assigned to this vertex ...");
            }
        }

        return ret;
    }

    bool setVertex(int i, const V& value)
    {
        bool ret = ( (0<=i) && (i<vCount()) );

        if(ret)
        {
            V* temp = m_vertexes[i];

            if(temp == nullptr)
            {
                temp = new V();

                if(temp == nullptr)
                {
                    THROW_EXCEPTION(NoEnoughMemoryException, " no enought memory to new V");
                }

                *temp = value;

                m_vertexes[i] = temp;
            }

        }

        return ret;
    }

    virtual SharePoint< Array<int> > getAdjacent(int i) = 0; //获取相连接顶点

    virtual E getEdge(int i, int j) = 0; //获取边相关的元素值
    virtual bool getEdge(int i, int j, E& value) = 0;
    virtual bool getEdge(int i, int j, const E& value) = 0;

    virtual bool removeEdge(int i, int j) = 0; //删除i到j的边


    int vCount()  //顶点数
    {
        return N;
    }
    virtual int eCount() //边数
    {
        return m_eCount;
    }
    virtual int OD(int i) = 0;  //获取顶点的出度
    virtual int ID(int i) = 0;  //获取顶点的入度

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
}
#endif // MATRIXGRAPH_H
