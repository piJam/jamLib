#include <iostream>
#include <cstring>
#include <cstdlib>
#include "JString.h"
using namespace std;
using namespace jamLib;

int main()
{
    JString s = "absdhasdwerwerwerwer";

    cout<< s.remove(4,8).str()<< endl;

    return 0;
}


