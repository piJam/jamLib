#ifndef GRAPH_H
#define GRAPH_H

#include "SharedPointer.h"
#include "Array.h"
#include "DynamicArray.h"
#include "Object.h"
#include "LinkQueue.h"
#include "LinkStack.h"
#include "Sort.h"

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

    bool operator > (const Edge<E>& obj)
    {
        return (data > obj.data);
    }

    bool operator < (const Edge<E>& obj)
    {
        return (data < obj.data);
    }
};

template <typename V, typename E>
class Graph : public Object
{
protected:
    template<typename T>
    DynamicArray<T>* QueueToArray(LinkQueue<T>& lq)
    {
        DynamicArray<T>* ret = new DynamicArray<T>(lq.lenght());

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

    int find( Array<int>& p, int v)
    {
        while(p[v] != -1)
        {
            v = p[v];
        }

       return v;
    }

   SharedPointer< Array<Edge<E>> > getUndirectedEdges()
    {
        DynamicArray< Edge<E> >* ret = NULL;

        if( asUndirected() )
        {
            LinkQueue< Edge<E> > queue;

            for( int i=0; i<vCount(); i++ )
            {
                for( int j=i; j<vCount(); j++)
                {
                    if( isAdjacent(i, j) )
                        queue.add( Edge<E>(i, j, getEdge(i, j)) );
                }

            }

            ret = QueueToArray(queue);
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "this graph not Undirected ...");
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
                if(isAdjacent(i, j))
                {
                     ret = ret && isAdjacent(j, i) && ( getEdge(i, j) == getEdge(j, i) );
                }

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

    SharedPointer< Array<Edge<E>> > Prim(E LIMIT)
    {
        LinkQueue<Edge<E>> ret;

        if(asUndirected())
        {
            DynamicArray<bool> mark(vCount());
            DynamicArray<E> cost(vCount());
            DynamicArray<int> adjVex(vCount());

            int v = 0;

            SharedPointer< Array<int> > aj = NULL;

            for(int i=0; i<vCount(); i++)
            {
                mark[i] = false;
                cost[i] = LIMIT;
                adjVex[i] = -1;
            }

            bool end = false;

            mark[v] = true;

            aj = getAdjacent(v);

            for(int i=0; i<(*aj).length(); i++)
            {
                cost[(*aj)[i]] = getEdge(v, (*aj)[i]);
                adjVex[(*aj)[i]] = v;
            }

            for(int i=0; i<vCount() && !end; i++)
            {
                int k = -1;
                E m = LIMIT;

                for(int j=0; j<vCount(); j++)
                {
                    if( !mark[j] && (cost[j] < m) )
                    {
                        m = cost[j];
                        k = j;
                    }
                }

                end = (k == -1);

                if(!end)
                {
                    ret.add( Edge<E>(adjVex[k], k, getEdge(adjVex[k], k)) );
                    mark[k] = true;
                    aj = getAdjacent(k);

                    for(int j=0; j<(*aj).length(); j++)
                    {
                        if( !mark[(*aj)[j]] && (getEdge(k, (*aj)[j]) < cost[(*aj)[j]]) )
                        {
                            cost[(*aj)[j]] = getEdge(k, (*aj)[j]);
                            adjVex[(*aj)[j]] = k;
                        }
                    }
                }
            }

            if( ret.lenght() != (vCount()-1)) //不符合边，报异常
            {
                THROW_EXCEPTION(InvalidOperationException, "no enough edge ...");
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "invaild graph ...");
        }


        return QueueToArray(ret);
    }

    SharedPointer< Array<Edge<E>> > Kruskal()
    {
        LinkQueue< Edge<E> > ret;
        DynamicArray<int> p(vCount());
        SharedPointer< Array< Edge<E> > > edges = getUndirectedEdges();

        for(int i=0; i<vCount(); i++)
        {
            p[i] = -1;
        }

        Sort::Shell_insert(*edges);

        for( int i=0; ( i<edges->length() ) && ( ret.lenght() != (vCount()-1)); i++ )
        {
           int b = find(p, (*edges)[i].m_start);
           int e = find(p, (*edges)[i].m_end);

           if(b != e)
           {
               p[e] = b;
               ret.add((*edges)[i]);
           }
        }

        if( ret.lenght() != (vCount()-1)) //不符合边，报异常
        {
            THROW_EXCEPTION(InvalidOperationException, "no enough edge ...");
        }

        return QueueToArray(ret);
    }

    SharedPointer< Array<int> > dijkstra(int start, int end, const E& MAX)
    {

        LinkQueue<int> ret;

        if( ( 0<=start ) && ( start<vCount() ) && ( 0<=end ) && ( end<vCount() ) )
        {
            DynamicArray<E> dist(vCount());
            DynamicArray<int> path(vCount());
            DynamicArray<bool> mark(vCount());

            for(int i=0; i<vCount(); i++)
            {
                path[i] = -1;
                mark[i] = false;

                dist[i] = isAdjacent(start, i) ? (path[i]=start, getEdge(start, i)) : MAX;
            }

            mark[start] = true;

            for(int k=0; k<vCount(); k++)
            {
                E temp = MAX;
                int u = -1;

                for(int i=0; i<vCount(); i++)
                {
                    if( temp > dist[i] && !mark[i])
                    {
                        temp = dist[i];
                        u = i;
                    }
                }

                if(u == -1)  //如果图无边，会存在找不到最小值。u == -1
                {
                    break;
                }

                mark[u] = true;

                for(int w=0; w<vCount(); w++)
                {
                    if( !mark[w] && isAdjacent(u, w) && (dist[u] + getEdge(u ,w) < dist[w]) )
                    {
                        dist[w] = dist[u] + getEdge(u, w);
                        path[w] = u;
                    }
                }

            }

            LinkStack<int> stack;

            stack.push(end);

            for(int w=path[end]; w<vCount() && w != -1; w=path[w])
            {
                stack.push(w);
            }

            while(stack.size()>0)
            {
                ret.add(stack.top());
                stack.pop();
            }
        }
        else
        {

            THROW_EXCEPTION(InvalidParameterException, "start or end is invaild...");
        }

        if( ret.lenght() < 2 )
        {
            THROW_EXCEPTION(ArithmeticException, "There is no path from start to end ...");
        }

        return QueueToArray(ret);
    }

    SharedPointer< Array<int> > floyd(int start, int end, const E& LIMIT)
    {
        LinkQueue<int> ret;

        if( (0 <= start) && (start < vCount()) &&  (0 <= end)  && (end < vCount()) )
        {
            DynamicArray< DynamicArray<E> > dist(vCount());
            DynamicArray< DynamicArray<int> > path(vCount());

            for(int k=0; k<vCount(); k++)
            {
                dist[k].resize(vCount());
                path[k].resize(vCount());
            }

            for(int i=0; i<vCount(); i++)
            {
                for(int j=0; j<vCount(); j++)
                {
                    path[i][j] = -1;
                    dist[i][j] = isAdjacent(i, j) ? ( path[i][j] = j, getEdge(i, j) ) : LIMIT;
                }
            }

            for(int k=0; k<vCount(); k++)
            {
                for(int i=0; i<vCount(); i++)
                {
                    for(int j=0; j<vCount(); j++)
                    {
                        if( dist[i][j] > (dist[i][k] + dist[k][j]) )
                        {
                            dist[i][j] = dist[i][k] + dist[k][j];
                            path[i][j] = path[i][k];
                        }
                    }
                }
            }

            while( (start != -1) && (start != end) )
            {
                ret.add(start);
                start = path[start][end];
            }

            if( start != -1 ) //start经过不断赋值，start会等于end，再将end（最后一个顶定点）放入集合。
            {
                ret.add(start);
            }

        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "start ot end is invaild...");
        }

        if( ret.lenght() < 2 )
        {
            THROW_EXCEPTION(ArithmeticException, "There is no path from start to end ...");
        }

        return QueueToArray(ret);
    }

};
}


#endif // GRAPH_H
