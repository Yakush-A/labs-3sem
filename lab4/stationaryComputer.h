#pragma once
#ifndef STATIONARYCOMPUTER_H
#define STATIONARYCOMPUTER_H

#include"computer.h"

class StationaryComputer : public Computer          //класс Стационарный Компьютер 
{
protected:
    unsigned PSUPowerInWatts;                       //мощность блока питания
public:
    StationaryComputer() : Computer(), PSUPowerInWatts(0)
    {
    }
    StationaryComputer(unsigned RAM, unsigned storage, 
        std::string CPU, std::string GPU,
        unsigned PSU) :
        Computer(RAM, storage, CPU, GPU), PSUPowerInWatts(PSU)
    {
    }
    
    StationaryComputer(StationaryComputer& src) = default;
    ~StationaryComputer() = default;

    //геттеры-сеттеры
    inline void setPSUPower(unsigned power);
    inline unsigned getPSUPower();

    //перегрузка ввода-вывода
    friend inline std::ostream& operator << (std::ostream& os, StationaryComputer& PC);
    friend inline std::istream& operator >> (std::istream& is, StationaryComputer& PC);

    //функция печати шапки таблицы
    virtual inline void printTable();

    // Операторы сравнения
    bool operator==(const StationaryComputer& other) const;
    bool operator!=(const StationaryComputer& other) const;
    bool operator<(const StationaryComputer& other) const;
    bool operator>(const StationaryComputer& other) const;
    bool operator<=(const StationaryComputer& other) const;
    bool operator>=(const StationaryComputer& other) const;
};


#include"stationaryComputer.cpp"

#endif