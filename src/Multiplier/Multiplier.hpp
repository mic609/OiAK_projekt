#ifndef MULTIPLIER_HPP
#define MULTIPLIER_HPP

class Multiplier{

    private:

    int *result;
    int matrixFS[8][15];
    int matrixSS[4][15];

    public:
    Multiplier();
    int* getResult();
    void multiply(int*, int*);
    void showMatrixSS();

    private:
    void fillMatrixFS(int*, int*);
};

#endif