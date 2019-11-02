#ifndef SHAREDPOINTER_H
#define SHAREDPOINTER_H
#include <cstdlib>
#include "Pointer.h"
#include "Exception.h"


namespace jamLib {
template <typename T>
class SharedPointer : public Pointer<T>
{
protected:
    int* m_ref;
    void assign(const SharedPointer<T>& obj)
    {
        this->m_ref = obj.m_ref;
        this->m_pointer = obj.m_pointer;
        if(this->m_ref)
        {
            (*this->m_ref)++;

        }
    }

public:
    SharedPointer(T* t = NULL) : m_ref(NULL)
    {
        if(t)
        {
            this->m_ref = static_cast<int*>(malloc(sizeof(int)));
            if(m_ref)
            {
                this->m_pointer = t;
                *(this->m_ref) = 1;
            }else
            {
                THROW_EXCEPTION(NoEnoughMemoryException,"no memory to create sharedpointer object... ");
            }
        }
    }

    SharedPointer(const SharedPointer<T>& obj) : Pointer<T>(NULL)
    {
       cout << "copy" << endl;
        assign(obj);
    }

    SharedPointer<T>& operator =(const SharedPointer<T>& obj)
    {
        if(this != &obj)
        {
            clear();
            assign(obj);

        }
        return *this;
    }

    void clear()
    {
        T* p = this->m_pointer;
        int* ref = this->m_ref;

        this->m_pointer = NULL;
        this->m_ref = NULL;

        if(ref)
        {
            (*ref)--;

            if(*ref == 0)
            {
                free(ref);
                delete p;
            }
        }
    }

    void getAssign() //20190722 add function
    {
        cout<<"m_ref is " <<*(this->m_ref)<< endl;
    }

    ~SharedPointer()
    {
        clear();
    }

    bool operator == (const SharedPointer<T>& obj)
    {
        return (this->get() == obj.get());
    }

    bool operator != (const SharedPointer<T>& obj)
    {
        return !(*this == obj);
    }
};
//全局共享指针比较
//template<typename T>
//bool operator == (const SharedPointer<T>& obj1,const SharedPointer<T>& obj2)
//{
//    return (*obj1 == *obj2);
//}
}


#endif // SHAREDPOINTER_H
