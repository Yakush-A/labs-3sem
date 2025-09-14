class Matrix
{
    private:
    int *mpMatrix;
    unsigned mRows, mCols;

    public:

    Matrix()
    {
        mpMatrix = nullptr;
        mCols = mRows = 0;
    }
    Matrix(unsigned rows, unsigned cols)
    {
        mRows = rows;
        mCols = cols;
        mpMatrix = new int[rows*cols];
    }

    Matrix(Matrix& m)
    {
        mRows = m.mRows;
        mCols = m.mCols;
        mpMatrix = new int[m.mRows*m.mCols];
        for(int i=0; i<mRows*mCols; i++)
            mpMatrix[i] = m.mpMatrix[i];
    }

    ~Matrix()
    {
        if(mpMatrix != nullptr) delete[] mpMatrix;
    }


    void print();
    
    Matrix chsize(unsigned rows, unsigned cols);
    Matrix fill();
    Matrix add(Matrix& m);

};