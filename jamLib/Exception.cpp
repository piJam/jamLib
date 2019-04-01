#include"Exception.h"
#include <cstdlib>
#include <cstring>
namespace jamLib
{

void Exception::init(const char *message, const char *file, int line)
{
    m_message = strdup(message);

    if(file != NULL)
    {

    }
}



}
