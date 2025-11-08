#ifndef INTERFACE_H
#define INTERFACE_H

#include "computer.h"
#include "laptop.h"
#include "tablet.h"
#include "tree.h"
#include "monoblock.h"
#include "stationaryComputer.h"
#include "portableComputer.h"
#include <iostream>

class Interface
{
private:

    //конейнеры для разных типов вычислительных машин
    Tree<Computer> computerContainer;                       //контейнер для ВМ
    Tree<StationaryComputer> stationaryComputerContainer;   //конейнер для стационарных ВМ
    Tree<PortableComputer> portableComputerContainer;       //контейнер для портативных ВМ
    Tree<Monoblock> monoblockContainer;                     //контейнер для моноблоков
    Tree<Laptop> laptopContainer;                           //контейнер для ноутбуков
    Tree<Tablet> tabletContainer;                           //контейнер для планшетов

public:
    void menu();                                            //функция меню для выбора типа ВМ

    template <typename T>
    void containerMenu(Tree<T>& container);                 //функция работы с выбранным контейнером

    inline void printContainerMenu();                       //функция вывода подсказки по опциям для работы
    inline void printAvaibleContainers();                   //функция вывода подсказки по доступным контейнерам
};

#include "interface.cpp"

#endif