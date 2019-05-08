/*  20190401 16:24  */
#ifndef SMARTPOINT_H
#define SMARTPOINT_H
#include "Pointer.h"

namespace jamLib{

template<typename T>
class SmartPoint : public Pointer<T>
{
//protected:
//    T* m_point;  //使用父类Pointer的m_pointer
public:
    SmartPoint(T* point = NULL) : Pointer<T>(point)
    {

    }

    SmartPoint(const SmartPoint<T>& obj)
    {
        this->m_pointer = obj.m_pointer;
        const_cast<SmartPoint<T>&>(obj).m_pointer = NULL;
    }

    SmartPoint<T>& operator =(const SmartPoint<T>& obj)
    {
        if(this != &obj)
        {
            T* p = this->m_pointer;
            this->m_pointer = obj.m_pointer;
            const_cast< SmartPoint<T>& >(obj).m_pointer = NULL;
            delete p;
        }

        return *this;
    }



    ~SmartPoint()
    {
        delete this-> m_pointer;
    }
};


}

#endif // SMARTPOINT_H
