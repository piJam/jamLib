#ifndef OBJECT_H
#define OBJECT_H
namespace jamLib{
class Object
{
public:

    virtual ~Object() = 0;

    void* operator new(unsigned int size) throw();
    void operator delete(void* p);

    void* operator new[](unsigned int size) throw();
    void operator delete[](void* p);
};
}
#endif // OBJECT_H
