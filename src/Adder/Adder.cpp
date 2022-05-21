#include<Adder.hpp>
#include<Gate.hpp>

Adder::Adder(){
    S = 0;
    C_out = 0;
}

int Adder::getS(){
    return S;
}

int Adder::getC_out(){
    return C_out;
}

void Adder::full_circuit(int *inp){ // 3 wejscia
    Gate xor1, xor2;

    int xor1_out, nor_inp[2];

    int tabA[2];
    tabA[0] = inp[0];
    tabA[1] = inp[1];

    xor1.f_xor(inp, 2);
    xor1_out = xor1.gateValue();

    tabA[0] = xor1_out;
    tabA[1] = inp[2];

    xor2.f_xor(tabA, 2);
    S = xor2.gateValue();

    Gate and1, and2, or1;
    and1.f_and(tabA, 2);
    nor_inp[0] = and1.gateValue();
    and2.f_and(inp, 2);
    nor_inp[1] = and2.gateValue();

    or1.f_or(nor_inp, 2);
    C_out = or1.gateValue();
}

void Adder::half_circuit(int *inp){ // 3 wejscia
    Gate xorg, andg;

    xorg.f_xor(inp, 2);
    S = xorg.gateValue();
    andg.f_and(inp, 2);
    C_out = andg.gateValue();
}