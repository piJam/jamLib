#ifndef PROXY_H
#define PROXY_H
#include<ctime>
#include<iostream>
#include "Sort.h"
using namespace std;
namespace jamLib
{

struct Test
{
    int id;
    int data1[1000];
    double data2[500];

    bool operator > (const Test& test) const
    {
        return id > test.id;
    }
    bool operator >= (const Test& test) const
    {
        return id >= test.id;
    }
    bool operator < (const Test& test) const
    {
        return id < test.id;
    }
    bool operator <= (const Test& test) const
    {
        return id <= test.id;
    }
    bool operator == (const Test& test) const
    {
        return id == test.id;
    }
    int getID()
    {
        return id;
    }
};

class TestProxy
{
private:
    Test* m_test;
public:
    Test& test() const
    {
        return *m_test;
    }

    bool operator > (const TestProxy& obj)
    {
        return test() > obj.test() ;
    }
    bool operator >= (const TestProxy& obj)
    {
        return this->test() >=  obj.test();
    }
    bool operator < (const TestProxy& obj)
    {
        return test() < obj.test();
    }
    bool operator <= (const TestProxy& obj)
    {
        return  test() <= obj.test();
    }
    bool operator == (const TestProxy& obj)
    {
        return  test() ==  obj.test();
    }

    int getID()
    {
        return m_test->getID();
    }

    Test& operator = ( Test& test)
    {
        m_test = &test;
        return test;
    }
};

void proxyTest()
{
    static Test test[1000];   // test 和 tp 要么为静态，要么为全局，不能为局部，应为栈空间有限，1000个会使栈崩溃
    static TestProxy tp[1000];

     clock_t start = 0;
     clock_t end = 0;

     for (int i=0; i<1000; i++)
     {
         test[i].id = i;
         tp[i] = test[i];
     }

     start = clock();
     Sort::Bubble(test, 1000, false);
     end = clock();

     cout<<"Test time is " << (end - start) << endl;

     start = clock();
     Sort::Bubble(tp, 1000, true);
     end = clock();

     cout<<"TP time is " << (end - start) << endl;

     for (int i=0; i<1000; i++)
     {
         //cout<< test[i].getID() <<":"<< tp[i].getID() << endl;
     }

}
}


#endif // PROXY_H
