#include<iostream>
#include<iomanip>

class Matrix
{
    private:
    int *mpMatrix;                      //указатель на память, выделенную под матрицу
    unsigned mRows, mCols;              //количество строк и столбцов матрицы

    public:
    Matrix()                            //конструктор без параметров
    {
        mpMatrix = nullptr;
        mCols = mRows = 0;
    }
    Matrix(unsigned rows, unsigned cols)//конструктор с параметами 
    {                                   //(количество строк, столбцов матрицы)
        mRows = rows;
        mCols = cols;
        mpMatrix = new int[rows*cols];
    }

    Matrix(Matrix& m)                   //конструктор копирования
    {
        mRows = m.mRows;
        mCols = m.mCols;
        mpMatrix = new int[m.mRows*m.mCols];
        for(unsigned i=0; i<mRows*mCols; i++)
            mpMatrix[i] = m.mpMatrix[i];
    }

    ~Matrix()                           //деструктор
    {
        if(mpMatrix != nullptr) delete[] mpMatrix;
    }


    void print();                       //функция вывода матрицы на экран
    void fill();                        //функция заполнения матрицы с клавиатуры
    Matrix& add(Matrix& m);             //функция добавления к матрице другой матрицы

};