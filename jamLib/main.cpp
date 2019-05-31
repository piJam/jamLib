#include <iostream>
#include <cstring>
#include <cstdlib>
#include "LinkQueue.h"
#include "Stack_Queue_Convert.h"


using namespace std;
using namespace jamLib;



int main()
{

    StackToQueue<int> queue;

    for(int i = 0; i < 10; i++)
    {
        queue.add(i);
    }

cout << queue.lenght() << endl;
queue.clear();
   while(queue.lenght() > 0)
    {
      cout<<  queue.front() << endl;
        queue.remove();
    }

   QueueToStack<int> stack;

   for(int i = 0; i < 5; i++)
   {
       stack.push(i);
   }
    stack.clear();
   while(stack.size() > 0)
   {
       cout << stack.top() << endl;
       stack.pop();
   }
/*
   LinkQueue<int> que;
   for(int i = 0; i < 5; i++)
   {
       que.add(i);
   }

   while( que.lenght() > 0)
   {
       cout << que.front() << endl;
       que.remove();
   }*/

    return 0;
}


