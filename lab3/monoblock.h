#pragma once

#include"stationaryComputer.h"


class Monoblock : public StationaryComputer
{
protected:
    double screenSize;

public:
    Monoblock() : StationaryComputer(), screenSize(0.0)
    {
    }
    Monoblock(unsigned RAM, unsigned storage, 
        std::string CPU, std::string GPU,
        unsigned PSU, double screen) :
        StationaryComputer(RAM, storage, CPU, GPU, PSU),screenSize(0)
    {
    }

    friend inline std::ostream& operator << (std::ostream& os, Monoblock& PC);

    Monoblock(Monoblock& src);
    ~Monoblock();

    virtual inline void printTable();

};