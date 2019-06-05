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




JString::~JString()
{
    free(m_str);
}

}
