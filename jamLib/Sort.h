#ifndef SORT_H
#define SORT_H
#include "Object.h"
#include "Array.h"
namespace jamLib
{
class Sort : public Object
{
private:
    Sort();
    Sort(const Sort& sort);
    Sort& operator= (const Sort& sort);
    template<typename T>
    static void Swap(T& t1, T& t2)
    {
        T c(t1);
        t1 = t2;
        t2 = c;
    }

    template<typename T>
    static void Merge( T src[], T temp[], int begin, int middle, int end, bool minTomax = true)
    {
        int i = begin;
        int j = middle + 1;
        int k = begin;

        while( (i <= middle) && (j <= end) )
        {
            if(src[i] > src[j])
            {
                temp[k++] = src[j++];
            }
            else
            {
                temp[k++] = src[i++];
            }
        }

        while(i <= middle)
            temp[k++] = src[i++];

        while(j <= end)
            temp[k++] = src[j++];

        for(i=begin; i<=end; i++)
            src[i] = temp[i];
    }

    template<typename T>
    static void Merge( T src[], T temp[], int begin, int end, bool minTomax = true)
    {
        if(begin < end)
        {
            int middle = ( begin + end ) / 2;

            Merge(src, temp, begin, middle, minTomax);
            Merge(src, temp, middle+1, end, minTomax);

            Merge(src, temp, begin, middle, end, minTomax);
        }

    }

    template<typename T>
    static int Partition(T array[], int begin, int end, bool minTomax)
    {
//        T point = array[begin];
//        int falg = true;
//        while(begin != end)
//        {
//            if(falg)
//            {
//                if(array[end] > point)
//                {
//                    end--;
//                    falg = true;
//                }
//                else
//                {
//                    Swap(array[begin], array[end]);
//                    falg = false;
//                }
//            }
//            else
//            {
//                if(array[begin] <= point)
//                {
//                    begin++;
//                    falg = false;
//                }
//                else
//                {
//                    Swap(array[begin], array[end]);
//                    falg = true;
//                }
//            }
//        }

        T pv = array[begin];
        while(begin < end)
        {
            while( (begin < end) && (minTomax ? (array[end] > pv) : (array[end] < pv) ) )
            {
                end--;
            }

            Swap(array[begin], array[end]);

            while( (begin < end) && (minTomax ? (array[begin] < pv) : (array[begin] > pv) ) )
            {
                begin++;
            }

            Swap(array[begin], array[end]);
        }

         array[begin] = pv; //目前没有找到该句的意义
        return begin;
    }


    template<typename T>
    static void Quick(T array[], int begin, int end, bool minTomax = true)
    {
        if(begin < end)
        {
            int pv = Partition(array, begin, end, minTomax);

            Quick(array, begin, pv-1, minTomax);
            Quick(array, pv+1, end, minTomax);
        }
    }

public:
    template<typename T>
    static void Select(T array[], int len, bool minToMax = true)
    {
        for(int i=0; i<len; i++)
        {
            int min = i;
            for(int j=i+1; j<len; j++)
            {
                if(minToMax ? array[min]>array[j] : array[min]<array[j])
                {
                    min = j;
                }
            }
            if(i != min)
                Swap(array[i],array[min]);
        }
    }

    template<typename T>
    static void Insert(T array[], int len, bool minToMax = true)
    {
        for (int i=1; i<len; i++)
        {
            T e = array[i];
            int index = i;

            for(int j=i-1; j>=0 && (minToMax ? (array[j] > e) : (array[j] < e)); j--)
            {
                index = j;
                array[j+1] = array[j];
            }

            if(index != i)
                array[index] = e;
        }

    }

    template<typename T>
    static void Bubble(T array[], int len, bool minToMax = true)
    {
        bool exChang = true;

        for (int i=0; (i<len) && exChang; i++)
        {
            exChang = false;
            for (int j=len-1; j>i; j--)
            {
                if( minToMax ? (array[j] < array[j-1]) : (array[j] > array[j-1]) )
                {
                        Swap(array[j], array[j-1]);
                        exChang = true;
                }

            }
        }
    }

    template<typename T>
    static void Shell_insert(T array[], int len, bool minToMax = true)
    {
        int d = len;
        do
        {
            d = d / 3 + 1;
            for (int i=d; i<len; i+=d)
            {
                T e = array[i];
                int k = i;
                for ( int j=i-d; j>=0 && (minToMax ? (array[j] > e) : (array[j] < e)); j-=d )
                {
                    k = j;
                    array[j+d] = array[j];
                }

                if(k != i)
                    array[k] = e;
            }
        } while (d > 1);

    }

    template<typename T>
    static void Shell_bubble(T array[], int len, bool minToMax = true)
    {
        int d =len;
        do
        {
            d = d / 3 + 1;
            bool exchang = true;

            for(int i=d; i<len; i+=d)
            {
                exchang = false;
                for (int j = len-1; j>=i; j-=d )
                {
                    if((minToMax ? (array[j] < array[j-d]) : (array[j] > array[j-d])))
                    {
                         Swap(array[j],array[j-d]);
                         exchang = true;
                    }

                }

            }
        }while(d > 1);
    }

    template<typename T>
    static void Merge(T array[], int len, bool minToMax = true)
    {
        T* temp = new T[len];
        if(temp != NULL)
        {
            Merge(array, temp, 0, len, minToMax);
        }

        delete[] temp;
    }

    template<typename T>
    static void Quick(T array[], int len, bool minTomax = true)
    {
         Quick(array, 0, len-1, minTomax);
    }

    template<typename T>
    static void Select(Array<T>& array, bool minTomax = true)
    {
        Select(array.array(), array.length(), minTomax);
    }

    template<typename T>
    static void Insert(Array<T>& array, bool minToMax = true)
    {
        Insert(array.array(), array.length(), minToMax);
    }

    template<typename T>
    static void Bubble(Array<T>& array, bool minToMax = true)
    {
        Bubble(array.array(), array.length(), minToMax);
    }

    template<typename T>
    static void Shell_insert(Array<T>& array, bool minToMax = true)
    {
        Shell_bubble(array.array(), array.length(), minToMax);
    }

    template<typename T>
    static void Merge(Array<T>& array, bool minToMax = true)
    {
        Merge(array.array(), array.length(), minToMax);
    }

    template<typename T>
    static void Quick(Array<T>& array, bool minTomax = true)
    {
        Quick(array, array.length(), minTomax);
    }
};
}

#endif // SORT_H
