#include<Exact.hpp>
#include<Adder.hpp>

Exact::Exact(){
    S = 0;
    C_out = 0;
    carry = 0;
}

int Exact::getC_out(){
    return C_out;
}

int Exact::getcarry(){
    return carry;
}

int Exact::getS(){
    return S;
}

void Exact::circuit(int* inp, int c_in){
    Adder adder1, adder2;

    int* tabA = new int[3];

    int j = 3;

    for(int i = 0; i < 3; i++){
        tabA[i] = inp[j];
        j--;
    }

    adder1.full_circuit(tabA);

    C_out = adder1.getC_out();

    tabA = new int[3];
    tabA[0] = adder1.getS();
    tabA[1] = inp[0];
    tabA[2] = c_in;

    adder2.full_circuit(tabA);

    S = adder2.getS();
    carry = adder2.getC_out();
}