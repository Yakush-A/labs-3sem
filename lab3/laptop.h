#pragma once
#include"portableComputer.h" 
#include"screen.h" 

class Laptop : public PortableComputer, public Screen
{
private:
    std::string keyboardLayout;    

public:
    Laptop();
    ~Laptop();
};
