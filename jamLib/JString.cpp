#include "JString.h"
#include <cstring>
#include <cstdlib>
namespace jamLib
{
void JString::init(const char *s)
{
    m_str = strdup(s);
    if(m_str)
    {
         m_length = strlen(s);
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException,"no memory to create JString object... ");
    }
}

JString::JString()
{
    init("");
}

JString::JString(const char* s)
{
    init( s ? s : "");
}

JString::JString(const char c)
{
    char str[] = {c, '\0'};
    init(str);
}

JString::JString(const JString& s)
{
    init(s.m_str);
}

int JString::lenght() const
{
    return m_length;
}

const char* JString::str() const
{
    return m_str;
}

bool JString::operator == (const char* s) const
{
    return ( strcmp(m_str, s ? s : "") == 0 );
}

bool JString::operator == (const JString& s) const
{
    return ( strcmp(m_str, s.m_str) == 0);
}

bool JString::operator != (const char* s) const
{
    return !( *this == s );
}
bool JString::operator != (const JString& s) const
{
    return !( *this == s.m_str );
}
bool JString::operator > (const char* s) const
{
   return ( strcmp(m_str, s ? s : "") > 0 );
}
bool JString::operator > (const JString& s) const
{
    return ( strcmp(m_str, s.m_str) > 0 );
}

bool JString::operator < (const char* s) const
{
    return ( strcmp(m_str, s ? s : "") > 0 );
}
bool JString::operator < (const JString& s) const
{
    return ( strcmp(m_str, s.m_str) > 0 );
}
bool JString::operator >= (const char* s) const
{
    return ( strcmp(m_str, s ? s : "") >= 0 );
}
bool JString::operator >= (const JString& s) const
{
    return ( strcmp(m_str, s.m_str) >= 0 );
}

bool JString::operator <= (const char* s) const
{
    return ( strcmp(m_str, s ? s : "") <= 0 );
}
bool JString::operator <= (const JString& s) const
{
    return ( strcmp(m_str, s.m_str) <= 0 );
}
JString JString::operator + (const char* s) const
{
    JString ret;
    int len = m_length + strlen( s ? s : "");
    char* str_p = reinterpret_cast<char*> ( malloc( len + 1 ) );
    if(str_p)
    {
        strcpy(str_p, m_str);
        strcat(str_p, s ? s : "");

        free(ret.m_str);

        ret.m_str = str_p;
        ret.m_length = len;
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException,"no memory to create JString object... ");
    }
    return ret;
}

JString JString::operator + (const JString& s) const  // waring if suecc
{
    return *this + s.m_str;
}

JString& JString::operator += (const char* s)
{
    return ( *this = *this + s );
}
JString& JString::operator += (const JString& s)
{
    return ( *this = *this + s.m_str );
}

JString& JString::operator = (const char* s)
{
    if( m_str != s)
    {
        char* str = strdup( s ? s : "");
        if( str )
        {
            free( m_str );
            m_length = strlen(str);
            m_str = str;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "no memory to str...");
        }

    }

    return *this;
}

JString& JString::operator = (const JString& s)
{
    return ( *this = s.m_str );
}

 JString& JString::operator = (const char s)
 {
     char str[] = {s,'\0'};
     return (*this = str);
 }
JString::~JString()
{
    free(m_str);
}

}
