#include<iostream>
#include<iomanip>
#include<cstring>

class String
{

private:
    char* mpStr;
    unsigned mLength;

public:
    String() : mLength(0)
    {
        mpStr = new char(0);
    }

    String(const char* src)
    {
        mLength = strlen(src);
        mpStr = new char[mLength+1]{};
        strcpy(mpStr, src);
    }

    String(String src, unsigned start, unsigned length)
    {
        if(start + length <= src.mLength)
        {
            mLength = length;
            mpStr = new char[length+1];
            strncpy(mpStr, src.mpStr+start, length);
        }
        else 
        {
            std::cout<<"Ошибка! Некорректный размер подстроки"<<std::endl;
            mpStr = nullptr;
            mLength = 0;
        }
    }

    String(const char* src, unsigned start, unsigned length)
    {
        if(start + length <= strlen(src))
        {
            mLength = length;
            mpStr = new char[length+1];
            strncpy(mpStr, src+start, length);
        }
        else 
        {
            std::cout<<"Ошибка! Некорректный размер подстроки"<<std::endl;
            mpStr = nullptr;
            mLength = 0;
        }
    }


    String(String& src)
    {        
        mLength = src.mLength;
        mpStr = new char[mLength+1]{};
        strcpy(mpStr, src.mpStr);
    }


    ~String()
    {
        delete[] mpStr;
    }

    inline unsigned length();

    String& operator = (const String& src);
    
    String operator + (String& src);
    String& operator += (const String& src);
    
    friend String operator + (char* left, String& right);
    friend String operator + (String& left, char* right);
    friend String operator + (String& left, String& right);

    friend std::istream& operator >> (std::istream& is, String& str);
    friend std::ostream& operator << (std::ostream& os, const String& str);
    
    inline bool operator < (String const str);
    inline bool operator > (String const str);
    inline bool operator == (String const str);
    inline bool operator != (String const str);
    inline char operator [] (unsigned index);
};