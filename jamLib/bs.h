#ifndef BS_H
#define BS_H
#include <iostream>
#include "Object.h"

class Bs : public jamLib::Object
{
    int age;
public:
    Bs();
    ~Bs();
    int getInt();

    string getString();
    void setAge(int age);
};

#endif // BS_H
