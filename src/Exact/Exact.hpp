#ifndef EXACT_HPP
#define EXACT_HPP

class Exact{

    private:

    int S;
    int carry;
    int C_out;

    public:
    Exact();
    int getC_out();
    int getcarry();
    int getS();
    void circuit(int*, int);
};

#endif