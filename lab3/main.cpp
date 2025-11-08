#include"menu.cpp"

int main()
{
    Computer computers[ARRAY_SIZE];                 // массивы объектов для разных классов устройств
    PortableComputer portables[ARRAY_SIZE];
    StationaryComputer stationaries[ARRAY_SIZE];
    Tablet tablets[ARRAY_SIZE];
    Laptop laptops[ARRAY_SIZE];
    Monoblock monoblocks[ARRAY_SIZE];

    int choice;
    do                                              //зацикливание программы
    {
        std::cout << "\n=== ГЛАВНОЕ МЕНЮ ===" << std::endl;
        std::cout << "1. Компьютеры" << std::endl;
        std::cout << "2. Портативные компьютеры" << std::endl;
        std::cout << "3. Стационарные компьютеры" << std::endl;
        std::cout << "4. Планшеты" << std::endl;
        std::cout << "5. Ноутбуки" << std::endl;
        std::cout << "6. Моноблоки" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выбор: ";
        std::cin >> choice;

        switch (choice)                             //выбор действия
        {
            case 1:
                computerMenu(computers);
                break;
            case 2:
                portableComputerMenu(portables);
                break;
            case 3:
                stationaryComputerMenu(stationaries);
                break;
            case 4:
                tabletMenu(tablets);
                break;
            case 5:
                laptopMenu(laptops);
                break;
            case 6:
                monoblockMenu(monoblocks);
                break;
        }
    } while (choice != 0);

    return 0;
}
