#include"computer.cpp"
#include"stationaryComputer.cpp"
#include"portableComputer.cpp"
#include"tablet.cpp"
#include"laptop.cpp"
#include"monoblock.cpp"

int main(void)
{
    Computer* dihpc;

    Computer niggapc(16, 1000, "kykyryzen 9", "rtx 6090");
    PortableComputer wiggapc(32, 256, "ryzen ai 9", "integrated", 100);
    
    dihpc = &niggapc;

    dihpc->printTable();
    std::cout<<niggapc<<std::endl;

    dihpc = &wiggapc;

    dihpc->printTable();
    std::cout<<wiggapc<<std::endl;
}