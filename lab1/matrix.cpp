#include"matrix.h"

//функция вывода матрицы на экран
void Matrix::printTable()
{
    if(mpMatrix!=nullptr)
    {
        for(unsigned i=0; i<mRows; i++)
        {
            for(unsigned j=0; j<mCols; j++)
            {
                std::cout<<std::setw(7)<<std::left<<
                mpMatrix[i*mCols+j]<<' ';
            }
            std::cout<<std::endl;
        }
    }
}

//функция заполнения матрицы с клавиатуры
void Matrix::fill()
{
    if(mpMatrix!=nullptr)
    {
        for(unsigned i=0; i<mRows; i++)
        {
            for(unsigned j=0; j<mCols; j++)
            {
                std::cout<<"Введите ["<<i+1<<"]["<<j+1<<"] элемент матрицы: ";
                std::cin>>mpMatrix[i*mCols+j];
            }
        }
    }
}

//функция добавления к матрице другой матрицы
Matrix& Matrix::add(Matrix& m)
{
    if(mpMatrix!=nullptr && m.mpMatrix!=nullptr)
    {
        for(unsigned i=0; i<mRows*mCols; i++)
        this->mpMatrix[i]+=m.mpMatrix[i];
    }
    else std::cout<<"Ошибка! Матрицы должны быть инициализированы!"<<std::endl;

    return *this;
}
