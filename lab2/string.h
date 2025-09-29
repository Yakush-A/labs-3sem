#include<iostream>
#include<iomanip>
#include<cstring>

class String
{

private:
    char* mpStr;
    unsigned mLength;

public:
    String() : mLength(0), mpStr(nullptr)
    {

    }

    String(const char* src) : mLength(0), mpStr(nullptr)
    {
        if(src != nullptr)
        {
            mLength = strlen(src);
            mpStr = new char[mLength+1]{};
            strcpy(mpStr, src);
        }
    }

    String(String& src)
    {
        mLength = src.mLength;

        if(mLength != 0)
        {
            mpStr = new char[mLength+1]{};
            strcpy(mpStr, src.mpStr);
        }        
        else mpStr = nullptr;
    }


    ~String()
    {
        if(mpStr != nullptr) delete[] mpStr;
    }

    inline unsigned length();

    String& operator = (const String& src);

    String& operator += (const String& src);
    
    friend String operator + (char* left, String& right);
    friend String operator + (String& left, char* right);
    friend String operator + (String& left, String& right);

    friend std::istream& operator >> (std::istream& is, String& str);
    friend std::ostream& operator << (std::ostream& os, const String& str);
    

    inline bool operator <= (const String& str);
    inline bool operator >= (const String& str);
    inline bool operator <  (const String& str);
    inline bool operator >  (const String& str);
    inline bool operator == (const String& str);
    inline bool operator != (const String& str);
    inline char operator [] (unsigned index);
};