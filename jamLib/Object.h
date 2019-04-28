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

    virtual ~Object() = 0;
};
}
#endif // OBJECT_H
