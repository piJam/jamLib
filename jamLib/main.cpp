#include <iostream>
#include <cstring>
#include <cstdlib>
#include "JString.h"
using namespace std;
using namespace jamLib;

int sum(int num)
{

    if( num == 1)
    {
       num = 1;
    }else
    {
       num += sum(num - 1);
    }
    return num;
}

int main()
{
    JString s = "absdhasdwerwerwerwer";

    cout<< sum(1000) << endl;

    return 0;
}


