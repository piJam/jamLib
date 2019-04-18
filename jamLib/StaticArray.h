#ifndef STATICARRAY_H
#define STATICARRAY_H
#include "Array.h"
namespace jamLib
{
template<typename T,int N>
class StaticArray : public Array<T>
{
protected:
    T m_space[N];
public:
    StaticArray()
    {
        this->m_array = m_space;
    }

    StaticArray(const StaticArray<T,N>& obj)
    {
        this ->m_array = m_space;
        for(int i = 0; i < length(); i++)
        {
          // this -> m_array[i] =  obj[i];

            m_space[i] = obj[i];
        }
    }

    StaticArray<T,N>& operator=(const StaticArray<T,N>& obj)
    {
        if(this != &obj)
        {
            for(int i = 0; i<length(); i++)
            {
                 this ->  m_array[i] =  obj.m_array[i];
            }

        }
        return *this;
    }
    virtual int length() const
    {
        return N;
    }
};

}

#endif // STATICARRAY_H
