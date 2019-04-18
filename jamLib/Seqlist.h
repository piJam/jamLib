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

    virtual bool insert(int i,const T& e)
    {
        bool ret = (0 <= i)&&(i <= m_length); //判断i到 m_length 长度时空间还够不够用
        ret = ret && (m_length < capacity());
        if(ret)
        {
            for(int p = m_length - 1; p >= i; p--)
            {
                m_array[p + 1] = m_array[p];
            }

           m_array[i] = e;

           m_length++;
        }
        return ret;
    }
    virtual bool insert(const T& e)
    {
        return insert(m_length,e);
    }
    virtual bool remove(int i)
    {
        bool ret = (0 <= i) && (i< m_length);

        if(ret)
        {
            for(int p = i; p < m_length - 1; p++)
            {
                m_array[p] = m_array[p + 1];
            }
            m_length--;
        }

        return ret;
    }

    virtual bool get(int i,T& e) const
    {
        bool ret = (i >= 0)&&(i < m_length);
        if(ret)
        {
            e = m_array[i];
        }
        return ret;
    }

    virtual bool set(int i,const T& e)
    {
        bool ret = (i >= 0)&&(i < m_length);
        if(ret)
        {
            m_array[i] = e;
        }
        return ret;
    }

    virtual int length() const
    {
         return m_length;
    }

    virtual void clear()
    {
         m_length = 0;
    }

    virtual T& operator [](int i)
    {
        if((i >= 0)&&(i < m_length))
        {
            return m_array[i];
        }else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException,"invalid...");
        }
    }

    virtual T operator[](int i )const
    {
         return (const_cast<SeqList<T>&>(*this))[i]  ;
    }

    //空间大小
    virtual int capacity() const = 0;
};


}


#endif // SEQLIST_H
