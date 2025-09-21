#include"string.h"

String String::operator + (String& src)
{
    char* tmp = new char[mLength + src.mLength + 1]{};
    if(mLength     != 0) strcat(tmp, mpStr);
    if(src.mLength != 0) strcat(tmp, src.mpStr);
    return String(tmp);
}
String& String::operator += (String& src)
{
    mLength += src.mLength;
    char* tmp = new char[mLength + 1]{};
    if(mLength     != 0) strcat(tmp, mpStr);
    if(src.mLength != 0) strcat(tmp, src.mpStr);
    
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

String& String::operator = (String& src)
{
    std::cout<<"<Перегруженный =>"<<std::endl;
    if(mpStr != src.mpStr)
    {
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
std::ostream& operator << (std::ostream& os, String& str)
{
    os<<str.mpStr;

    return os;
}


inline bool String::operator < (String str)
{
    return strcmp(mpStr, str.mpStr) == 1;
}
inline bool String::operator > (String str)
{
    return strcmp(mpStr, str.mpStr) == -1;
}
inline bool String::operator == (String str)
{
    return strcmp(mpStr, str.mpStr) == 0;
}
inline bool String::operator != (String str)
{
    return strcmp(mpStr, str.mpStr) != 0;
}

