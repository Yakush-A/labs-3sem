#pragma once
#include<iostream>
#include<iomanip>
#include<string>

class Computer
{
private:
    unsigned long RAMInGBytes;
    unsigned long storageCapacityInGBytes;
    std::string CPUName;
    std::string GPUName;
    std::string motherBoardName;

public:
    Computer(unsigned long RAM, unsigned long storage, 
        std::string CPU, std::string GPU, std::string MoBo) :
        RAMInGBytes(RAM), storageCapacityInGBytes(storage), 
        CPUName(CPU), GPUName(GPU), motherBoardName(MoBo) 
    {
    }

    Computer(Computer& src)
    {
        
    }
    ~Computer()
    {

    }


    friend std::ostream& operator << (std::ostream& os, Computer& PC); 


    void setRAM(unsigned long size);
    void setStorage(unsigned long capacity);
    void setCPUName(std::string name);
    void setGPUName(std::string name);
    void setMoBoName(std::string name);


    unsigned long getRAM();
    unsigned long getStorage();
    std::string getCPUName();
    std::string getGPUName();
    std::string getMoBoName();

};