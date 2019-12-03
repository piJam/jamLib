#ifndef GRAPH_H
#define GRAPH_H
#include "SharedPointer.h"
#include "Array.h"
namespace jamLib {
template <typename V, typename E>
class Graph : public Object
{
public:
    virtual V getVertex(int i) = 0;  //获取顶点相关的元素值
    virtual bool getVertex(int i, V& value) = 0;

    virtual bool setVertex(int i, const V& value) = 0; //设置顶点相关的元素值
    virtual SharePoint< Array<int> > getAdjacent(int i) = 0; //获取相连接顶点

    virtual E getEdge(int i, int j) = 0; //获取边相关的元素值
    virtual bool getEdge(int i, int j, E& value) = 0;
    virtual bool getEdge(int i, int j, const E& value) = 0;

    virtual bool removeEdge(int i, int j) = 0; //删除i到j的边


    virtual int vCount() = 0;  //获取顶点个数
    virtual int eCount() = 0;  //获取边的总数
    virtual int OD(int i) = 0;  //获取顶点的出度
    virtual int ID(int i) = 0;  //获取顶点的入度

    virtual int TD(int i) //获取顶点的度
    {
        return OD(i) + ID(i);
    }

};


}


#endif // GRAPH_H
