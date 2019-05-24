#include <iostream>
#include <cstring>
#include <cstdlib>
#include "StaticStack.h"
#include "LinkStack.h"


using namespace std;
using namespace jamLib;

bool left_id(char c)
{
    return  (c=='{') || (c == '[') || ( c=='(' ) || ( c== '<' );
}
bool right_id(char c)
{
    return ( c=='}' ) || ( c== ']') || ( c==')' ) || ( c=='>') ;
}

bool double_id(char c)
{
    return ( c == '\'' ) || (c == '\"') ;
}

bool scan(const char* str)
{
    LinkStack<char> lslist;
    str = (str == nullptr) ? "" : str;

    int i = 0;
    while (str[i] != '\0')
    {
        if( left_id(str[i]) )
        {
            lslist.push(str[i]);
        }
        else if( right_id(str[i]) && (lslist.top() == str[i]) )
        {
            lslist.pop();
        }
        else
        {
            if( double_id(str[i]) )
            {
                if(lslist.top() == str[i])
                {
                    lslist.pop() ;
                }
                else
                {
                    lslist.push(str[i]) ;
                }
            }
        }

        i++;
    }
    return ( lslist.size() == 0 ) && (i > 0);
}

int main()
{

    cout<< scan("}") << endl;

    return 0;
}


