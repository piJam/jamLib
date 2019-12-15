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

    void init(T* array,int length)
    {
        if(array != NULL)
        {
            this->m_array = array;
            this->m_length = length;
        }else
        {
             THROW_EXCEPTION(IndexOutOfBoundsException,"on memory to create...");
        }
    }

    T* copy(T* array,int length,int newLength)
    {
        T* ret = new T[newLength];
        if(ret != NULL)
        {
            int len = (length > newLength)? newLength : length ;
            for(int i =0; i<len; i++)
            {
                ret[i] = array[i];
            }
        }
         return ret;
    }

    void update(T* array,int length)
    {
        if(array != NULL)
        {
            T* temp = this->m_array;

            this->m_array = array;
            this->m_length = length;

            delete[] temp;

        }else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException,"on memory to copy...");
        }
    }
public:
    DynamicArray(int length = 0)
    {
        init(new T[length], length);
    }

    DynamicArray(const DynamicArray<T>& obj)
    {
//        this->m_array = new T[obj.m_length];
//        if(this->m_array != NULL)
//        {
//            for(int i = 0; i<obj.length(); i++)
//            {
//               // this->m_array[i] = obj.m_array[i];  //调用方法重载不如直接调用变量效率高
//                this->m_array[i] = obj.m_array[i];
//            }
//            this->m_length = obj.length();
//        }else
//        {
//            THROW_EXCEPTION(IndexOutOfBoundsException,"on memory create DynamicArray...");
//        }

         init( copy(obj.m_array,obj.m_length,obj.m_length), obj.m_length );
    }

    DynamicArray<T>& operator= (const DynamicArray<T>& obj)
    {
        if(this != &obj)
        {
//            T* array = new T[obj.m_length];
//            if(array != NULL)
//            {
//                for(int i = 0; i<obj.length(); i++)
//                {
//                   array[i] = obj.m_array[i];
//                }
//                T* temp = this->m_array;
//                this->m_array = array;
//                this->m_length = obj.m_length;
//                delete[] temp;
//            }else
//            {
//                THROW_EXCEPTION(IndexOutOfBoundsException,"on memory copy...");
//            }

                T* array = copy(obj.m_array,obj.m_length,obj.m_length);
                update(array,obj.length());

          }
          return *this;
      }

      void resize(int length)
      {
           if(length != m_length)
           {
//            int len =(length > m_length) ? m_length : length;  //用于老旧数组之间数据COPY。
//             T *space = new T[length];
//             if(space != NULL)
//             {
//                 for(int i = 0; i<len; i++)
//                 {
//                      space[i] = this->m_array[i];
//                 }
//                T* temp = this->m_array;
//                this->m_length = length;
//                this->m_array  = space;
//                delete[] temp;
//              }else
//              {
//                  THROW_EXCEPTION(IndexOutOfBoundsException,"on memory...");
//              }
                update(copy(this->m_array,this->m_length,length),length);
            }
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
