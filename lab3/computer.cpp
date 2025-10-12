#include"computer.h"
void Computer::setRAM(unsigned long size)
{
    this->RAMInGBytes = size;
}
void Computer::setStorage(unsigned long capacity)
{
    this->storageCapacityInGBytes = capacity;
}
void Computer::setCPUName(std::string name)
{
    this->CPUName = name;
}
void Computer::setGPUName(std::string name)
{
    this->GPUName = name;
}


unsigned long Computer::getRAM()
{
    return RAMInGBytes;
}
unsigned long Computer::getStorage()
{
    return storageCapacityInGBytes;
}
std::string Computer::getCPUName()
{
    return CPUName;
}
std::string Computer::getGPUName()
{
    return GPUName;
} 


std::ostream& operator << (std::ostream& os, Computer& PC)
{
    os<<std::setw(5)<<PC.RAMInGBytes<<"GB|"<<
        std::setw(5)<<PC.storageCapacityInGBytes<<"GB|"<<
        std::setw(15)<<PC.CPUName<<'|'<<
        std::setw(15)<<PC.GPUName;
    return os;
} 
