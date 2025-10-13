#pragma once
#include"portableComputer.h" 

class Laptop : public PortableComputer
{
protected:
    std::string keyboardLayout;    

public:
    Laptop() : PortableComputer(), keyboardLayout()
    {}
    Laptop(unsigned RAM, unsigned storage, 
        std::string CPU, std::string GPU,
        unsigned battery, std::string keyboard) :

        PortableComputer(RAM, storage, CPU, GPU, battery), 
        keyboardLayout(keyboard)
    {}
    
    Laptop(Laptop& src);
    ~Laptop();

    friend inline std::ostream& operator << (std::ostream& os, Laptop& PC);

    inline void setKeyboardLayout(std::string layout);
    inline std::string getKeyboardLayout();

    virtual inline void printTable();

};



