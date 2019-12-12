#ifndef ARRAY_H
#define ARRAY_H
#include <cstdio>
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

   virtual bool set(int i, const T& t)
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
       return ( const_cast<Array<T>&>(*this) )[i];
    }

    T* array() const{ return m_array;}

    //纯虚函数的定义，决定了这个类是抽象类，如果类中全为纯虚函数，那么这个类为接口类
    virtual int length() const = 0;

};
}

#endif // ARRAY_H
