#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H
#include "Exception.h"
#include "SeqList.h"
template<typename T>
class DynamicList : public SeqList<T>
{
protected:
    int m_capacity;
public:
    DynamicList(int capacity)
    {
        this ->m_array = new T[capacity];
        if(m_array)
        {
            this->m_length = 0;
            this->m_capacity = capacity;

        }else{

            THROW_EXCEPTION(NoEnoughMemoryException,"on memory...");

        }

    }
    int capacity()const
    {
        return m_capacity;
    }

    void resize(int capacity)
    {
        T* array = new T[capacity];
        if(sp != NULL)
        {
            int length = capacity > this->m_capacity ? this->m_capacity : capacity;
            for(int i = 0; i<length; i++)
            {
                array[i] = m_array[i]
            }

            T* temp = this->m_array;

            this->m_length = length;
            this->m_capacity = capacity;
            this->m_array = array;

            delete[] temp;
        }else{
            THROW_EXCEPTION(NoEnoughMemoryException,"on enough memory... ");
        }
    }

    ~DynamicList()
    {
        delete[] this->m_array;
    }
};

#endif // DYNAMICLIST_H
