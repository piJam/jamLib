#ifndef SEQLIST_H
#define SEQLIST_H
#include "List.h"
#include "Exception.h"
namespace jamLib
{
template<typename T>
class SeqList: public List<T>
{
protected:
    T*  m_array;
    int m_length;
public:

    virtual bool insert(int i,const T& e);
    virtual bool remove(int i);

    virtual bool get(int i,T& e) const;
    virtual bool set(int i,const T& e);

    virtual int length() const;
    virtual void clear();

    virtual T& operator [](int i);
    virtual T operator[](int i )const;

    virtual int capacity() const = 0;
};


}


#endif // SEQLIST_H
