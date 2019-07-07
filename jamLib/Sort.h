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

};
}

#endif // SORT_H
