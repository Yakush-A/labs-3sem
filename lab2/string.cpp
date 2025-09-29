#include"string.h"

String operator + (const char* left, const String& right)
{
    return String(left) + right;
}
String operator + (const String& left, const char* right)
{
    return left + String(right);
}

String operator + (const String& left, const String& right)
{
    String sum;
    sum.mSize = left.mSize + right.mSize;
    
    if(sum.mSize != 0) 
    {    sum.mpStr = new char[sum.mSize + 1];
    
        if(left.mpStr != nullptr) strcat(sum.mpStr, left.mpStr);
        else sum.mpStr[0] = '\0';

        if(right.mpStr != nullptr)strcat(sum.mpStr, right.mpStr);
    }
    return sum;
}

String& String::operator += (const String& src)
{
    *this = *this + src;
    return *this;
}

inline char32_t String::operator [] (unsigned index)
{
    if(mpStr == nullptr) return 0;

    unsigned counter{};
    unsigned pos{};


    while(index > counter)
    {
        if(index > mSize) return 0;

        if ((mpStr[pos] & 0x80) == 0x00) pos += 1;  
        else if ((mpStr[pos] & 0xE0) == 0xC0) pos += 2;
        else if ((mpStr[pos] & 0xF0) == 0xE0) pos += 3;
        else if ((mpStr[pos] & 0xF8) == 0xF0) pos += 4;
        counter++;
    }

    unsigned length; 
    if ((mpStr[pos] & 0x80) == 0x00) length = 1;  
    else if ((mpStr[pos] & 0xE0) == 0xC0) length = 2;
    else if ((mpStr[pos] & 0xF0) == 0xE0) length = 3;
    else if ((mpStr[pos] & 0xF8) == 0xF0) length = 4;

    for(int i=0; i<4; i++)
    {
        
    }

    return 0;

    // if(index < mSize) return mpStr[index];
    // else return 0;
}

String& String::operator = (const String& src)
{
    if(this != &src)
    {
        if(mpStr != nullptr) delete[] mpStr;

        mSize = src.mSize;
        
        if(src.mpStr != nullptr)
        {
            mpStr = new char[src.mSize+1]{};
            strcpy(mpStr, src.mpStr);
        }
    }
    return *this;
}

String String::operator () (unsigned start, unsigned length)
{
    String res;

    if(mSize >= start + length && length != 0)
    {
        res.mpStr = new char[length + 1]{};
        res.mSize = length;

        strncpy(res.mpStr, mpStr+start, length);
    }
    else std::cout<<"Ошибка! Неверный размер подстроки!"<<std::endl;
    return res;
} 

std::istream& operator >> (std::istream& is, String& str)
{
    char buffer[81]{};
    is >> buffer;
    
    str.mSize = strlen(buffer);
    
    str.mpStr = new char[str.mSize+1]{};
    strcpy(str.mpStr, buffer);

    return is;
}
std::ostream& operator << (std::ostream& os, const String& str)
{
    os<<str.mpStr;

    return os;
}


inline bool String::operator <= (const String& str)
{
    return strcmp(mpStr, str.mpStr) != 1;
}
inline bool String::operator >= (const String& str)
{
    return strcmp(mpStr, str.mpStr) != -1;
}
inline bool String::operator <  (const String& str)
{
    return strcmp(mpStr, str.mpStr) == 1;
}
inline bool String::operator >  (const String& str)
{
    return strcmp(mpStr, str.mpStr) == -1;
}
inline bool String::operator == (const String& str)
{
    return strcmp(mpStr, str.mpStr) == 0;
}
inline bool String::operator != (const String& str)
{
    return strcmp(mpStr, str.mpStr) != 0;
}

inline unsigned String::size()
{
    return mSize;
}
inline unsigned String::length()
{
    unsigned length{};
    for(unsigned i{}; i<mSize; i++)
    {
        if((mpStr[i] & 0x40) != 0x00) length++;
    }
    return length;
}

