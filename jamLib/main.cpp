#include <iostream>
#include <cstring>
#include <cstdlib>
#include "JString.h"
using namespace std;
using namespace jamLib;

int* make_pmt(const char* p)
{
    int len = strlen(p);
    int* ret = static_cast<int*>(malloc(sizeof(int) * len));
    int longestLength = 0;
    ret[0] = 0;

    for(int i = 1; i<len ; i++)
    {
        while( longestLength > 0 && p[longestLength] != p[i] )
        {
            longestLength = ret[ longestLength - 1];
        }

        if(p[longestLength] == p[i])
        {
            longestLength++;
        }
        ret[i] = longestLength;
    }
    return ret;
}


int main()
{


    char* p = "ABABDABA";

    int* ret = make_pmt(p);

    for(int i = 0; i< strlen("ABABDABA"); i++)
    {
        cout<< i << ":" << ret[i] << endl;
    }
    return 0;
}


