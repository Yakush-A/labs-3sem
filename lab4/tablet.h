#pragma once
#ifndef TABLET_H
#define TABLET_H

#include"portableComputer.h"

class Tablet : public PortableComputer          //класс Планшет
{
protected:
    unsigned multiTouchSensorCapacity;          //ёмкость мультитач сенсора

public:
    Tablet() : PortableComputer(), multiTouchSensorCapacity()
    {}
    Tablet(unsigned RAM, unsigned storage, 
        std::string CPU, std::string GPU,
        unsigned battery, unsigned multiTouch) :

        PortableComputer(RAM, storage, CPU, GPU, battery), 
        multiTouchSensorCapacity(multiTouch)
    {}
    
    Tablet(Tablet& src) = default;
    ~Tablet() = default;

    //перегрузка ввода-вывода
    friend inline std::ostream& operator << (std::ostream& os, Tablet& PC);
    friend inline std::istream& operator >> (std::istream& os, Tablet& PC);

    //геттеры-сеттеры
    inline void setMultiTouchCapacity(unsigned multiTouch);
    inline unsigned getMultiTouchCapacity();

    //функция печати шапки таблицы
    virtual inline void printTable();

    // Операторы сравнения
    bool operator==(const Tablet& other) const;
    bool operator!=(const Tablet& other) const;
    bool operator<(const Tablet& other) const;
    bool operator>(const Tablet& other) const;
    bool operator<=(const Tablet& other) const;
    bool operator>=(const Tablet& other) const;
};

#include"tablet.cpp"

#endif