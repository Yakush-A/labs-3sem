#pragma once
#include<iostream>
#include<iomanip>
#include<string>

class Computer
{
protected:
    unsigned RAMInGBytes;
    unsigned storageCapacityInGBytes;
    std::string CPUName;
    std::string GPUName;

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

    Computer(Computer& src)
    {   
    }
    ~Computer()
    {
    }


    friend inline std::ostream& operator << (std::ostream& os, Computer& PC); 

    virtual inline void printTable();

    inline void setRAM(unsigned size);
    inline void setStorage(unsigned capacity);
    inline void setCPUName(std::string name);
    inline void setGPUName(std::string name);


    inline unsigned getRAM();
    inline unsigned getStorage();
    inline std::string getCPUName();
    inline std::string getGPUName();

};