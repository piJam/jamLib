/*  20190401 16:24  */
#ifndef SMARTPOINT_H
#define SMARTPOINT_H
#include "Object.h"

namespace jamLib{

template<typename T>
class SmartPoint : public Object
{
private:
    T* m_point;
public:
    SmartPoint(T* point = NULL)
    {
        this->m_point = point;
    }

    SmartPoint(const SmartPoint<T>& obj)
    {
        this->m_point = obj.m_point;
        const_cast< SmartPoint<T>& >(obj).m_point = NULL;
    }

    SmartPoint<T>& operator =(const SmartPoint<T>& obj)
    {
        if(this != &obj)
        {
            delete m_point;
            this->m_point = obj.m_point;
            const_cast< SmartPoint<T>& >(obj).m_point = NULL;
        }

        return *this;
    }

    T* operator ->()
    {
        return m_point;
    }

    T& operator *()
    {
        return *m_point;
    }

    T* get()
    {
        return m_point;
    }

    bool isNull()
    {
        return (m_point == NULL) ;
    }

    ~SmartPoint()
    {
        delete m_point;
    }
};


}

#endif // SMARTPOINT_H
