#ifndef OBJECT_H
#define OBJECT_H
#include<iostream>
#include <cstdlib>
using namespace std;
namespace jamLib{
class Object
{

public:

    void* operator new(size_t size) throw();
    void operator delete(void* p);

    bool operator ==(const Object& obj);
    bool operator !=(const Object& obj);

    void* operator new[](size_t size) throw();
    void operator delete[](void* p);

    virtual ~Object() = 0; // 纯虚函数中只有“析构函数”需要给出函数原型（实现）
};
}
#endif // OBJECT_H
