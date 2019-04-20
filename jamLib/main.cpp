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

    try{

    THROW_EXCEPTION(IndexOutOfBoundsException,"this is no ...");

    }
    catch(Exception& e)
    {

        cout << e.message() << endl;
         cout << e.location() << endl;
    }

    return 0;
}


