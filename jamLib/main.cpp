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

int kmp(const char* str, const char* pStr )
{
    int ret = -1;
    int slen = strlen(str);
    int plen = strlen(pStr);

    int* pmt = make_pmt(pStr);

    if( (pmt != NULL) && (slen >= plen) && (plen > 0) )
    {
        for(int i=0, j=0; i<slen; i++)
        {
            while( str[i] != pStr[j] && (j > 0))
            {
                j = pmt[j - 1];
            }

            if(str[i] == pStr[j] )
            {
                j++;
            }

            if( j == plen )
            {
                ret = i + 1 - plen;
                break;
            }
        }

    }
    return ret;
}

int main()
{


    char* p = "ABCDABD";

    int* ret = make_pmt(p);

    for(int i = 0; i< strlen("ABCDABD"); i++)
    {
        cout<< i << ":" << ret[i] << endl;
    }

    char* str = "cdsABCDABDeewew";
    cout<< kmp(str,p) << endl;
    return 0;
}


