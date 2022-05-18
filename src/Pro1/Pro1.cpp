#include <Pro1.hpp>
#include <Gate.hpp>

Pro1::Pro1(){
    S = 0;
    C = 0;
}

int Pro1::getC(){
    return C;
}

int Pro1::getS(){
    return S;
}

void Pro1::circuit(int *inp){

    int *a_input = new int [2];
    int *b_input = new int [2];
    int *c_input = new int [2];
    int *d_input = new int [2];

    for(int i = 0; i < 2; i++)
        a_input[i] = inp[i];

    b_input = a_input;

    int k = 2;
    for(int i = 0; i < 2; i++)
    {
        c_input[i] = inp[k];
        k++;
    }

    d_input = c_input;

    int A, B, C, D;
    A = calA(a_input);
    B = calB(b_input);
    C = calC(c_input);
    D = calD(d_input);

    int sinput;
    int cinput;

    sinput = calD(a_input); // ten sam mini ukladzik ale inne wejscia

    delete [] a_input;

    cinput = calB(c_input);

    delete [] c_input;

    Gate gate1, gate2;
    Gate not1, not4, not5, not6;

    int* gate1_input = new int [6];
    int* gate2_input = new int [6];

    not1.f_not(sinput);
    gate1_input[0] = not1.gateValue();
    gate1_input[1] = D;
    gate1_input[2] = sinput;
    not4.f_not(D);
    gate1_input[3] = not4.gateValue();
    not5.f_not(B);
    gate1_input[4] = not5.gateValue();
    not6.f_not(cinput);
    gate1_input[5] = not6.gateValue();

    gate2_input[0] = B;
    gate2_input[1] = C;
    gate2_input[2] = A;
    gate2_input[3] = cinput;

    gate1.f_ao222(gate1_input);
    gate2.f_aoi22(gate2_input);

    delete [] gate1_input;
    delete [] gate2_input;

    S = gate1.gateValue();
    this->C = gate2.gateValue();
}

int Pro1::calA(int *inp){
    Gate nor;
    nor.f_nor(inp, 2);
    return nor.gateValue();
}

int Pro1::calB(int *inp){
    Gate nand;
    nand.f_nand(inp, 2);
    return nand.gateValue();
}

int Pro1::calC(int *inp){
    Gate nor;
    nor.f_nor(inp, 2);
    return nor.gateValue();
}

int Pro1::calD(int *inp){
    Gate nor, nand1, nand2, notgate;
    int *output = new int [2];

    nor.f_nor(inp, 2);
    output[0] = nor.gateValue();

    notgate.f_not(output[0]);
    output[0] = notgate.gateValue();

    nand1.f_nand(inp, 2);
    output[1] = nand1.gateValue();

    nand2.f_nand(output, 2);

    delete [] output;

    return nand2.gateValue();
}