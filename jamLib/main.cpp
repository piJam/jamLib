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
    int i[] = {23,1,32,4,56,76,2,6,18,9};
    Sort::Merge(i, 10, false);
    for(int j=0; j<10; j++)
    {
        cout<< i[j] <<endl;
    }


    return 0;
}


