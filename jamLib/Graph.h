#ifndef GRAPH_H
#define GRAPH_H
#include "SharedPointer.h"
#include "Array.h"
namespace jamLib {
template <typename V, typename E>
class Graph : public Object
{
public:
    virtual V getVertex(int i) = 0;
    virtual bool getVertex(int i, V& value) = 0;
    virtual bool getVertex(int i, const V& value) = 0;
    virtual SharePoint< Array<int> > getAdjacent(int i) = 0;

    virtual E getEdge(int i, int j) = 0;
    virtual bool getEdge(int i, int j, E& value) = 0;
    virtual bool getEdge(int i, int j, const E& value) = 0;
    virtual bool removeEdge(int i, int j) = 0;

    virtual int vCount() = 0;
    virtual int eCount() = 0;
    virtual int OD(int i) = 0;
    virtual int ID(int i) = 0;

    virtual int TD(int i)
    {
        return OD(i) + ID(i);
    }

};


}


#endif // GRAPH_H
