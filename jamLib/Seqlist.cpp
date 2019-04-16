#include "Seqlist.h"

namespace jamLib
{

template<typename T>
 bool SeqList<T>::insert(int i,const T& e)
 {
     bool ret = (0 <= i)&&(i <= m_length); //判断i到 m_length 长度时空间还够不够用
     ret = ret && (m_length < capacity());
     if(ret)
     {
         for(int p = m_length - 1; p >= i; p--)
         {
             *(m_array + p + 1) = *(m_array + p);
         }

        *(m_array + i) = e;

        m_length++;
     }
     return ret;
 }

 template<typename T>
 bool SeqList<T>::remove(int i)
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

     return 1;
 }

 template<typename T>
 bool SeqList<T>::get(int i,T& e) const
 {
     bool ret = (i >= 0)&&(i < m_length);
     if(ret)
     {
         e = m_array[i];
     }
     return ret;
 }

 template<typename T>
 bool SeqList<T>::set(int i,const T& e)
 {
     bool ret = (i >= 0)&&(i < m_length);
     if(ret)
     {
         m_array[i] = e;
     }
     return ret;
 }

 template<typename T>
 int SeqList<T>::length() const
 {
     return m_length;
 }

 template<typename T>
 void SeqList<T>::clear()
 {
     m_length = 0;
 }

 template<typename T>
 T& SeqList<T>::operator [](int i)
 {
      if((i >= 0)&&(i < m_length))
      {
          return m_array[i];
      }else
      {
          THROW_EXCEPTION(IndexOutOfBoundsException,"invalid...");
      }

 }

template<typename T>
T SeqList<T>::operator[](int i )const
{
    return (const_cast<SeqList<T>&>(*this))[i]  ;
}

}

