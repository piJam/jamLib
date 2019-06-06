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

    bool operator == (const char* s) const;
    bool operator == (const JString& s) const;

    bool operator != (const char* s) const;
    bool operator != (const JString& s) const;

    bool operator > (const char* s) const;
    bool operator > (const JString& s) const;

    bool operator < (const char* s) const;
    bool operator < (const JString& s) const;

    bool operator >= (const char* s) const;
    bool operator >= (const JString& s) const;

    bool operator <= (const char* s) const;
    bool operator <= (const JString& s) const;

    JString operator + (const char* s) const;
    JString operator + (const JString& s) const;

    JString& operator += (const char* s);
    JString& operator += (const JString& s);

    JString& operator = (const char* s);
    JString& operator = (const JString& s);
    JString& operator = (const char s);




    ~JString();
};

}



#endif // JSTRING_H
