#include <iostream>
#include <cstring>
#include <cstdlib>
#include "SmartPoint.h"
#include "Exception.h"
#include "StaticList.h"
#include "DynamicList.h"
#include "SeqList.h"
#include "StaticArray.h"


using namespace std;
using namespace jamLib;

int main()
{
    StaticArray<int,6> ar1;


    for(int i = 0; i < ar1.length();i++)
    {
        ar1.set(i,i);
    }
    for(int i = 0; i<ar1.length();i++)
    {
        int b = i;
         ar1.get(i,b);
        cout << b << endl;
    }
    return 0;
}

