#include "computer.cpp"
#include "stationaryComputer.cpp"
#include "portableComputer.cpp"
#include "tablet.cpp"
#include "laptop.cpp"
#include "monoblock.cpp"

const int ARRAY_SIZE = 5;

void computerMenu(Computer computers[]);
void portableComputerMenu(PortableComputer computers[]);
void stationaryComputerMenu(StationaryComputer computers[]);
void tabletMenu(Tablet tablets[]);
void laptopMenu(Laptop laptops[]);
void monoblockMenu(Monoblock monoblocks[]);

// Меню для базового класса Computer
void computerMenu(Computer computers[])
{
    int index, choice;
    unsigned ram, storage;
    std::string cpu, gpu;

    do
    {
        std::cout << "\n=== МЕНЮ КОМПЬЮТЕРОВ ===" << std::endl;
        std::cout << "1. Показать все компьютеры" << std::endl;
        std::cout << "2. Ввести новый компьютер" << std::endl;
        std::cout << "3. Изменить ОЗУ" << std::endl;
        std::cout << "4. Изменить ПЗУ" << std::endl;
        std::cout << "5. Изменить процессор" << std::endl;
        std::cout << "6. Изменить видеокарту" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "Выбор: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                computers[0].printTable();
                for (int i = 0; i < ARRAY_SIZE; i++)
                {
                    std::cout << (i + 1) << ". " << computers[i] << std::endl;
                }
                break;
            case 2:
                std::cout << "Введите индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cin >> computers[index - 1];
                }
                break;
            case 3:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "ОЗУ (ГБ): ";
                    std::cin >> ram;
                    computers[index - 1].setRAM(ram);
                }
                break;
            case 4:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "ПЗУ (ГБ): ";
                    std::cin >> storage;
                    computers[index - 1].setStorage(storage);
                }
                break;
            case 5:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "Процессор: ";
                    std::cin.ignore();
                    std::getline(std::cin, cpu);
                    computers[index - 1].setCPUName(cpu);
                }
                break;
            case 6:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "Видеокарта: ";
                    std::cin.ignore();
                    std::getline(std::cin, gpu);
                    computers[index - 1].setGPUName(gpu);
                }
                break;
        }
    } while (choice != 0);
}

// Меню для портативных компьютеров
void portableComputerMenu(PortableComputer computers[])
{
    int index, choice;
    unsigned ram, storage, battery;
    std::string cpu, gpu;

    do
    {
        std::cout << "\n=== МЕНЮ ПОРТАТИВНЫХ КОМПЬЮТЕРОВ ===" << std::endl;
        std::cout << "1. Показать все" << std::endl;
        std::cout << "2. Ввести новый" << std::endl;
        std::cout << "3. Изменить ОЗУ" << std::endl;
        std::cout << "4. Изменить ПЗУ" << std::endl;
        std::cout << "5. Изменить процессор" << std::endl;
        std::cout << "6. Изменить видеокарту" << std::endl;
        std::cout << "7. Изменить батарею" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "Выбор: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                computers[0].printTable();
                for (int i = 0; i < ARRAY_SIZE; i++)
                {
                    std::cout << (i + 1) << ". " << computers[i] << std::endl;
                }
                break;
            case 2:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cin >> computers[index - 1];
                }
                break;
            case 3:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "ОЗУ (ГБ): ";
                    std::cin >> ram;
                    computers[index - 1].setRAM(ram);
                }
                break;
            case 4:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "ПЗУ (ГБ): ";
                    std::cin >> storage;
                    computers[index - 1].setStorage(storage);
                }
                break;
            case 5:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "Процессор: ";
                    std::cin.ignore();
                    std::getline(std::cin, cpu);
                    computers[index - 1].setCPUName(cpu);
                }
                break;
            case 6:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "Видеокарта: ";
                    std::cin.ignore();
                    std::getline(std::cin, gpu);
                    computers[index - 1].setGPUName(gpu);
                }
                break;
            case 7:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "Батарея (Вт*ч): ";
                    std::cin >> battery;
                    computers[index - 1].setBatteryCapacity(battery);
                }
                break;
        }
    } while (choice != 0);
}

// Меню для стационарных компьютеров
void stationaryComputerMenu(StationaryComputer computers[])
{
    int index, choice;
    unsigned ram, storage, psu;
    std::string cpu, gpu;

    do
    {
        std::cout << "\n=== МЕНЮ СТАЦИОНАРНЫХ КОМПЬЮТЕРОВ ===" << std::endl;
        std::cout << "1. Показать все" << std::endl;
        std::cout << "2. Ввести новый" << std::endl;
        std::cout << "3. Изменить ОЗУ" << std::endl;
        std::cout << "4. Изменить ПЗУ" << std::endl;
        std::cout << "5. Изменить процессор" << std::endl;
        std::cout << "6. Изменить видеокарту" << std::endl;
        std::cout << "7. Изменить БП" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "Выбор: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                computers[0].printTable();
                for (int i = 0; i < ARRAY_SIZE; i++)
                {
                    std::cout << (i + 1) << ". " << computers[i] << std::endl;
                }
                break;
            case 2:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cin >> computers[index - 1];
                }
                break;
            case 3:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "ОЗУ (ГБ): ";
                    std::cin >> ram;
                    computers[index - 1].setRAM(ram);
                }
                break;
            case 4:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "ПЗУ (ГБ): ";
                    std::cin >> storage;
                    computers[index - 1].setStorage(storage);
                }
                break;
            case 5:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "Процессор: ";
                    std::cin.ignore();
                    std::getline(std::cin, cpu);
                    computers[index - 1].setCPUName(cpu);
                }
                break;
            case 6:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "Видеокарта: ";
                    std::cin.ignore();
                    std::getline(std::cin, gpu);
                    computers[index - 1].setGPUName(gpu);
                }
                break;
            case 7:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "Мощность БП (Вт): ";
                    std::cin >> psu;
                    computers[index - 1].setPSUPower(psu);
                }
                break;
        }
    } while (choice != 0);
}

// Меню для планшетов
void tabletMenu(Tablet tablets[])
{
    int index, choice;
    unsigned ram, storage, battery;
    std::string cpu, gpu;

    do
    {
        std::cout << "\n=== МЕНЮ ПЛАНШЕТОВ ===" << std::endl;
        std::cout << "1. Показать все" << std::endl;
        std::cout << "2. Ввести новый" << std::endl;
        std::cout << "3. Изменить ОЗУ" << std::endl;
        std::cout << "4. Изменить ПЗУ" << std::endl;
        std::cout << "5. Изменить процессор" << std::endl;
        std::cout << "6. Изменить видеокарту" << std::endl;
        std::cout << "7. Изменить батарею" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "Выбор: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                tablets[0].printTable();
                for (int i = 0; i < ARRAY_SIZE; i++)
                {
                    std::cout << (i + 1) << ". " << tablets[i] << std::endl;
                }
                break;
            case 2:
                std::cout << "Введите индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cin >> tablets[index];
                }
                break;
            case 3:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "ОЗУ (ГБ): ";
                    std::cin >> ram;
                    tablets[index].setRAM(ram);
                }
                break;
            case 4:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "ПЗУ (ГБ): ";
                    std::cin >> storage;
                    tablets[index].setStorage(storage);
                }
                break;
            case 5:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "Процессор: ";
                    std::cin.ignore();
                    std::getline(std::cin, cpu);
                    tablets[index].setCPUName(cpu);
                }
                break;
            case 6:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "Видеокарта: ";
                    std::cin.ignore();
                    std::getline(std::cin, gpu);
                    tablets[index].setGPUName(gpu);
                }
                break;
            case 7:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "Батарея (Вт*ч): ";
                    std::cin >> battery;
                    tablets[index].setBatteryCapacity(battery);
                }
                break;
        }
    } while (choice != 0);
}

// Меню для ноутбуков
void laptopMenu(Laptop laptops[])
{
    int index, choice;
    unsigned ram, storage, battery;
    std::string cpu, gpu;

    do
    {
        std::cout << "\n=== МЕНЮ НОУТБУКОВ ===" << std::endl;
        std::cout << "1. Показать все" << std::endl;
        std::cout << "2. Ввести новый" << std::endl;
        std::cout << "3. Изменить ОЗУ" << std::endl;
        std::cout << "4. Изменить ПЗУ" << std::endl;
        std::cout << "5. Изменить процессор" << std::endl;
        std::cout << "6. Изменить видеокарту" << std::endl;
        std::cout << "7. Изменить батарею" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "Выбор: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                laptops[0].printTable();
                for (int i = 0; i < ARRAY_SIZE; i++)
                {
                    std::cout << (i + 1) << ". " << laptops[i] << std::endl;
                }
                break;
            case 2:
                std::cout << "Введите индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cin >> laptops[index];
                }
                break;
            case 3:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "ОЗУ (ГБ): ";
                    std::cin >> ram;
                    laptops[index].setRAM(ram);
                }
                break;
            case 4:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "ПЗУ (ГБ): ";
                    std::cin >> storage;
                    laptops[index].setStorage(storage);
                }
                break;
            case 5:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "Процессор: ";
                    std::cin.ignore();
                    std::getline(std::cin, cpu);
                    laptops[index].setCPUName(cpu);
                }
                break;
            case 6:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "Видеокарта: ";
                    std::cin.ignore();
                    std::getline(std::cin, gpu);
                    laptops[index].setGPUName(gpu);
                }
                break;
            case 7:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "Батарея (Вт*ч): ";
                    std::cin >> battery;
                    laptops[index].setBatteryCapacity(battery);
                }
                break;
        }
    } while (choice != 0);
}

// Меню для моноблоков
void monoblockMenu(Monoblock monoblocks[])
{
    int index, choice;
    unsigned ram, storage, psu;
    std::string cpu, gpu;

    do
    {
        std::cout << "\n=== МЕНЮ МОНОБЛОКОВ ===" << std::endl;
        std::cout << "1. Показать все" << std::endl;
        std::cout << "2. Ввести новый" << std::endl;
        std::cout << "3. Изменить ОЗУ" << std::endl;
        std::cout << "4. Изменить ПЗУ" << std::endl;
        std::cout << "5. Изменить процессор" << std::endl;
        std::cout << "6. Изменить видеокарту" << std::endl;
        std::cout << "7. Изменить мощность БП" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "Выбор: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                monoblocks[0].printTable();
                for (int i = 0; i < ARRAY_SIZE; i++)
                {
                    std::cout << (i + 1) << ". " << monoblocks[i] << std::endl;
                }
                break;
            case 2:
                std::cout << "Введите индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cin >> monoblocks[index];
                }
                break;
            case 3:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "ОЗУ (ГБ): ";
                    std::cin >> ram;
                    monoblocks[index].setRAM(ram);
                }
                break;
            case 4:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "ПЗУ (ГБ): ";
                    std::cin >> storage;
                    monoblocks[index].setStorage(storage);
                }
                break;
            case 5:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "Процессор: ";
                    std::cin.ignore();
                    std::getline(std::cin, cpu);
                    monoblocks[index].setCPUName(cpu);
                }
                break;
            case 6:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "Видеокарта: ";
                    std::cin.ignore();
                    std::getline(std::cin, gpu);
                    monoblocks[index].setGPUName(gpu);
                }
                break;
            case 7:
                std::cout << "Индекс (1-" << ARRAY_SIZE << "): ";
                std::cin >> index;
                if (index >= 0 && index < ARRAY_SIZE)
                {
                    std::cout << "Мощность БП (Вт): ";
                    std::cin >> psu;
                    monoblocks[index].setPSUPower(psu);
                }
                break;
        }
    } while (choice != 0);
}
