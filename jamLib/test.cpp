#include <iostream>
#include <cstring>
#include <cstdlib>
#include "smartPoint.h"
#include "Exception.h"

using namespace std;
using namespace jamLib;
int main()
{
     try
    {

    }
    catch(const Exception& e)
    {
        cout << e.message() << endl;
    }
    return 0;
}

