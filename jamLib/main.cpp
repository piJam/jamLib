#include <iostream>
#include <cstring>
#include <cstdlib>
#include "StaticQueue.h"


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
<<<<<<< HEAD
    StaticQueue<int, 10> queue;

    for(int i = 0; i < 10; i++)
    {
        queue.add(i);
    }

    for(int i = 0; i < queue.capacity(); i++)
    {
        cout<< queue.front() << endl;
        queue.remove();
    }
=======
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
>>>>>>> a512df02f82da9e9430afd443efd141ed9bebb2b

    cout<< scan("}") << endl;

    return 0;
}


