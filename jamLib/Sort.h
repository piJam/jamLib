#ifndef SORT_H
#define SORT_H
#include "Object.h"
namespace jamLib
{
class Sort : public Object
{
private:
    Sort(){}
    Sort(const Sort& sort){}
    Sort& operator= (const Sort& sort){}
public:
    template<typename T>
    static void swap(T& t1, T& t2)
    {
        T c();
        c = t1;
        t1 = t2;
        t2 = c;
    }

};
}

#endif // SORT_H
