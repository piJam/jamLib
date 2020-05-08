#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

#include "test.h"
#include "Array.h"
#include "LinkQueue.h"
#include "JString.h"
using namespace std;
using namespace jamLib;

int main()
{
//    int a[] = {1, 3, 5, 4};

//    int a[] = {3, 18, 7, 14, 10, 12, 23, 41, 16, 24};

 //   int a[] = {2, 1, 3, 5, 4};
  //  solution<int>(a, sizeof (a) / sizeof (*a) );

    int *a = new int();

    cout << a << endl;

    delete a;

    if(a != nullptr)
    {
         cout << a << endl;
    }


    return 0;
}
