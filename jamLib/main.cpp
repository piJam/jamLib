#include <iostream>
#include <cstring>
#include <cstdlib>
#include "SmartPoint.h"
#include "Exception.h"
#include "StaticList.h"
#include "DynamicList.h"
#include "SeqList.h"
#include "StaticArray.h"
#include "DynamicArray.h"


using namespace std;
using namespace jamLib;

int main()
{
    StaticArray<int,6> ar1;


    for(int i = 0; i < ar1.length();i++)
    {
        ar1.set(i,i);
    }

    StaticArray<int,6> ar;
    ar = ar1;

    for(int i = 0; i<ar.length();i++)
    {

        cout << ar[i] << endl;
    }


    DynamicArray<int> ds(10);


    for(int i = 0; i<ds.length(); i++)
    {
        ds[i] = i*i;

    }

    DynamicArray<int> dss(10);// = ds ;

    dss = ds;
    for(int i = 0; i<dss.length(); i++)
    {
        cout<< dss[i] <<endl;
    }

    return 0;
}


