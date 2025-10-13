#include"portableComputer.h"

class Tablet : public PortableComputer
{
protected:
    unsigned multiTouchSensorCapacity;

public:
    Tablet() : PortableComputer(), multiTouchSensorCapacity()
    {
    }
    Tablet(unsigned RAM, unsigned storage, 
        std::string CPU, std::string GPU,
        unsigned battery, unsigned multiTouch) :

        PortableComputer(RAM, storage, CPU, GPU, battery), 
        multiTouchSensorCapacity(multiTouch)
    {
    }
    
    Tablet(Tablet& src);
    ~Tablet();

    friend inline std::ostream& operator << (std::ostream& os, Tablet& PC);
 

    inline void setMultiTouchCapacity(unsigned multiTouch);
    inline unsigned getMultiTouchCapacity();

    virtual inline void printTable();
};