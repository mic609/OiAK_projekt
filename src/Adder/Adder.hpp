#ifndef ADDER_HPP
#define ADDER_HPP

class Adder{
    private:

    int S;
    int C_out;

    public:

    Adder();
    int getC_out();
    int getS();
    void full_circuit(int*);
    void half_circuit(int*);
};
#endif