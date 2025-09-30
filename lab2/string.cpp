#include"string.h"

//перегрузка оператора + для разных типов операндов
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

//оператор получения элемента строки
inline char String::operator [] (unsigned index)
{
    if(index <= mSize && mSize != 0) return mpStr[index];
    else return 0;    
}

//оператор присваивания
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

//оператор получения подстроки длиной length начиная с символа start
String String::operator () (unsigned start, unsigned length)
{
    String res;

    if(mpStr == nullptr) return res;

    unsigned char_len;
    unsigned chars{}, start_pos{}, end_pos{};
    
    unsigned i{};
    while (i<mSize)
    {
        if      ((mpStr[i] & 0x80) == 0x00) char_len = 1;  
        else if ((mpStr[i] & 0xE0) == 0xC0) char_len = 2;
        else if ((mpStr[i] & 0xF0) == 0xE0) char_len = 3;
        else if ((mpStr[i] & 0xF8) == 0xF0) char_len = 4;

        if(chars == start) start_pos = i;

        chars++;
        if(chars == start + length){
            end_pos = i + char_len;
            break;
        } 
        i += char_len;
    }
    
    if(chars < start + length) return res;
    res.mSize = end_pos - start_pos;
    res.mpStr = new char[res.mSize + 1] {};

    strncpy(res.mpStr, mpStr+start_pos, res.mSize);

    return res;
} 

//перегрузки ввода-вывода
std::istream& operator >> (std::istream& is, String& str)
{
    char buffer[ 80 * sizeof(char32_t) + 1]{};
    
    std::cin.getline(buffer, 80*sizeof(char32_t));

    str.mSize = strlen(buffer);
    
    str.mpStr = new char[str.mSize+1]{};
    strcpy(str.mpStr, buffer);

    return is;
}
std::ostream& operator << (std::ostream& os, const String& str)
{
    if(str.mpStr != nullptr) os<<str.mpStr;

    return os;
}

//операции лексикографического сравнения строк 
inline bool String::operator <  (const String& str)
{
    return strcmp(mpStr, str.mpStr) != 1;
}
inline bool String::operator <= (const String& str)
{
    return strcmp(mpStr, str.mpStr) != 1;
}
inline bool String::operator >  (const String& str)
{
    return strcmp(mpStr, str.mpStr) == 1;
}
inline bool String::operator >= (const String& str)
{
    return strcmp(mpStr, str.mpStr) != -1;
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
        if((mpStr[i] & 0x40) != 0x00 || (mpStr[i] & 0x80) == 0x00) length++;
    return length;
}

//операции инкремента/декремента
String& String::operator ++ (int)
{
    if(mpStr == nullptr) return *this;

    unsigned char_len;   
    unsigned i{};
    while (i<mSize)
    {
        if ((mpStr[i] & 0x80) == 0x00) char_len = 1;  
        else if ((mpStr[i] & 0xE0) == 0xC0) char_len = 2;
        else if ((mpStr[i] & 0xF0) == 0xE0) char_len = 3;
        else if ((mpStr[i] & 0xF8) == 0xF0) char_len = 4;

        i += char_len;
        mpStr[i-1]++;
    }
    
    return *this;
}
String& String::operator -- (int)
{
    if(mpStr == nullptr) return *this;

    unsigned char_len;   
    unsigned i{};
    while (i<mSize)
    {
        if ((mpStr[i] & 0x80) == 0x00) char_len = 1;  
        else if ((mpStr[i] & 0xE0) == 0xC0) char_len = 2;
        else if ((mpStr[i] & 0xF0) == 0xE0) char_len = 3;
        else if ((mpStr[i] & 0xF8) == 0xF0) char_len = 4;

        i += char_len;
        mpStr[i-1]--;
    }
    
    return *this;
}