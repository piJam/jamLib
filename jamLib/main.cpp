#include <iostream>
#include <cstring>
#include <cstdlib>
#include "JString.h"
using namespace std;
using namespace jamLib;



int main()
{
    JString str = "1234567890++";

    cout << str.insert(8,"ABCDFG").str() << endl;




    return 0;
}


