#ifndef GRAPH_H
#define GRAPH_H

#include "SharedPointer.h"
#include "Array.h"
#include "DynamicArray.h"
#include "Object.h"
#include "LinkQueue.h"

namespace jamLib {
template<typename E>
struct Edge : public Object
{
    int m_start;
    int m_end;
    E data;

    Edge(){}
    Edge(int start, int end)
    {
        m_start = start;
        m_end = end;
    }

    Edge(int start, int end, const E& value)
    {
        m_start = start;
        m_end = end;
        data = value;
    }

    bool operator == (const Edge<E>& obj)
    {
        return ( m_start == obj.m_start ) && ( m_end == obj.m_end ) ;
    }

    bool operator != (const Edge<E>& obj)
    {
        return !(*this == obj);
    }
};

template <typename V, typename E>
class Graph : public Object
{
protected:
    DynamicArray<int>* toArray(LinkQueue& lq)
    {
        DynamicArray<int>* ret = new DynamicArray<int>(lq.lenght());

        if(ret)
        {
            for(int i=0; i<lq.lenght(); i++,lq.remove())
            {
                ret->set(i, lq.front());
            }
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "no enough memory to create DynamicArray ... ");
        }

        return ret;
    }

public:
    virtual V getVertex(int i) = 0;  //获取顶点相关的元素值
    virtual bool getVertex(int i, V& value) = 0;

    virtual bool setVertex(int i, const V& value) = 0; //设置顶点相关的元素值
    virtual SharedPointer< Array<int> > getAdjacent(int i) = 0; //获取以i为起点，所有的终点

    virtual E getEdge(int i, int j) = 0; //获取边相关的元素值
    virtual bool getEdge(int i, int j, E& value) = 0;

    virtual bool setEdge(int i, int j, const E& value) = 0; //设置一条边的权

    virtual bool removeEdge(int i, int j) = 0; //删除i到j的边


    virtual int vCount() = 0;  //获取顶点个数
    virtual int eCount() = 0;  //获取边的总数
    virtual int OD(int i) = 0;  //获取顶点的出度
    virtual int ID(int i) = 0;  //获取顶点的入度

    virtual int TD(int i) //获取顶点的度
    {
        return OD(i) + ID(i);
    }

    SharedPointer< Array<int> > BFS(int index)
    {
        DynamicArray<int>* ret = NULL;

        if( ( 0 <= index ) && ( index < vCount() ))
        {
            LinkQueue<int> q;
            LinkQueue<int> r;

            q.add(index);

            DynamicArray<bool> markArray(vCount());

            for(int i=0; i<markArray.length(); i++)
            {
                markArray[i] = false;
            }

            while( q.lenght() > 0 )
            {
                int i = q.front();
                q.remove();

                if( !markArray[i] )
                {
                    markArray[i] = true;
                    r.add(i);

                    SharedPointer< Array<int> > adjacent = getAdjacent(i);

                    for(int j=0; j<adjacent->length(); j++)
                    {
                        q.add((*adjacent)[j]);
                    }
                }
            }

            ret = toArray(r);
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "index is valid ...");
        }


        return ret;
    }

};


}


#endif // GRAPH_H
