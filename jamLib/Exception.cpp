#include"Exception.h"
#include <cstdlib>
#include <cstring>
#include <iostream>
namespace jamLib{

#ifdef __APPLE__

void Exception::itoa(int line, char *str, int num)
{
    int length = 0;
        for(int i = 10; i < 10000000; i*=10)
        {
              length++;
            if((line / i) == 0)
            {
                 break;
            }
        }

        for(int i = 1; i <= length; i++)
        {
            str[length - i] = getCharCode (line % 10) ;
            line /= 10;
        }
}

char Exception::getCharCode(int num)
{
  switch (num)
        {
            case 0:
               return 48;
            case 1:
               return 49;
            case 2:
               return 50;
            case 3:
                return 51;
            case 4:
                return 52;
            case 5:
                return 53;
            case 6:
                return 54;
            case 7:
                return 55;
            case 8:
                return 56;
            case 9:
                return 57;
        }

}

#endif
void Exception::init(const char *message, const char *file, int line)
{
    m_message = strdup(message);

    if(file != NULL)
    {
        char sl[16] = {0};
        itoa(line,sl,10);  //参数1，要转换的数字。参数2，字符数组的指针。参数3，要转换成的进制数
        m_location = static_cast<char*>(malloc(strlen(file) + strlen(sl) + 2));

        if(m_location != NULL)
        {
            m_location = strcpy(m_location, file);
            m_location = strcat(m_location, ":");
            m_location = strcat(m_location, sl);
        }

    }
    else
    {
        m_location = NULL;
    }
}

Exception::Exception(const char* message)
{
    init(message, NULL, 0);
}
Exception::Exception(const char* file,int line)
{
    init(NULL, file, line);
}
Exception::Exception(const char* message,const char* file,int line)
{
    init(message, file, line);
}

Exception::Exception(const Exception& e)
{
    m_message = strdup(e.m_message);
    m_location = strdup(e.m_location);
}
Exception& Exception::operator =(const Exception& e)
{
    if(this != &e)
    {
        free(m_message);
        free(m_location);

        m_message = strdup(e.m_message);
        m_location = strdup(e.m_location);
    }

    return *this;
}

const char* Exception::message() const
{
    return m_message;
}
const char* Exception::location() const
{
    return m_location;
}

Exception::~Exception()
{
    free(m_message);
    free(m_location);
}


}
