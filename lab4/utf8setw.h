#pragma once
#include <iostream>

inline unsigned utf8len(const std::string& str)
{
    unsigned len = 0;
    for (unsigned i = 0; i < str.size(); ++i)
    {
        char c = static_cast<char>(str[i]);
        if ((c & 0b11000000) != 0b10000000)                    //байт, начинающий символ
            ++len;
    }
    return len;
}

class utf8setw
{
private:
    unsigned width_;
    std::string str_;
public:
    utf8setw(unsigned width, std::string str) : width_(width), str_(str) { }

    friend std::ostream& operator<<(std::ostream& o_stream, const utf8setw& manip)
    {
        unsigned len = utf8len(manip.str_);
        if (len < manip.width_)
            o_stream << manip.str_ << std::setw(manip.width_ - len) << "";
        else
            o_stream << manip.str_;
        return o_stream;
    }
};