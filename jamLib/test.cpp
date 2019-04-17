#include <iostream>
#include <cstring>
#include <cstdlib>
#include "SmartPoint.h"
#include "Exception.h"
#include "StaticList.h"
#include "SeqList.h"

using namespace std;
using namespace jamLib;

int main()
{

   // SeqList<int> sl;
      StaticList<int,10> list;
    for(int i = 0; i < list.capacity(); i++)
    {
       list.insert(0,i);
    }

    return 0;
}

