#pragma once
#include"computer.h"

class PortableComputer : public Computer 
{
protected:
    unsigned batteryCapacityInWH;

public:
    PortableComputer() : Computer(), batteryCapacityInWH(0)
    {
    }
    PortableComputer(unsigned RAM, unsigned storage, 
        std::string CPU, std::string GPU,
        unsigned battery) :
        Computer(RAM, storage, CPU, GPU), batteryCapacityInWH(0)
    {
    }

    PortableComputer(PortableComputer& src)
    {
        
    }
    ~PortableComputer()
    {

    }

    friend inline std::ostream& operator << (std::ostream& os, PortableComputer& PC);

    inline void setBatteryCapacity(unsigned capacity);
    inline unsigned getBatteryCapacity();

    virtual inline void printTable();
};

