#ifndef ARRAY_H
#define ARRAY_H
#include "Object.h"
#include "Exception.h"
namespace jamLib
{
template<typename T>
class Array :  public Object
{
protected:
    T* m_array;
public:
    virtual bool get(int i ,T& t)const
    {
        bool ret = (0 <= i)&&(i < length());
        if(ret)
        {
            t = m_array[i];
        }
        return ret;
    }

    virtual bool set(int i,T& t)
    {
          bool ret = (i >= 0)&&(i < length());
          if(ret)
          {
                m_array[i] = t;
          }
          return ret;
    }

    T& operator [](int i)
    {
        if( (0 <= i)&&( i< length()))
        {
             return m_array[i];
        }
        else
        {
             THROW_EXCEPTION(IndexOutOfBoundsException,"invalid...");
        }


    }

    T operator [](int i) const
    {
        return (static_cast<Array<T>&>(*this))[i];
    }
    virtual int length() const = 0;

};
}

#endif // ARRAY_H
