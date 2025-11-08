inline void Laptop::setKeyboardLayout(std::string layout)
{
    keyboardLayout = layout;
}

inline std::string Laptop::getKeyboardLayout()
{
    return keyboardLayout;
}


inline void Laptop::printTable()
{
    std::cout<<"| ОЗУ | ПЗУ |   Процессор   |Граф. Процессор| Батарея, Вт*ч |Раскладка |"<<std::endl;
}

inline std::ostream& operator << (std::ostream& os, Laptop& PC)
{
        os<<static_cast<PortableComputer&>(PC)<<
        std::setw(10)<<std::left<<PC.keyboardLayout<<'|';

    return os;
}


inline std::istream& operator >> (std::istream& is, Laptop& PC)
{
    is>>static_cast<PortableComputer&>(PC);
    std::cout<<"Введите раскладку клавиатуры: ";
    std::getline(is, PC.keyboardLayout, '\n');
 
    return is;
}

bool Laptop::operator==(const Laptop& other) const 
{
    return PortableComputer::operator==(other) &&
           keyboardLayout == other.keyboardLayout;
}

bool Laptop::operator!=(const Laptop& other) const
{
    return !(*this == other);
}

bool Laptop::operator<(const Laptop& other) const 
{
    if (!PortableComputer::operator==(other))
        return PortableComputer::operator<(other);
    return keyboardLayout < other.keyboardLayout;
}

bool Laptop::operator>(const Laptop& other) const 
{
    return other < *this;
}

bool Laptop::operator<=(const Laptop& other) const 
{
    return !(other < *this);
}

bool Laptop::operator>=(const Laptop& other) const 
{
    return !(*this < other);
}