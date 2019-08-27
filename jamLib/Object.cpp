#include "Object.h"
#include "GTreeNode.h"
namespace jamLib{

void* Object::operator new(size_t size) throw()
{
    return malloc(size);
}
void Object::operator delete(void* p)
{
    cout << "delete value is "<< ((GTreeNode<int>*)p)->value << endl;
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

Object::~Object(){}
}
