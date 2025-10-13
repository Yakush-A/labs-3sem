#include<iostream>
#include<iomanip>
#include<cstring>

class String
{

protected:
    //указатель на массив символов
    char* mpStr; 
    //размер массива
    unsigned mSize;

public:
    //конструкторы без, с параметрами
    String() : mSize(0), mpStr(nullptr)
    { }

    String(const char* src)
    {
        mSize = strlen(src);
        if(mSize != 0)
        {
            mpStr = new char[mSize+1]{};
            strcpy(mpStr, src);
        }
        else mpStr = nullptr;
    }

    //конструктор копирования
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

    //деструктор
    ~String()
    {
        if(mpStr != nullptr && mSize != 0) delete[] mpStr;
    }

    //метод получения размера в байтах строки
    inline unsigned size();

    //метод получения длины в символах строки
    inline unsigned length();

    //оператор присваивания
    String& operator = (const String& src);
    
    String& operator += (const String& src);
    
    //оператор получения подстроки длиной length начиная с символа start
    String operator () (unsigned start, unsigned length);  

    //перегрузки +
    friend String operator + (const char* left, const String& right);
    friend String operator + (const String& left, const char* right);
    friend String operator + (const String& left, const String& right);
    
    //перегрузки ввода-вывода
    friend std::istream& operator >> (std::istream& is, String& str);
    friend std::ostream& operator << (std::ostream& os, const String& str);
    
    //оператор получения элемента строки
    inline char operator [] (unsigned index);

    //операции лексикографического сравнения строк 
    inline bool operator <= (const String& str);
    inline bool operator >= (const String& str);
    inline bool operator <  (const String& str);
    inline bool operator >  (const String& str);
    inline bool operator == (const String& str);
    inline bool operator != (const String& str);

    //операции инкремента/декремента
    String& operator ++ (int);
    String& operator -- (int);
};