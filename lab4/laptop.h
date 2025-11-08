#pragma once
#ifndef LAPTOP_H
#define LAPTOP_H

#include"portableComputer.h" 

class Laptop : public PortableComputer              //класс Ноутбук
{
protected:
    std::string keyboardLayout;                     //раскладка клавиатуры

public:
    Laptop() : PortableComputer(), keyboardLayout()
    {}
    Laptop(unsigned RAM, unsigned storage, 
        std::string CPU, std::string GPU,
        unsigned battery, std::string keyboard) :

        PortableComputer(RAM, storage, CPU, GPU, battery), 
        keyboardLayout(keyboard)
    {}
    
    Laptop(Laptop& src) = default;
    ~Laptop() = default;

    //перегрузка ввода-вывода
    friend inline std::ostream& operator << (std::ostream& os, Laptop& PC);
    friend inline std::istream& operator >> (std::istream& is, Laptop& PC);

    //set-еры, get-еры
    inline void setKeyboardLayout(std::string layout);
    inline std::string getKeyboardLayout();

    //функция печати шапки таблицы
    virtual inline void printTable();


    // Операторы сравнения
    bool operator==(const Laptop& other) const;
    bool operator!=(const Laptop& other) const;
    bool operator<(const Laptop& other) const;
    bool operator>(const Laptop& other) const;
    bool operator<=(const Laptop& other) const;
    bool operator>=(const Laptop& other) const;
};

#include"laptop.cpp"

#endif