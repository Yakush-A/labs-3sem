#include"string.h"

String operator + (const char* left, const String& right)
{
    return String(left) + right;
}
String operator + (String& left, char* right)
{
    return left + String(right);
}

String operator + (String& left, String& right)
{
    String sum;
    sum.mLength = left.mLength + right.mLength;
    sum.mpStr = new char[sum.mLength + 1];
    
    return sum;
}

String& String::operator += (const String& src)
{
    mLength += src.mLength;
    char* tmp = new char[mLength + 1]{};

    strcat(tmp, mpStr);
    strcat(tmp, src.mpStr);
    
    delete[] mpStr;

    mpStr = tmp;
    mLength += src.mLength; 
    
    return *this;
}
inline char String::operator [] (unsigned index)
{
    if(index < mLength) return mpStr[index];
    else return 0;
}

String& String::operator = (const String& src)
{
    if(mpStr != src.mpStr)
    {
        delete[] mpStr;

        mLength = src.mLength;
        
        mpStr = new char[src.mLength+1]{};
        strcpy(mpStr, src.mpStr);
    }
    return *this;
}

std::istream& operator >> (std::istream& is, String& str)
{
    char buffer[81]{};
    is >> buffer;
    
    str.mLength = strlen(buffer);
    
    str.mpStr = new char[str.mLength+1]{};
    strcpy(str.mpStr, buffer);

    return is;
}
std::ostream& operator << (std::ostream& os, const String& str)
{
    os<<str.mpStr;

    return os;
}


inline bool String::operator<= (const String& str)
{
    return strcmp(mpStr, str.mpStr) != 1;
}
inline bool String::operator>= (const String& str)
{
    return strcmp(mpStr, str.mpStr) != 1;
}
inline bool String::operator<  (const String& str)
{
    return strcmp(mpStr, str.mpStr) != 1;
}
inline bool String::operator>  (const String& str)
{
    return strcmp(mpStr, str.mpStr) != 1;
}
inline bool String::operator== (const String& str)
{
    return strcmp(mpStr, str.mpStr) != 1;
}
inline bool String::operator!= (const String& str)
{
    return strcmp(mpStr, str.mpStr) != 1;
}
inline char String::operator [] (unsigned index)
{
    return mpStr[index];
}