#pragma once
#ifndef COMPUTER_H
#define COMPUTER_H

#include<iostream>
#include<iomanip>
#include<string>
#include<limits>

class Computer                                  //класс Компьютер (Вычислительная Машина)
{
protected:
    unsigned RAMInGBytes;                       //объём ОЗУ
    unsigned storageCapacityInGBytes;           //объем ПЗУ
    std::string CPUName;                        //модель центрального процессора
    std::string GPUName;                        //модель графического процессора

public:
    Computer() : 
        RAMInGBytes(0), storageCapacityInGBytes(0),
        CPUName(), GPUName()
    {
    } 
    Computer(unsigned RAM, unsigned storage, 
        std::string CPU, std::string GPU) :
        RAMInGBytes(RAM), storageCapacityInGBytes(storage), 
        CPUName(CPU), GPUName(GPU) 
    {
    }

    Computer(Computer& src) = default;
    ~Computer() = default;


    //перегрузка ввода-вывода
    friend inline std::ostream& operator << (std::ostream& os, Computer& PC); 
    friend inline std::istream& operator >> (std::istream& is, Computer& PC);

    //функция печати шапки таблицы
    virtual inline void printTable();

    //сеттеры
    inline void setRAM(unsigned size);
    inline void setStorage(unsigned capacity);
    inline void setCPUName(std::string name);
    inline void setGPUName(std::string name);

    //геттеры
    inline unsigned getRAM();
    inline unsigned getStorage();
    inline std::string getCPUName();
    inline std::string getGPUName();


    bool operator==(const Computer& other) const;
    bool operator!=(const Computer& other) const;
    bool operator<(const Computer& other) const;
    bool operator>(const Computer& other) const;
    bool operator<=(const Computer& other) const;
    bool operator>=(const Computer& other) const;

};

#include"computer.cpp"

#endif