#include "matrix.cpp"

int main()
{
    bool exit_flag = false;

    while(!exit_flag)                                       //зацикливание программы
    {
        unsigned rows, cols;                                //ввод количества строк и столбцов матрицы
        std::cout<<"Введите количество строк матрицы: ";
        std::cin>>rows;
        std::cout<<"Введите количество столбцов матрицы: ";
        std::cin>>cols;

        std::cout<<"Ввод матрицы №1"<<std::endl;
        Matrix matrix1(rows, cols);                         //создание и заполнение первой матрицы
        matrix1.fill();
        std::cout<<"Матрица №1:"<<std::endl;
        matrix1.print();

        std::cout<<"Ввод матрицы №2"<<std::endl;
        Matrix matrix2(rows, cols);                         //создание и заполнение второй матрицы
        matrix2.fill();
        std::cout<<"Матрица №2:"<<std::endl;
        matrix2.print();

        std::cout<<"Сумма матриц №1 и №2:"<<std::endl;      //создание суммы матриц
        Matrix matrix12 = matrix1;
        matrix12.add(matrix2);
        matrix12.print();



        int option;
        std::cout<<"Введите 1 чтобы продолжить или любой другой символ для выхода: ";
        std::cin>>option;
        exit_flag = option != 1;
    }
}