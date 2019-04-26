#ifndef OBJECT_H
#define OBJECT_H
#include<iostream>
using namespace std;
namespace jamLib{
class Object
{
protected:
    Object(const Object& e);
    Object& operator=(const Object& e);
public:

    virtual ~Object() = 0;
    Object();
    void* operator new(size_t size) throw();
    void operator delete(void* p);

    bool operator ==(const Object& obj);
    bool operator !=(const Object& obj);

    void* operator new[](size_t size) throw();
    void operator delete[](void* p);
};
}
#endif // OBJECT_H
