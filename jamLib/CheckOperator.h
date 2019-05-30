#ifndef CHECKOPERATOR_H
#define CHECKOPERATOR_H


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
bool match(char l, char r)
{
    return (l == '(' && r == ')') ||
           (l == '[' && r == ']') ||
           (l == '{' && r == '}') ||
           (l == '<' && r == '>') ||
           (l == '\'' && r == '\'')||
           (l == '\"' && r == '\"');
}

bool scan(const char* str)
{
    LinkStack<char> lslist;
    str = (str == nullptr) ? "" : str;

    bool ret = true;
    int i = 0;
    while (str[i] != '\0')
    {
        if( left_id(str[i]) )
        {
            lslist.push(str[i]);
        }
        else if( right_id(str[i]) )
        {
            if((lslist.size() > 0) && match(lslist.top(), str[i]))
            {
                lslist.pop();
            }
            else
            {
                ret = false;
            }
        }
        else if(double_id(str[i]))
        {
            if( (lslist.size() == 0) || !match( lslist.top(), str[i] )   )
            {
                lslist.push(str[i]);
            }
            else if(match( lslist.top(), str[i] ))
            {
                 lslist.pop();
            }
        }

        i++;
     }
    return ( lslist.size() == 0 ) && ret;
}

#endif // CHECKOPERATOR_H
