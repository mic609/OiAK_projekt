#include<ProgramUI.hpp>
#include<Gate.hpp>
#include<Pro1.hpp>
#include<Multiplier.hpp>
#include<ExactMultiplier.hpp>
#include<ErrorMetrics.hpp>

#include<iostream>

void ProgramUI::showResults(int* tab1, int*tab2){

    Multiplier test;
    ExactMultiplier p;

    test.multiply(tab1, tab2);

    std::cout << std::endl;
    test.showMatrixFS();
    for(int i = 0; i < 15; i++) std::cout << "- ";
    std::cout << std::endl;

    test.showMatrixSS();
    for(int i = 0; i < 15; i++) std::cout << "- ";
    std::cout << std::endl;

    test.showMatrixFinal();
    std::cout << std::endl << std::endl;

    std::cout << "APPROXIMATE MULTIPLIER";
    std::cout << std::endl;
    std::cout << "BINARY RESULT: ";
    test.getMultiplyResult();
    std::cout << std::endl;
    std::cout << "DECIMAL RESULT: ";
    std::cout << test.getDecimalResult();

    std::cout << std::endl << std::endl;

    p.multiply(tab1, tab2);

    p.showMatrixFS();
    for(int i = 0; i < 15; i++) std::cout << "- ";
    std::cout << std::endl;

    p.showMatrixSS();
    for(int i = 0; i < 15; i++) std::cout << "- ";
    std::cout << std::endl;

    p.showMatrixFinal();
    std::cout << std::endl << std::endl;

    std::cout << "EXACT MULTIPLIER";
    std::cout << std::endl;
    std::cout << "BINARY RESULT: ";
    p.getMultiplyResult();
    std::cout << std::endl;

    std::cout << "DECIMAL RESULT: ";
    std::cout << p.getDecimalResult();
    std::cout << std::endl << std::endl;
}

void ProgramUI::welcomeMessage(){
    int tab1[8] = {1, 1, 1, 1, 1, 1, 1, 1};
    int tab2[8] = {1, 1, 1, 1, 1, 1, 1, 1};

    showResults(tab1, tab2);

    ErrorMetrics::show_ER();
    ErrorMetrics::show_NMED();
    ErrorMetrics::show_MRED();
    ErrorMetrics::show_NoEB();
    ErrorMetrics::show_PRED();
}