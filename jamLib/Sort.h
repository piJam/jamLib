#ifndef SORT_H
#define SORT_H
#include "Object.h"
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
};
}

#endif // SORT_H
