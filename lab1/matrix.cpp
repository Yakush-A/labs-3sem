#include"matrix.h"

//функция вывода матрицы на экран
void Matrix::print()
{
    if(mpMatrix!=nullptr)
    {
        for(unsigned i=0; i<mRows; i++)
        {
            for(unsigned j=0; j<mCols; j++)
            {
                std::cout<<std::setw(7)<<mpMatrix[i*mCols+j]<<' ';
            }
            std::cout<<std::endl;
        }
    }
}

//функция заполнения матрицы с клавиатуры
void Matrix::fill()
{
    if(mpMatrix!=0)
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
void Matrix::add(Matrix& m)
{
    if(m.mRows==mRows && m.mCols==mCols && mpMatrix != 0)
    {
        for(unsigned i=0; i<mRows*mCols; i++)
        mpMatrix[i]+=m.mpMatrix[i];
    }
    else std::cout<<"Ошибка! Матрицы имеют разный размер!"<<std::endl;
}
