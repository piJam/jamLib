#include <iostream>
#include <cstring>
#include <cstdlib>
#include "LinkQueue.h"


using namespace std;
using namespace jamLib;



int main()
{

    LinkQueue<int> list;

    for(int i = 0; i < 10; i++)
    {
        list.add(i);
    }

    //list.clear();

    while( list.lenght() > 0 )
    {
        cout << list.front() << endl;
        list.remove();
    }

    return 0;
}


