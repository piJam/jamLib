#ifndef GRAPH_H
#define GRAPH_H
#include "SharedPointer.h"
#include "Array.h"
#include "Object.h"
namespace jamLib {
template<typename E>
struct Edge : public Object
{
    int m_start;
    int m_end;
    E data;

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
public:
    virtual V getVertex(int i) = 0;  //��ȡ������ص�Ԫ��ֵ
    virtual bool getVertex(int i, V& value) = 0;

    virtual bool setVertex(int i, const V& value) = 0; //���ö�����ص�Ԫ��ֵ
    virtual SharedPointer< Array<int> > getAdjacent(int i) = 0; //��ȡ��iΪ��㣬���е��յ�

    virtual E getEdge(int i, int j) = 0; //��ȡ����ص�Ԫ��ֵ
    virtual bool getEdge(int i, int j, E& value) = 0;

    virtual bool setEdge(int i, int j, const E& value) = 0; //����һ���ߵ�Ȩ

    virtual bool removeEdge(int i, int j) = 0; //ɾ��i��j�ı�


    virtual int vCount() = 0;  //��ȡ�������
    virtual int eCount() = 0;  //��ȡ�ߵ�����
    virtual int OD(int i) = 0;  //��ȡ����ĳ���
    virtual int ID(int i) = 0;  //��ȡ��������

    virtual int TD(int i) //��ȡ����Ķ�
    {
        return OD(i) + ID(i);
    }

};


}


#endif // GRAPH_H
