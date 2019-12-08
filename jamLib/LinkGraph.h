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

        LinkList< Edge<E> > edge; //Ϊʲô����edgeָ�룿�ڶ����ͷ�ʱ��������������������edgeҲ��֮�����������edgeָ�룬����������ʱ��edge���ܹ�����������ڴ�й©��

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
        bool ret = (0 <= i) && (i < m_vertex.length());

        if(i)
        {
            Vertex* vertex = m_vertex.get(i);
            V* data = vertex->data;

            if( data == nullptr)
            {
                data = new V();  // ? dephi data != NULL
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
            Vertex* vertex = m_vertex.get(i);

            if( vertex->data != NULL)
            {
                value =  *(vertex->data); //? value = vertex->data;
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
            Vertex* del = m_vertex_list.get(index); //�������ȡҪɾ������

            if( m_vertex_list.remove(index) ) //����ֻ�ܽ�����Ԫɾ��������ָ��ָ��ռ䲻��ɾ�������ԣ����滹Ҫ�����ͷš�
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

        if( ( 0 <= i ) && ( i < vCount) )
        {
            Vertex* v = m_vertex_list.get(i);

            ret = new DynamicArray(v->edge.length());

            if( ret != nullptr )
            {
                for( int k =(v->edge.move(0),0); !v->edge.end(); k++,v->edge.next() )
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


    virtual int vCount()
    {
        return m_vertex.length();
    }
    virtual int eCount() = 0;  //��ȡ�ߵ�����
    virtual int OD(int i) = 0;  //��ȡ����ĳ���
    virtual int ID(int i) = 0;  //��ȡ��������

};

}

#endif // LINKGRAPH_H
