#include<ProgramUI.hpp>
#include<Gate.hpp>
#include<Pro1.hpp>
#include<Multiplier.hpp>

#include<iostream>

using namespace std;

void ProgramUI::welcomeMessage(){
    Multiplier test;
    int tab1[8] = {1, 1, 1, 1, 1, 1, 1, 1};
    int tab2[8] = {1, 1, 1, 1, 1, 1, 1, 1};

    test.multiply(tab1, tab2);
    test.showMatrixSS();
    for(int i = 0; i < 15; i++) std::cout << "- ";
    std::cout << std::endl;
    test.showMatrixFinal();
}