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

bool JString::equal(const char* l, const char* r, int len) const
{
    bool ret = true;

    for(int i=0; i<len && ret; i++)
    {
        ret = ret && (l[i] == r[i]); // ret =  (l[i] == r[i]);
    }

    return ret;
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

char& JString::operator[](int index)
{
    if( (0 <= index) && (index < m_length) )
    {
        return *( m_str + index ) ;
    }
    else
    {
        THROW_EXCEPTION(InvalidOperationException, "Ivalid index...");
    }

}

char JString::operator [](int index) const
{
    return (const_cast<JString&>(*this))[index];
}

bool JString::startWith(const char* s) const
{
    bool ret = 1;
    ret = (s != NULL);
    if(ret)
    {
        int len = strlen(s);
        // ret = (len < m_length) && equal(m_str, s, len); dephi tang 实现如果是S是空字符串不能得到正确结果
        ret = (len < m_length) && (len > 0) && equal(m_str, s, len);

    }
    else
    {
        THROW_EXCEPTION(InvalidParameterException, " parameter S is NULL...");
    }
    return ret;
}

bool JString::startWith(const JString& s) const
{
    return startWith(s.m_str);
}


bool JString::endOf(const char* s) const
{
    bool ret = true;

    ret = (s != NULL);
    if(ret)
    {
        int len = strlen(s);
        char* str = m_str + m_length - len;
        ret = (len < m_length) && (len > 0) && equal(str, s, len);
    }
    else
    {
        THROW_EXCEPTION(InvalidParameterException, " parameter is null ...");
    }
    return ret;
}
bool JString::endOf(const JString& s) const
{
    return endOf(s.m_str);
}

JString& JString::insert(int i,const char* s)
{
   if( (0 <= i) && ( i<= m_length))
   {
       if( (s != NULL) && ( s[0] != '\0') )
       {
          char* str = reinterpret_cast<char*>( malloc( m_length + strlen(s) +1 ) );
          if(str)
          {
              strncpy(str, m_str, i);
              strncpy(str + i, s, strlen(s));
              strncpy(str + i + strlen(s), m_str + i, m_length - i);
              // == str[m_length + strlen(s)] = '\0';
              *(str + m_length + strlen(s)) = '\0';

              free(m_str);
              m_str = str;
              m_length = m_length + strlen(s);
          }
          else
          {
              THROW_EXCEPTION(NoEnoughMemoryException, "no memory to create...");
          }
       }
   }
   else
   {
       THROW_EXCEPTION(InvalidParameterException, "parament is invalid...");
   }

    return *this;
}
JString& JString::insert(int i,const JString& s)
{
    return insert(i, s.m_str);
}

JString& JString::trim()
{
    int font = 0;
    int end = m_length - 1;

    while( *(m_str + font) == ' ' ) font++;
    while( *(m_str + end)  == ' ' ) end--;
/*
    if(font > 0)
    {
        for(int i=0; i<(m_length - font); i++)
        {
            m_str[i] = m_str[i + font];
        }

        m_length = m_length - font;
        end = end - font;
    }

    if(end < m_length - 1)
    {
        m_str[end + 1] = '\0';

        m_length = strlen(m_str);
    }
*/
    if(font == 0)
    {
        m_str[end + 1] = '\0';
        m_length = end + 1;
    }
    else
    {
        for(int i=0, j=font; j<=end; i++, j++)
        {
            m_str[i] = m_str[j];
        }

        m_str[end - font + 1] = '\0';
        m_length = end - font + 1 ;
    }


    return *this;
}

JString::~JString()
{
    free(m_str);
}

}
