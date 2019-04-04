#include <iostream>
#include <cstring>
#include <cstdlib>
#include "SmartPoint.h"
#include "Exception.h"

using namespace std;
using namespace jamLib;
int main()
{
    SmartPoint<int> sp = NULL;
    cout << "Hello JamLib!" << &sp << " value is :" << sp.isNull() << endl;

    return 9;
}

