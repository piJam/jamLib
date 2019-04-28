#include <iostream>
#include <cstring>
#include <cstdlib>
#include "SmartPoint.h"
#include "Exception.h"
#include "StaticList.h"
#include "DynamicList.h"
#include "SeqList.h"
#include "StaticArray.h"
#include "DynamicArray.h"
#include "LinkList.h"

using namespace std;
using namespace jamLib;

int main()
{
    LinkList<int> list;
    list.insert(1);
    list.insert(1);


   for(int i = 0;i < 10;i++)
   {
        list.insert(i*i);
   }

   for(int i = 0; i< 10; i++)
   {
       cout<< list.get(i) << endl;
   }

   list.remove(6);
   cout<<endl;

   for(int i = 0; i< 9; i++)
   {
       cout<< list.get(i) << endl;
   }

  list.clear();

    system("pause");



   return 0;
}


