#ifndef EXCEPTION_H
#define EXCEPTION_H
namespace jamLib{
class Exception
{
private:
    char* m_message;
    char* m_location;

    void init(const char* message,const char* file,int line);
public:
    Exception(const char* message);
    Exception(const char* file,int line);
    Exception(const char* message,const char* file,int line);

    Exception(const Exception& e);
    Exception& operator =(const Exception& e);

    virtual const char* message() const;
    virtual const char* location() const;
    virtual ~Exception()=0;


};
}


#endif // EXCEPTION_H
