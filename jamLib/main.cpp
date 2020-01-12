#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

#include "test.h"
#include "Array.h".h"
#include "LinkQueue.h"

using namespace std;
using namespace jamLib;

int main()
{
    int a[] = {2,15,3,4,20,0,23};
    for(int i=0; i<7; i++)
    {
        cout << a[i] << endl;
    }

    SharedPointer< Graph<int, int> > sp = create_graph(a, 7);

    SharedPointer< Array<int> > sp1 = (*sp).DFS(5);

    for(int i=0; i<sp1->length(); i++)
    {
        int k = (*sp1)[i];
         cout<< (*sp1)[i] << ":" << a[k] << "  ";
    }
    cout << endl;

    return 0;
}







