#ifndef PRO2_HPP
#define PRO2_HPP

class Pro2{

    
    private:
    int S;
    int C;

    public:

    Pro2();
    int getC();
    int getS();
    void circuit(int*);

    private:
    int calA(int *inp);
    int calB(int *inp);
    int calC(int *inp);
    int calD(int *inp);
    int calE(int *inp);
    int cal_cinput4(int *inp);
};

#endif