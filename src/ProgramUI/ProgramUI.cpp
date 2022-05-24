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

    int tab1[8], tab2[8];

    std::cout << std::endl;
    ErrorMetrics::show_ER();
    ErrorMetrics::show_NMED();
    ErrorMetrics::show_MRED();
    ErrorMetrics::show_NoEB();
    ErrorMetrics::show_PRED();

    while(true){
        std::cout << "Cyfry nalezy rozdzielac spacja!" << std::endl;
        std::cout << "Wpisz pierwsza liczbe: " << std::endl;
        for(int i = 0; i < 8; i++){
            std::cin >> tab1[i];
        }
        std::cout << "Wpisz druga liczbe: " << std::endl;
        for(int i = 0; i < 8; i++){
            std::cin >> tab2[i];
        }

        showResults(tab1, tab2);
    }
}