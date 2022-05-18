#include <Gate.hpp>

#include <iostream>

Gate::Gate(){
    g_outp = 0; 
}

int Gate::gateValue(){
    return g_outp;
}

void Gate::f_not(int inp){

    g_outp = inp;

    if(g_outp == 0) g_outp = 1;
    else if(g_outp == 1) g_outp = 0;
}

void Gate::f_and(int* inp, int n){

    for(int i = 0; i < n; i++)
        if(inp[i] < 0 || inp[i] > 1)
            std::cout << "Wrong number of an input. It should be 0 or 1";

    for(int i = 0; i < n; i++){
        if(!inp[i]){
            g_outp = 0;
            break;
        }
        else g_outp = 1;
    }
}

void Gate::f_or(int* inp, int n){

    for(int i = 0; i < n; i++)
        if(inp[i] < 0 || inp[i] > 1)
            std::cout << "Wrong number of an input. It should be 0 or 1";

    for(int i = 0; i < n; i++){
        if(inp[i]){
            g_outp = 1;
            break;
        }
        else g_outp = 0;
    }
}

void Gate::f_nand(int* inp, int n){
    for(int i = 0; i < n; i++)
        if(inp[i] < 0 || inp[i] > 1)
            std::cout << "Wrong number of an input. It should be 0 or 1";

    for(int i = 0; i < n; i++){
        if(!inp[i]){
            g_outp = 0;
            break;
        }
        else g_outp = 1;
    }

    if(g_outp) g_outp = 0;
    else g_outp = 1;
}

void Gate::f_nor(int* inp, int n){
    for(int i = 0; i < n; i++)
        if(inp[i] < 0 || inp[i] > 1)
            std::cout << "Wrong number of an input. It should be 0 or 1";

    for(int i = 0; i < n; i++){
        if(inp[i]){
            g_outp = 1;
            break;
        }
        else g_outp = 0;
    }

    if(g_outp) g_outp = 0;
    else g_outp = 1;
}

void Gate::f_ao222(int* inp){
    Gate* andg; // bramka and
    Gate norg; // bramka nor
    int* andoutp = new int[3]; // dane wyjsciowe z bramek and
    
    andg = new Gate [3]; // 3 bramki and

    int and_num = 0; // numer bramki and
    for(int i = 0; i < 6; i+=2){
        int *andinp = new int[2]; // tworzymy tablice 2 wejsc do bramki and

        int k = i;
        for(int j = 0; j < 2; j++){ // nastepuje przypisanie odpowiednich wartosci z tablicy inp do andinp
            andinp[j] = inp[k];
            k++;
        }

        andg[and_num].f_and(andinp, 2); // obliczamy wyjscie
        andoutp[and_num] = andg[and_num].gateValue(); // wyjscie pojedynczej bramki and
        and_num ++;
        delete [] andinp;
    }

    norg.f_or(andoutp, 3); // obliczamy finalne wyjscie na podstawie wczesniej obliczonych wyjsc bramek and
    g_outp = norg.gateValue();

    delete [] andoutp;
    delete [] andg;
}

void Gate::f_aoi22(int* inp){

    Gate* andg; // bramki and
    Gate norg; // bramka nor
    int* andoutp = new int[2]; // dane wyjsciowe z bramek and
    
    andg = new Gate [2]; // 2 bramki and

    int and_num = 0; // numer bramki and
    for(int i = 0; i < 4; i+=2){
        int *andinp = new int[2]; // tworzymy tablice 2 wejsc do bramki and

        int k = i;
        for(int j = 0; j < 2; j++){ // nastepuje przypisanie odpowiednich wartosci z tablicy inp do andinp
            andinp[j] = inp[k];
            k++;
        }

        andg[and_num].f_and(andinp, 2); // obliczamy wyjscie
        andoutp[and_num] = andg[and_num].gateValue(); // wyjscie pojedynczej bramki and
        and_num ++;
        delete [] andinp;
    }

    norg.f_nor(andoutp, 2); // obliczamy finalne wyjscie na podstawie wczesniej obliczonych wyjsc bramek and
    g_outp = norg.gateValue();

    delete [] andoutp;
    delete [] andg;
}