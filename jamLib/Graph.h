#ifndef GRAPH_H
#define GRAPH_H

#include "SharedPointer.h"
#include "Array.h"
#include "DynamicArray.h"
#include "Object.h"
#include "LinkQueue.h"
#include "LinkStack.h"

namespace jamLib {
template<typename E>
struct Edge : public Object
{
    int m_start;
    int m_end;
    E data;

    Edge(int start = -1, int end = -1)
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
    DynamicArray<int>* QueueToArray(LinkQueue<int>& lq)
    {
        DynamicArray<int>* ret = new DynamicArray<int>(lq.lenght());

        if(ret)
        {
            int i = 0;
            while( lq.lenght() > 0 )
            {
                 ret->set(i, lq.front());

                 lq.remove();

                 i++;
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
    virtual bool isAdjacent(int i, int j) = 0;  //判断i到j是否邻接

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

    bool asUndirected()
    {
        bool ret = true;
        for(int i=0; i<vCount(); i++)
        {
            for(int j=0; j<vCount(); j++)
            {
                ret = ret && isAdjacent(i, j) && isAdjacent(j, i) && ( getEdge(i, j) == getEdge(j, i) );
            }
        }
        return ret;
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

            ret = QueueToArray(r);
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "index is valid ...");
        }


        return ret;
    }

    SharedPointer< Array<int> > DFS(int index)
    {
        DynamicArray<int>* ret = NULL;

        if( ( 0 <= index ) && ( index < vCount() ) )
        {
            LinkStack<int> ls;
            LinkQueue<int> re;

            DynamicArray<bool> visitArray(vCount());

            for(int i=0; i<visitArray.length(); i++)
            {
                visitArray[i] = false;
            }

            ls.push(index);

            while( ls.size() > 0 )
            {
                int v = ls.top();
                ls.pop();

                if( !visitArray[v] )
                {
                    visitArray[v] = true;
                    re.add(v);

                    SharedPointer< Array<int> > sa = getAdjacent(v);
                    for(int i=sa->length()-1; i>=0; i--) //将数组第一个元素留到栈顶
                    {
                        ls.push((*sa)[i]);
                    }

                }
            }
            cout << "re lenght ="<< re.lenght() << endl;
            ret = QueueToArray(re);
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "index is valid ...");
        }
        return ret;
    }

    void DFSByRecursion(int v, Array<bool>& visit, LinkQueue<int>& lp)
    {
        if( ( 0 <= v ) && ( v < vCount() ) )
        {
            lp.add(v);

            visit[v] = true;

            SharedPointer< Array<int> > sa = getAdjacent(v);

            for(int i=0; i<sa->length(); i++)
            {
                if( !visit[(*sa)[i]] )
                {
                    DFSByRecursion((*sa)[i], visit, lp);
                }
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "V is invaild ...");
        }
    }

    SharedPointer< Array<int> > DFSByRecursion(int v)
    {
        DynamicArray<int>* ret = NULL;

        LinkQueue<int> lq;
        DynamicArray<bool> visit(vCount());

        for(int i=0; i<visit.length(); i++)
        {
            visit[i] = false;
        }

        DFSByRecursion(v, visit, lq);

        ret = QueueToArray(lq);

        return ret;
     }

    SharedPointer< Array<Edge<E>> > Prim(int v, E LIMIT)
    {
        DynamicArray< Edge<E> >* ret = NULL;

        if(asUndirected())
        {
            Array<bool> mark;
            Array<E> cost;
            Array<int> adjVex;
            LinkQueue<Edge<E>> ret;
            bool end = false;

            for(int i=0; i<vCount(); i++)
            {
                mark[i] = false;
                cost[i] = LIMIT;
                adjVex[i] = -1;
            }

            mark[v] = true;
            SharedPointer< Array<int> > aj = getAdjacent(v);

            for(int i=0; i<(*aj).length(); i++)
            {
                cost[(*aj)[i]] = getEdge(v, (*aj)[i]);
                adjVex[(*aj)[i]] = v;
            }

            for()
            {


            }

        else
        {
            THROW_EXCEPTION(InvalidOperationException, "invaild graph ...");
        }

        return ret;
    }

};
}


#endif // GRAPH_H
