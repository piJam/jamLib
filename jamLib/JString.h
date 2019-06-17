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
    bool equal(const char* l, const char* r, int len) const;
    static int* make_pmt(const char* p);
    static int kmp(const char* str, const char* pStr );
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

    JString operator - (const char* s) const;
    JString operator - (const JString& s) const;

    JString& operator += (const char* s);
    JString& operator += (const JString& s);

    JString& operator -= (const char* s);
    JString& operator -= (const JString& s);

    JString& operator = (const char* s);
    JString& operator = (const JString& s);
    JString& operator = (const char s);

    char& operator[](int index);
    char operator[](int index) const;

    bool startWith(const char* s) const;
    bool startWith(const JString& s) const;

    bool endOf(const char* s) const;
    bool endOf(const JString& s) const;

    JString& insert(int i,const char* s);
    JString& insert(int i,const JString& s);

    JString& trim();

    int indexOf(const char* s) const;
    int indexOf(const JString& s) const;

    JString& remove(int index,int len);
    JString& remove(const char* s);
    JString& remove(const JString& s);

    JString& replace(const char* t, const char* s);
    JString& replace(const char* t, const JString& s);
    JString& replace(const JString& t, const JString& s);
    JString& replace(const JString& t, const char* s);

    JString sub(int index, int len) const;


    ~JString();
};

}



#endif // JSTRING_H
