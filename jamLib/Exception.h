#ifndef EXCEPTION_H
#define EXCEPTION_H
#include "Object.h"


namespace jamLib{

#define THROW_EXCEPTION(e,m) (throw e(m,__FILE__,__LINE__))
#define THROW(e) (throw e())

class Exception : public Object
{
private:
    char* m_message;
    char* m_location;


#ifdef __APPLE__

    void itoa(int line,char* str,int num);
    char getCharCode(int num);

#endif


    void init(const char* message,const char* file,int line);
public:
    Exception(const char* message);
    Exception(const char* file,int line);
    Exception(const char* message,const char* file,int line);

    Exception(const Exception& e);
    Exception& operator =(const Exception& e);

    virtual const char* message() const;
    virtual const char* location() const;
    virtual ~Exception() = 0;


};

/****************计算异常**********************/
class ArithmeticException : public Exception
{
public:
    ArithmeticException():Exception(0){}
    ArithmeticException(const char* message):Exception(message){}
    ArithmeticException(const char* file,int line):Exception(file,line){}
    ArithmeticException(const char* message,const char* file,int line):Exception(message,file,line){}

    ArithmeticException(const ArithmeticException& e):Exception(e){}
    ArithmeticException& operator =(const ArithmeticException& e)
    {
        Exception::operator =(e);
        return *this;
    }
};
/********************操作异常*********************/
class InvalidOperationException : public Exception
{
public:
    InvalidOperationException():Exception(0){}
    InvalidOperationException(const char* message):Exception(message){}
    InvalidOperationException(const char* file,int line):Exception(file,line){}
    InvalidOperationException(const char* message,const char* file,int line):Exception(message,file,line){}

    InvalidOperationException(const InvalidOperationException& e):Exception(e){}
    InvalidOperationException& operator =(const InvalidOperationException& e)
    { Exception::operator =(e);
      return *this;
    }

};
/*********************参数错误异常***********************/
class InvalidParameterException : public Exception
{
public:
    InvalidParameterException():Exception(0){}
    InvalidParameterException(const char* message):Exception(message){}
    InvalidParameterException(const char* file,int line):Exception(file,line){}
    InvalidParameterException(const char* message,const char* file,int line):Exception(message,file,line){}

    InvalidParameterException(const InvalidParameterException& e):Exception(e){}
    InvalidParameterException& operator =(const InvalidParameterException& e)
    { Exception::operator =(e);
      return *this;
    }

};
/**********************空指针异常*************************/
class NullPointException : public Exception
{
public:
    NullPointException():Exception(0){}
    NullPointException(const char* message):Exception(message){}
    NullPointException(const char* file,int line):Exception(file,line){}
    NullPointException(const char* message,const char* file,int line):Exception(message,file,line){}

    NullPointException(const NullPointException& e):Exception(e){}
    NullPointException& operator =(const NullPointException& e)
    { Exception::operator =(e);
      return *this;
    }

};
/*********************越界异常**********************/
class IndexOutOfBoundsException : public Exception
{
public:
    IndexOutOfBoundsException():Exception(0){}
    IndexOutOfBoundsException(const char* message):Exception(message){}
    IndexOutOfBoundsException(const char* file,int line):Exception(file,line){}
    IndexOutOfBoundsException(const char* message,const char* file,int line):Exception(message,file,line){}

    IndexOutOfBoundsException(const IndexOutOfBoundsException& e):Exception(e){}
    IndexOutOfBoundsException& operator =(const IndexOutOfBoundsException& e)
    { Exception::operator =(e);
      return *this;
    }

};
/********************内存不足异常************************/
class NoEnoughMemoryException : public Exception
{
public:
    NoEnoughMemoryException():Exception(0){}
    NoEnoughMemoryException(const char* message):Exception(message){}
    NoEnoughMemoryException(const char* file,int line):Exception(file,line){}
    NoEnoughMemoryException(const char* message,const char* file,int line):Exception(message,file,line){}

    NoEnoughMemoryException(const NoEnoughMemoryException& e):Exception(e){}
    NoEnoughMemoryException& operator =(const NoEnoughMemoryException& e)
    { Exception::operator =(e);
      return *this;
    }

};



}


#endif // EXCEPTION_H
