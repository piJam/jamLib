#ifndef LINKGRAPH_H
#define LINKGRAPH_H
#include "LinkList.h"
#include "Object.h"
#include "Graph.h"
#include "Array.h"
#include "DynamicArray.h"

namespace jamLib
{

template<typename V, typename E>
class LinkGraph : public Graph<V, E>
{
protected:
    struct Vertex : public Object
    {
        V* data;

        LinkList< Edge<E> > edge; //为什么不用edge指针？在顶点释放时，链表析构，链表析构edge也随之析构。如果用edge指针，在链表析构时，edge不能够析构，造成内存泄漏。

        Vertex()
        {
            data = nullptr;
        }
    };

    LinkList< Vertex* > m_vertex_list;

public:

    LinkGraph(unsigned int n = 0)
    {
        for(unsigned int i=0; i<n; i++)
        {
            addVertex();
        }
    }

    int addVertex()
    {
        int ret = -1;

        Vertex* vertex = new Vertex();

        if( vertex != NULL )
        {
            m_vertex_list.insert(vertex);

            ret = m_vertex_list.length() - 1;

        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "no enough memory create new vertex object ...");
        }

        return ret;
    }

    int addVertex(const V& value)
    {
        int ret = addVertex();

        if( ret >= 0 )
        {
            setVertex(ret, value);
        }

        return ret;
    }

    bool setVertex(int i, const V& value)
    {
        bool ret = (0 <= i) && (i < vCount());

        if(ret)
        {
            Vertex* vertex = m_vertex_list.get(i);
            V* data = vertex->data;

            if( data == NULL)
            {
                data = new V();
            }

            if( data != nullptr )
            {
                *data = value;
                vertex->data = data;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "no enought memory create V ...");
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "this paramter is invaild ...");
        }

        return ret;
    }

    V getVertex(int i)
    {
        V ret;

        if( !getVertex(i, ret) )
        {
            THROW_EXCEPTION(InvalidParameterException, "this paramter is invaild ...");
        }

        return ret;
    }

    bool getVertex(int i, V& value)
    {
        bool ret = (0 <= i) && (i < vCount());

        if(ret)
        {
            Vertex* vertex = m_vertex_list.get(i);

            if( vertex->data != NULL)
            {
                value =  *(vertex->data);
            }
            else
            {
                THROW_EXCEPTION(InvalidOperationException, "No value assigned to this vertex ...s");
            }
        }

        return ret;
    }

    void removeVertex()
    {
        if( m_vertex_list.length() > 0 )
        {

            int index = m_vertex_list.length() - 1;
            Vertex* del = m_vertex_list.get(index); //从链表获取要删除顶点

            if( m_vertex_list.remove(index) ) //链表只能将链表单元删除，但是指针指向空间不能删除，所以，下面还要进行释放。
            {
                for( int i = (m_vertex_list.move(0), 0); !m_vertex_list.end(); i++, m_vertex_list.next() )
                {

                    int pos = m_vertex_list.current()->edge.find(Edge<E>(i, index));

                    if( pos >= 0 )
                    {
                        m_vertex_list.current()->edge.remove(pos);
                    }
                }
            }

            delete del->data;
            delete del;
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "No vertex in current graph ...");
        }
    }

    SharedPointer< Array<int> > getAdjacent(int i)
    {
        DynamicArray<int>* ret = NULL;

        if( ( 0 <= i ) && ( i < vCount()) )
        {
            Vertex* v = m_vertex_list.get(i);

            ret = new DynamicArray<int>(v->edge.length());

            if( ret != nullptr )
            {
                for( int k =(v->edge.move(0), 0); !v->edge.end(); k++, v->edge.next() )
                {
                    ret->set(k, v->edge.current().m_end);
                }
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "no enough memory create DynamicArray ...");
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "i is invalid ...");
        }

        return ret;
    }

    E getEdge(int i, int j)
    {
        E ret;

        if( !getEdge(i, j, ret) )
        {
            THROW_EXCEPTION(InvalidParameterException, "Edge<i, j> parameter is invalid ...");
        }

        return ret;
    }

    bool getEdge(int i, int j, E& value)
    {
        bool ret = ( (0 <= i) && (i < vCount()) ) && ( (0 <= j) && (j < vCount()) );

        if( ret )
        {
            Vertex* vertex = m_vertex_list.get(i);

            int pos = vertex->edge.find( Edge<E>(i, j) );

            if( pos >= 0 )
            {
                value = vertex->edge.get(pos).data;
            }
            else
            {
                THROW_EXCEPTION(InvalidOperationException, "No value assgined to this edge ...");
            }
        }

        return ret;
    }

    bool setEdge(int i, int j, const E& value)
    {
        bool ret = ( (0 <= i) && (i < vCount()) ) && ( (0 <= j) && (j < vCount()) );

        if( ret )
        {
            Vertex* vertex = m_vertex_list.get(i);
            int pos = vertex->edge.find(Edge<E>(i, j));

            if( pos >= 0)
            {
                ret = vertex->edge.set(pos, Edge<E>(i, j, value));
            }
            else
            {
                ret = vertex->edge.insert(0, Edge<E>(i, j, value));
            }
        }

        return ret;
    }


    bool removeEdge(int i, int j)
    {
        bool ret = ( (0 <= i) && (i < vCount()) ) && ( (0 <= j) && (j < vCount()) );

        if( ret )
        {
            Vertex* vertex = m_vertex_list.get(i);
            int pos = vertex->edge.find(Edge<E>(i, j));

            if( pos >= 0 )
            {
                ret = vertex->edge.remove(pos);
            }
            else
            {
                THROW_EXCEPTION(InvalidOperationException, "no value ...");
            }
        }

        return ret;
    }


    int vCount()
    {
        return m_vertex_list.length();
    }

    int eCount()
    {
        int ret;

        for( m_vertex_list.move(0); !m_vertex_list.end(); m_vertex_list.next() )
        {
            ret += m_vertex_list.current()->edge.length();
        }

        return ret;
    }

    int OD(int i)
    {
        int ret;

        if( (0 <= i) && (i < vCount()) )
        {
            Vertex* vertex = m_vertex_list.get(i);
            ret = vertex->edge.length();
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "parament i in invalid ...");
        }


        return ret;
    }

    int ID(int i)
    {
        int ret;

        if( (0 <= i) && (i < vCount()) )
        {
            for( m_vertex_list.move(0); !m_vertex_list.end(); m_vertex_list.next() )
            {
                LinkList< Edge<E> >& edge = m_vertex_list.current()->edge; //变成引用不用在调用构造函数，节省性能

                for( edge.move(0); !edge.end(); edge.next() )
                {
                    if(edge.current().m_end == i)
                    {
                        ret++;
                        break;
                    }
                }
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "parament i in invalid ...");
        }


        return ret;
    }

    ~LinkGraph()
    {
        while( vCount() > 0 )
        {
            Vertex* del = m_vertex_list.get(0);

            m_vertex_list.remove(0);

            delete del->data;
            delete del;
        }
    }

};

}

#endif // LINKGRAPH_H
