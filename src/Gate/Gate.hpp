#ifndef GATE_HPP
#define GATE_HPP

class Gate{

    public:

    int f_not(int);
    int f_and(int*, int);
    int f_or(int*, int);
    int f_nand(int*, int);
    int f_nor(int*, int);
    int f_ao222(int*);
    int f_aoi22(int*);
};


#endif