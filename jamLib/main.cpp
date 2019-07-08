#include <iostream>
#include <cstring>
#include <cstdlib>
#include "JString.h"
#include "LinkList.h"
#include "Sort.h"
#include "QueenPosition.h"
using namespace std;
using namespace jamLib;



int main()
{
    int i[] = {23,1,32,4,56,76};
    Sort::Bubble(i, 6, false);
    for(int j=0; j<6; j++)
    {
        cout<< i[j] <<endl;
    }

    return 0;
}


