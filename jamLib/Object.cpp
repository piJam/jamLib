#include "Object.h"
#include <cstdlib>

namespace jamLib{

Object::Object(){}
Object::~Object(){}

void* Object::operator new(size_t size) throw()
{
    return malloc(size);
}
void Object::operator delete(void* p)
{
     free(p);
}

bool Object::operator ==(const Object& obj)
{
    return (this == &obj);
}
bool Object::operator !=(const Object& obj)
{
    return (this != &obj);
}

void* Object::operator new[](size_t size) throw()
{
    return malloc(size);
}
void Object::operator delete[](void* p)
{
    free(p);
}

}
