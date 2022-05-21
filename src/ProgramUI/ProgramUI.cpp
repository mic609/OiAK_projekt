#include<ProgramUI.hpp>
#include<Gate.hpp>
#include<Pro1.hpp>
#include<Multiplier.hpp>
#include<ExactMultiplier.hpp>

#include<iostream>
#include<cmath>

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
    int tab1[8] = {0, 0, 0, 0, 0, 0, 0, -1};
    int tab2[8] = {0, 0, 0, 0, 0, 0, 0, -1};

    // showResults(tab1, tab2);

    double number_of_errors = 0;
    double ER = 0;

    int i = 0;

    while(true){

        tab1[7] += 1;
        if(tab1[7] == 2){
            tab1[7] = 0;
            tab1[6] += 1;
        }
        if(tab1[6] == 2){
            tab1[6] = 0;
            tab1[5] += 1;
        }
        if(tab1[5] == 2){
            tab1[5] = 0;
            tab1[4] += 1;
        }
        if(tab1[4] == 2){
            tab1[4] = 0;
            tab1[3] += 1;
        }
        if(tab1[3] == 2){
            tab1[3] = 0;
            tab1[2] += 1;
        }
        if(tab1[2] == 2){
            tab1[2] = 0;
            tab1[1] += 1;
        }
        if(tab1[1] == 2){
            tab1[1] = 0;
            tab1[0] += 1;
        }
        if(tab1[0] == 2){
            tab1[0] = 0;
            break;
        }

        while(true){
            tab2[7] += 1;
            if(tab2[7] == 2){
                tab2[7] = 0;
                tab2[6] += 1;
            }
            if(tab2[6] == 2){
                tab2[6] = 0;
                tab2[5] += 1;
            }
            if(tab2[5] == 2){
                tab2[5] = 0;
                tab2[4] += 1;
            }
            if(tab2[4] == 2){
                tab2[4] = 0;
                tab2[3] += 1;
            }
            if(tab2[3] == 2){
                tab2[3] = 0;
                tab2[2] += 1;
            }
            if(tab2[2] == 2){
                tab2[2] = 0;
                tab2[1] += 1;
            }
            if(tab2[1] == 2){
                tab2[1] = 0;
                tab2[0] += 1;
            }
            if(tab2[0] == 2){
                tab2[0] = 0;
                break;
            }

            Multiplier test;
            ExactMultiplier p;

            test.multiply(tab1, tab2);
            p.multiply(tab1, tab2);

            if(test.getDecimalResult() != p.getDecimalResult())
                number_of_errors++;
        }
    }

    ER = number_of_errors / (256*256);

    std::cout << "ER: " << std::ceil(ER * 100.0) / 100.0 << std::endl; // wartosc zaokraglona !
}