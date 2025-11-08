//функция вывода подсказки по доступным контейнерам
inline void Interface::printAvaibleContainers()
{
    std::cout
        <<"-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-;\n"
        <<"Доступные меню контейнеров:\n"
        <<"c - меню для компьютеров;\n"
        <<"p - меню для портативных компьютеров;\n"
        <<"s - меню для стациорарных компьютеров;\n"
        <<"m - меню для моноблоков;\n"
        <<"t - менб для планшетов;\n"
        <<"l - меню для ноутбуков;\n"
        <<"x - Выйти из меню;\n"
        <<"-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-;\n"
        <<"Введите опцию контейнера: ";
}

//функция вывода подсказки по опциям для работы
inline void Interface::printContainerMenu()
{
    std::cout
        <<"-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-;\n"
        <<"Доступные опции:\n"
        <<"i - Добавить элемент в контейнер;\n"
        <<"d - Удалить элемент из контейнера;\n"
        <<"p - Вывести на экран элементы контейнера;\n"
        <<"f - Найти элемент в контейнере;\n"
        <<"x - Выйти из меню;\n"
        <<"-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-;\n"
        <<"Введите требуемую опцию: ";
}


//функция меню для выбора типа ВМ
void Interface::menu()
{
    char option{};
    do 
    {
        printAvaibleContainers();
        std::cin>>option;

        switch(option)                                      //выбор типа ВМ
        {
            case 'c':
                containerMenu(computerContainer);           //ВМ (компьютер)
                break;

            case 'p':
                containerMenu(portableComputerContainer);   //портативная ВМ
                break;
            
            case 's':
                containerMenu(stationaryComputerContainer); //стационарная ВМ
                break;
            
            case 'l':
                containerMenu(laptopContainer);             //ноутбук
                break;
            
            case 'm':
                containerMenu(monoblockContainer);          //моноблок
                break;

            case 't':
                containerMenu(tabletContainer);             //планшет
                break;

            case 'x': break;
            default: std::cout<<"Ошибка! Выберите корректную опцию!"<<std::endl;
        }
    } while(option != 'x');
}

//функция работы с выбранным контейнером
template <typename T>
void Interface::containerMenu(Tree<T>& container)
{
    char option{};
    T buffer;

    do 
    {
        printContainerMenu();
        std::cin>>option;

        switch(option)
        {
            case 'i':                                       //добавление элемента в контейнер
            {
                std::cout<<"Выбрано добавление элемента:"<<std::endl;
                std::cin>>buffer;
                container.insert(buffer);
                std::cout<<"Элемент добавлен успешно."<<std::endl;

                break;
            }
            
            case 'p':                                       //вывод на экран содержимого контейнера
            {
                if(container.empty())
                {
                    std::cout<<"Контейнер пуст."<<std::endl;
                    break;
                }
                else
                {
                    buffer.printTable();
                    std::cout<<container;
                    break;
                }
            }
            
            case 'd':                                       //удаление элемента из контейнера
            {
                if(container.empty())
                {
                    std::cout<<"Контейнер пуст."<<std::endl;
                    break;
                }
                std::cout<<"Выбрано удаление элемента:\nВведите элемент, который требуется удалить:"<<std::endl;
                std::cin>>buffer;
                container.erase(buffer);
                std::cout<<"Элемент успешно удалён."<<std::endl;

                break;
            }
            
            case 'f':                                       //определение, есть ли искомый элемент в контейнере
            {
                if(container.empty())
                {
                    std::cout<<"Контейнер пуст."<<std::endl;
                    break;
                }
                
                std::cout<<"Выбран поиск элемента:\nВведите элемент, который требуется найти:"<<std::endl;
                std::cin>>buffer;

                if(container.contains(buffer)) 
                    std::cout<<"Элемент с введенными данными присутствует."<<std::endl;
                else 
                    std::cout<<"Элемента с введенными данными не обнаружено."<<std::endl;
                
                break;
            }
            case 'x': break;
            default: std::cout<<"Ошибка! Выберите корректную опцию!"<<std::endl;
        }
    } while(option != 'x');
}