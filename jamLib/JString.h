#ifndef JSTRING_H
#define JSTRING_H
#include "Object.h"
#include "Exception.h"
namespace jamLib
{
class JString : public Object
{
protected:
    char* m_str;
    int m_length;
    void init(const char* s);
public:
    JString();
    JString(const char* s);
    JString(const char c);
    JString(const JString& s);

    int lenght() const;
    const char* str() const;



    ~JString();
};

}



#endif // JSTRING_H
