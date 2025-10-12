#pragma once
#include"computer.h"
#include"screen.h"

class PortableComputer : public Computer, public Screen 
{
private:
    unsigned int batteryCapacityInWH;

public:
    PortableComputer();
    PortableComputer(PortableComputer& src);
    ~PortableComputer();

};