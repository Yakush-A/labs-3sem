#pragma once
#ifndef PORTABLECOMPUTER_H
#define PORTABLECOMPUTER_H 

#include"computer.h"

class PortableComputer : public Computer            //класс Портативный Компьютер
{
protected:
    unsigned batteryCapacityInWH;                   //ёмкость батареи

public:
    PortableComputer() : Computer(), batteryCapacityInWH(0)
    {}
    PortableComputer(unsigned RAM, unsigned storage, 
        std::string CPU, std::string GPU,
        unsigned battery) :
        Computer(RAM, storage, CPU, GPU), batteryCapacityInWH(0)
    {}

    PortableComputer(PortableComputer& src) = default;
    ~PortableComputer() = default;

    //перегрузка ввода-вывода
    friend inline std::ostream& operator << (std::ostream& os, PortableComputer& PC);
    friend inline std::istream& operator >> (std::istream& is, PortableComputer& PC);

    //сеттеры-геттеры
    inline void setBatteryCapacity(unsigned capacity);
    inline unsigned getBatteryCapacity();

    //функция печати шапки таблицы
    virtual inline void printTable();

    // Операторы сравнения
    bool operator==(const PortableComputer& other) const;
    bool operator!=(const PortableComputer& other) const;
    bool operator<(const PortableComputer& other) const;
    bool operator>(const PortableComputer& other) const;
    bool operator<=(const PortableComputer& other) const;
    bool operator>=(const PortableComputer& other) const;
};

#include"portableComputer.cpp"

#endif