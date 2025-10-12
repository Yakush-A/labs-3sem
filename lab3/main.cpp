#include"computer.cpp"
#include"stationaryComputer.cpp"
#include"tablet.cpp"
#include"laptop.cpp"
#include"monoblock.cpp"

int main(void)
{
    Computer* dihpc;

    Computer niggapc(16, 1000, "kykyryzen 9", "rtx 6090");
    
    dihpc = &niggapc;

    std::cout<<dihpc->getCPUName()<<std::endl;
    std::cout<<niggapc<<std::endl;
}