#pragma once
#ifndef MONOBLOCK_H
#define MONOBLOCK_H

#include"stationaryComputer.h"

class Monoblock : public StationaryComputer     //класс Моноблок
{
protected:
    double screenSize;                          //размер экрана

public:
    Monoblock() : StationaryComputer(), screenSize(0.0)
    {}
    Monoblock(unsigned RAM, unsigned storage, 
        std::string CPU, std::string GPU,
        unsigned PSU, double screen) :
        StationaryComputer(RAM, storage, CPU, GPU, PSU),screenSize(0)
    {}

    Monoblock(Monoblock& src) = default;
    ~Monoblock() = default;

    //перегрузка ввода-вывода
    friend inline std::ostream& operator << (std::ostream& os, Monoblock& PC);
    friend inline std::istream& operator >> (std::istream& is, Monoblock& PC);

    //сеттеры-геттеры
    inline void setScreenSize(float diagonal);
    inline float getScreenSize();

    //функция печати шапки таблицы
    virtual inline void printTable();


    bool operator==(const Monoblock& other) const;
    bool operator!=(const Monoblock& other) const;
    bool operator<(const Monoblock& other) const;
    bool operator>(const Monoblock& other) const;
    bool operator<=(const Monoblock& other) const;
    bool operator>=(const Monoblock& other) const;
};

#include"monoblock.cpp"

#endif