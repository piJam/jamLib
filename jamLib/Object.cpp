#include "Object.h"
#include <cstdlib>

namespace jamLib{

Object::~Object()
{

}

void* Object::operator new(unsigned int size) throw()
{
    cout << "--- void* Object::operator new(unsigned int size) throw() ---" << endl;
    return malloc(size);
}
void Object::operator delete(void* p)
{
     cout << "--- void Object::operator delete(void* p) ---" << endl;
     free(p);
}

void* Object::operator new[](unsigned int size) throw()
{
    return malloc(size);
}
void Object::operator delete[](void* p)
{
    free(p);
}

}
