#include <iostream>
#include <cstring>
#include <cstdlib>
#include "smartPoint.h"
using namespace std;

int main()
{
    int a = 9999;
    char c[1]={0};
    itoa(a,c,3);
    cout << c << endl;
    return 0;
}

