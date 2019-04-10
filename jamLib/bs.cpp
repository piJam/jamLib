#include "bs.h"




Bs::Bs()
{
    std::cout << "----------------Bs()----------------" << std::endl;
}

Bs::~Bs()
{
    std::cout << "----------------~Bs()----------------" << std::endl;
}
int Bs:: getInt()
{
    return 999999;
}

string Bs::getString()
{
    return "ABC";
}
void Bs::setAge(int age)
{
    this->age = age;
}
