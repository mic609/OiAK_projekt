#include<ProgramUI.hpp>
#include<Gate.hpp>
#include<Pro1.hpp>
#include<Multiplier.hpp>

#include<iostream>

using namespace std;

void ProgramUI::welcomeMessage(){
    Multiplier test;
    int tab1[8] = {1, 0, 0, 1, 0, 1, 1, 1};
    int tab2[8] = {1, 0, 1, 1, 0, 0, 1, 0};

    test.multiply(tab1, tab2);
    test.showMatrixSS();
}