#ifndef GATE_HPP
#define GATE_HPP

class Gate{

    
    private:
    int g_outp;

    public:

    Gate();
    int gateValue();
    void f_not(int);
    void f_and(int*, int);
    void f_or(int*, int);
    void f_nand(int*, int);
    void f_nor(int*, int);
    void f_xor(int*, int);
    void f_ao222(int*);
    void f_ao22(int*);
    void f_aoi22(int*);
};


#endif