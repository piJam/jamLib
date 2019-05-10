#include <iostream>
#include <cstring>
#include <cstdlib>
#include "SmartPoint.h"
#include "DynamicArray.h"
#include "LinkList.h"
#include "SharedPointer.h"

using namespace std;
using namespace jamLib;

class Test
{
public:
    int m_value;
public:
    Test(int value = 0)
    {
        this->m_value = value;
    }
};

int main()
{

    SharedPointer<Test> te1 = new Test(1);
    SharedPointer<Test> te2 = te1;
    cout<< te1->m_value << endl;
    cout<< te2->m_value << endl;
    SharedPointer<Test> te3 = new Test(3);
    cout << te3->m_value << endl;
    te3 = te2;
    cout << te3->m_value << endl;

    cout << (te3 != te2) << endl;


    return 0;
}


