#include "Object.h"

namespace jamLib{

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
    std::cout <<"this :" << this <<"-&obj:"<< &obj << std::endl;
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

Object::~Object(){}
}
