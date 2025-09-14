#include "matrix.cpp"

int main()
{
    Matrix matrix1(4, 5);

    matrix1.fill();
    matrix1.print();

    Matrix matrix2(3,3);
    matrix2.fill();
    matrix2.print();

    matrix1.chsize(3, 3);
    std::cout<<std::endl;

}