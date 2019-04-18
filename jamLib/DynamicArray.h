#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include "Array.h"
#include "Exception.h"
namespace jamLib
{
template<typename T>
class DynamicArray : public Array<T>
{
protected:
    int m_length;
public:
    DynamicArray(int length)
    {
        this ->m_array = new T[length];
        if(this->m_array != NULL)
        {
            this->m_length = length;
        }else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException,"on memory...");
        }
    }

    DynamicArray(const DynamicArray<T>& obj)
    {
        this->m_array = new T(obj.length());

        if(this->m_array != NULL)
        {
            for(int i = 0; i<obj.length(); i++)
            {
                this->m_array[i] = obj.m_array[i];
            }
            this->m_length = obj.length();
        }else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException,"on memory...");
        }

    }

    DynamicArray<T>& operator= (const DynamicArray<T>& obj)
    {
        if(this != &obj)
        {
            for(int i = 0; i<obj.length(); i++)
            {
                this->m_array[i] = obj.m_array[i];
            }
         }
        return *this;
    }

    int length() const
    {
        return m_length;
    }

    ~DynamicArray()
    {
        delete[] this-> m_array;
    }
};

}

#endif // DYNAMICARRAY_H
