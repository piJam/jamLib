#include <iostream>
#include <cstring>
#include <cstdlib>
#include "SmartPoint.h"
#include "Exception.h"

using namespace std;
using namespace jamLib;
int main()
{
    try{
        //HROW_EXCEPTION(ArithmeticException,"wawawawa");
        THROW(ArithmeticException);
    }catch(Exception& e){

        cout << e.message() << endl;

    }

    return 9;
}

