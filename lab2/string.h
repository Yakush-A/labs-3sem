#include<iostream>
#include<iomanip>
#include<cstring>

class String
{

private:
    char* mpStr;
    unsigned mSize;

public:
    String() : mSize(0), mpStr(nullptr) {}

    String(const char* src) : mSize(0), mpStr(nullptr)
    {
        if(src != nullptr)
        {
            mSize = strlen(src);
            mpStr = new char[mSize+1]{};
            strcpy(mpStr, src);
        }
    }

    String(String& src)
    {        
        mSize = src.mSize;
        if(mSize != 0)
        {
            mpStr = new char[mSize+1]{};
            strcpy(mpStr, src.mpStr);
        }
        else mpStr = nullptr;
    }

    ~String()
    {
        if(mpStr != nullptr) delete[] mpStr;
    }

    inline unsigned size();
    inline unsigned length();

    String& operator = (const String& src);
    
    String& operator += (const String& src);
    
    String operator () (unsigned start, unsigned length); 

    friend String operator + (const char* left, const String& right);
    friend String operator + (const String& left, const char* right);
    friend String operator + (const String& left, const String& right);
    
    friend std::istream& operator >> (std::istream& is, String& str);
    friend std::ostream& operator << (std::ostream& os, const String& str);
    
    inline bool operator <  (const String& str);
    inline bool operator >  (const String& str);
    inline bool operator <= (const String& str);
    inline bool operator >= (const String& str);
    inline bool operator == (const String& str);
    inline bool operator != (const String& str);
    inline char32_t operator [] (unsigned index);
};