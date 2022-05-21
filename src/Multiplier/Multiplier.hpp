#ifndef MULTIPLIER_HPP
#define MULTIPLIER_HPP

class Multiplier{

    private:

    int *result;
    int intResult;
    int matrixFS[8][15];
    int matrixSS[4][15];
    int matrixFinal[2][15];

    public:
    Multiplier();
    int getDecimalResult();
    void multiply(int*, int*);
    void showMatrixSS();
    void showMatrixFinal();
    void getMultiplyResult();

    private:
    void firstStage(int*, int*);
    void secondStage(int*, int*);
    void fillMatrixFS(int*, int*);
    void finalStage();
};

#endif