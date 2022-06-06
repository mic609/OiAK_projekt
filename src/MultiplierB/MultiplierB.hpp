#ifndef MULTIPLIERB_HPP
#define MULTIPLIERB_HPP

class MultiplierB{

    private:

    int *result;
    int intResult;
    int matrixFS[8][15];
    int matrixSS[4][15];
    int matrixFinal[2][15];

    public:
    MultiplierB();
    void multiply(int*, int*);
    void getMultiplyResult();
    int getDecimalResult();
    void showMatrixFS();
    void showMatrixSS();
    void showMatrixFinal();

    private:
    void firstStage(int*, int*);
    void secondStage(int*, int*);
    void finalStage();
    void fillMatrixFS(int*, int*);
};

#endif