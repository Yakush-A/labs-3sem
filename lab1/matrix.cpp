#include"matrix.h"
#include<iostream>
#include<iomanip>

void Matrix::print()
{
    if(mpMatrix!=nullptr)
    {
        for(unsigned i=0; i<mRows; i++)
        {
            for(unsigned j=0; j<mCols; j++)
            {
                std::cout<<mpMatrix[i*mCols+j]<<' ';
            }
            std::cout<<std::endl;
        }
    }
}
    
Matrix Matrix::fill()
{
    if(mpMatrix!=0)
    {
        for(unsigned i=0; i<mRows; i++)
        {
            for(unsigned j=0; j<mCols; j++)
            {
                std::cout<<std::setw(7)<<"Введите ["<<i+1<<"]["<<j+1<<"] элемент матрицы: ";
                std::cin>>mpMatrix[i*mCols+j];
            }
        }
    }
    return *this;
}

Matrix Matrix::add(Matrix& m)
{
    if(m.mRows==mRows && m.mCols==mCols && mpMatrix != 0)
    {
        for(unsigned i=0; i<mRows*mCols; i++)
        mpMatrix[i]+=m.mpMatrix[i];
    }
    else std::cout<<"Ошибка! Матрицы имеют разный размер!"<<std::endl;
    return *this;
}

Matrix Matrix::chsize(unsigned rows, unsigned cols)
{
    if(rows==0 || cols==0)
    {
        delete[] mpMatrix;
        mpMatrix = nullptr;
    }
    else if(mpMatrix)
    {
        int *tmp_ptr = new int[rows*cols];

        for(unsigned i=0; i<rows; i++)
            for(unsigned j=0; j<cols; j++)
                tmp_ptr[i*cols+j] = mpMatrix[i*mCols+j];
    }

    mRows = rows;
    mCols = cols;

    return *this;
}
