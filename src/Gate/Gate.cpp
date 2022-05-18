#include <Gate.hpp>

#include <iostream>

int Gate::f_not(int inp){

    int outp = inp;

    if(outp == 0) outp = 1;
    if(outp == 1) outp = 0;

    return outp;
}

int Gate::f_and(int* inp, int n){

    for(int i = 0; i < n; i++)
        if(inp[i] < 0 || inp[i] > 1)
            std::cout << "Wrong number of an input. It should be 0 or 1";

    int outp;
    for(int i = 0; i < n; i++){
        if(!inp[i]){
            outp = 0;
            break;
        }
        else outp = 1;
    } 

    return outp;
}

int Gate::f_or(int* inp, int n){

    for(int i = 0; i < n; i++)
        if(inp[i] < 0 || inp[i] > 1)
            std::cout << "Wrong number of an input. It should be 0 or 1";

    int outp;
    for(int i = 0; i < n; i++){
        if(inp[i]){
            outp = 1;
            break;
        }
        else outp = 0;
    }

    return outp;
}

int Gate::f_nand(int* inp, int n){
    for(int i = 0; i < n; i++)
        if(inp[i] < 0 || inp[i] > 1)
            std::cout << "Wrong number of an input. It should be 0 or 1";

    int outp;
    for(int i = 0; i < n; i++){
        if(inp[i]){
            outp = 1;
            break;
        }
        else outp = 0;
    }

    if(outp) outp = 0;
    else outp = 1;

    return outp;
}

int Gate::f_nor(int* inp, int n){
    for(int i = 0; i < n; i++)
        if(inp[i] < 0 || inp[i] > 1)
            std::cout << "Wrong number of an input. It should be 0 or 1";

    int outp;
    for(int i = 0; i < n; i++){
        if(inp[i]){
            outp = 1;
            break;
        }
        else outp = 0;
    }

    if(outp) outp = 0;
    else outp = 1;

    return outp;
}

int Gate::f_ao222(int* inp){
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

        andoutp[and_num] = andg[and_num].f_and(andinp, 2); // wyjscie pojedynczej bramki and
        and_num ++;
        delete [] andinp;
    }

    int output = norg.f_or(andoutp, 3); // obliczamy finalne wyjscie na podstawie wczesniej obliczonych wyjsc bramek and

    delete [] andoutp;
    delete [] andg;

    return output;
}

int Gate::f_aoi22(int* inp){

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

        andoutp[and_num] = andg[and_num].f_and(andinp, 2); // wyjscie pojedynczej bramki and
        and_num ++;
        delete [] andinp;
    }

    int output = norg.f_nor(andoutp, 2); // obliczamy finalne wyjscie na podstawie wczesniej obliczonych wyjsc bramek and

    delete [] andoutp;
    delete [] andg;

    return output;
}