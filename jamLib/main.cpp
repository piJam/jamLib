#include <iostream>
#include <cstring>
#include <cstdlib>
#include "JString.h"
using namespace std;
using namespace jamLib;



int main()
{
   const JString str("ABCGDYE\0JR");
   char* s = NULL;
   JString st = s;
   cout<< str.startWith(st) << endl;



    return 0;
}


