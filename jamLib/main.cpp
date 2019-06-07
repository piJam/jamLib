#include <iostream>
#include <cstring>
#include <cstdlib>
#include "JString.h"
using namespace std;
using namespace jamLib;



int main()
{
    JString str = " BCGD  EFR**90_--";
    cout<< str.lenght() << endl;
    cout << str.trim().str() << endl;
    cout << str.lenght() << endl;




    return 0;
}


