#include <iostream>
#include <cstring>
#include <cstdlib>
#include "StaticStack.h"


using namespace std;
using namespace jamLib;
int main()
{

    StaticStack<int,10> list;

    for(int i = 0; i < list.capacity(); i++)
    {
        list.push(i);
    }

    for(int i = 0; i < list.capacity(); i++)
    {

        cout<< list.top() <<endl;
        list.pop();
    }





    return 0;
}


