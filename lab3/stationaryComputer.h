#pragma once
#include"computer.h"

class StationaryComputer : public Computer 
{
protected:
    unsigned PSUPowerInWatts;
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

    inline void setPSUPower(unsigned power);
    inline unsigned getPSUPower();

    friend inline std::ostream& operator << (std::ostream& os, StationaryComputer& PC);

    
    StationaryComputer(StationaryComputer& src);
    ~StationaryComputer();

    virtual inline void printTable();
};