#ifndef PRO1_HPP
#define PRO1_HPP

class Pro1{

    
    private:
    int S;
    int C;

    public:

    Pro1();
    int getC();
    int getS();
    void circuit(int*);

    private:
    int calA(int *inp);
    int calB(int *inp);
    int calC(int *inp);
    int calD(int *inp);
    int cal_cinput4(int *inp);
};

#endif