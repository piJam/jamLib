#include <iostream>
#include <cstring>
#include <cstdlib>
#include "StaticQueue.h"


using namespace std;
using namespace jamLib;


int main()
{
    StaticQueue<int, 10> queue;

    for(int i = 0; i < 10; i++)
    {
        queue.add(i);
    }

    for(int i = 0; i < queue.capacity(); i++)
    {
        cout<< queue.front() << endl;
        queue.remove();
    }


    return 0;
}


