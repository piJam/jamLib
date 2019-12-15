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

    SharedPointer< Array<int> > getAdjacent(int i)
    {
        Array<int>* ret = nullptr;

        if( (0<=i) && (i<vCount()) )
        {
            int index = 0;
            for(int j=0; j<vCount(); j++)
            {
                if( m_edges[i][j] != nullptr )
                {
                    index++;
                }
            }

            ret = new DynamicArray<int>(index);

            if( ret != NULL)
            {
                 for(int j=0, k=0; j<vCount(); j++)
                {
                    if( m_edges[i][j] != NULL )
                    {
                        ret->set(k++, j);
                    }
                }

            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "no enought memory to DynamicArray ...");
            }

        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "this index not range ...");
        }

        return ret;
    }

    E getEdge(int i, int j)
    {
        E ret;

        getEdge(i, j, ret);

        return ret;
    }

    bool getEdge(int i, int j, E& value)
    {
        bool ret = ( (0<=i) && (i<vCount()) ) && ( (0<=j) && (j<vCount()) );

        if(ret)
        {
            if( m_edges[i][j] != nullptr )
            {
                value = *m_edges[i][j];
            }
            else
            {
                THROW_EXCEPTION(InvalidOperationException, "this value is null ...");
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "this parament is invalid ...");
        }

        return ret;
    }

    bool setEdge(int i, int j, const E& value)
    {
        bool ret = ( (0<=i) && (i<vCount()) ) && ( (0<=j) && (j<vCount()) );

        if(ret)
        {
            E* temp = nullptr;

            if( m_edges[i][j] == nullptr )
            {
                temp = new E();
            }

            if( temp == nullptr)
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "no enought memory for edge ...");
            }

            *temp = value;

            m_edges[i][j] = temp;

            m_eCount++;


        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "this parament is invalid ...");
        }

        return ret;
    }

    bool removeEdge(int i, int j)
    {
        bool ret = ( (0<=i) && (i<vCount()) ) && ( (0<=j) && (j<vCount()) );

        if(ret)
        {
            if( m_edges[i][j] != nullptr )
            {
                E* temp = m_edges[i][j];

                m_edges[i][j] = nullptr;

                m_eCount--;

                delete temp;
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "this parament is invalid ...");
        }

        return ret;
    }


    int vCount()  //¶¥µãÊý
    {
        return N;
    }
    virtual int eCount() //±ßÊý
    {
        return m_eCount;
    }

    int OD(int i)
    {
        int ret = 0;

        if( (0<=i) && (i<vCount()) )
        {
            for(int j=0; j<vCount(); j++)
            {
                if( m_edges[i][j] != nullptr)
                {
                    ret++;
                }

            }
        }

        return ret;
    }

    int ID(int i)
    {
        int ret = 0;

        if( (0<=i) && (i<vCount()) )
        {
            for(int j=0; j<vCount(); j++)
            {
                if( m_edges[j][i] != nullptr)
                {
                    ret++;
                }

            }
        }

        return ret;
    }

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
