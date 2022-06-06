#include<MultiplierB.hpp>
#include<Adder.hpp>
#include<Pro2.hpp>
#include<Exact.hpp>

#include<iostream>

MultiplierB::MultiplierB(){
    result = new int[16];
    intResult = 0;
}

void MultiplierB::showMatrixFS(){

    int move = 0;

    for(int i = 0; i < 8; i++){

        for(int j = 14; j >= (8 + move); j--)
            std::cout << "  ";

        for(int j = (7 + move); j >= move; j--){
                std::cout << matrixFS[i][j] << " ";
        }

        for(int j = move - 1; j >= 0; j--)
            std::cout << "  ";

        std::cout << std::endl;
            
        move++;
    }
}

void MultiplierB::showMatrixSS(){
    for(int i = 0; i < 4; i++){
        if(i == 0){
            for(int j = 14; j >= 0; j--)
                std::cout << matrixSS[i][j] << " ";
            std::cout << std::endl;
        }
        else if(i == 1){
            for(int j = 14; j >= 14; j--)
                std::cout << "  ";
            for(int j = 13; j >= 1; j--)
                std::cout << matrixSS[i][j] << " ";
            for(int j = 0; j >= 0; j--)
                std::cout << "  ";
            std::cout << std::endl;
        }
        else if(i == 2){
            for(int j = 14; j >= 13; j--)
                std::cout << "  ";
            for(int j = 12; j >= 2; j--)
                std::cout << matrixSS[i][j] << " ";
            for(int j = 1; j >= 0; j--)
                std::cout << "  ";
            std::cout << std::endl;
        }
        else if(i == 3){
            for(int j = 14; j >= 13; j--)
                std::cout << "  ";
            for(int j = 12; j >= 3; j--)
                std::cout << matrixSS[i][j] << " ";
            for(int j = 2; j >= 0; j--)
                std::cout << "  ";
            std::cout << std::endl;
        }
    }
}

void MultiplierB::showMatrixFinal(){
    for(int i = 0; i < 4; i++){
        if(i == 0){
            for(int j = 14; j >= 0; j--)
                std::cout << matrixFinal[i][j] << " ";
            std::cout << std::endl;
        }
        if(i == 1){
            for(int j = 14; j >= 1; j--)
                std::cout << matrixFinal[i][j] << " ";
            std::cout << std::endl;
        }
    }
}

void MultiplierB::getMultiplyResult(){
    for(int j = 15; j >= 0; j--)
        std::cout << result[j] << " ";
}

int MultiplierB::getDecimalResult(){

    int multiplyNumber = 1;

    for(int j = 0; j <=15; j++){
        intResult += (result[j] * multiplyNumber);
        multiplyNumber *= 2;
    }

    return intResult;
}

void MultiplierB::multiply(int* firstNumber, int* secondNumber){

    fillMatrixFS(firstNumber, secondNumber); // wypelnianie macierzy w pierwszym kroku
    firstStage(firstNumber, secondNumber); // pierwszy etap mnozenia
    secondStage(firstNumber, secondNumber); // drugi etap mnozenia
    finalStage(); // zsumowanie pozostalych bitow
}

void MultiplierB::firstStage(int* firstNumber, int* secondNumber){

    Adder halfadder[3], fulladder[2];
    Pro2 pro[4];
    Exact exact[3];

    // Uwaga! Przypisanie, ktore nastepuje przed procesem wykonania obliczen na danej kolumnie, to przeniesienie
    // z poprzedniej kolumny!
    
    //kolumna 0
    matrixSS[0][0] = matrixFS[0][0]; //przypisanie
    
    //kolumna 1
    matrixSS[0][1] = matrixFS[0][1]; //przypisanie
    matrixSS[1][1] = matrixFS[1][1]; //przypisanie

    //kolumna 2
    matrixSS[0][2] = matrixFS[0][2]; //przypisanie
    matrixSS[1][2] = matrixFS[1][2]; //przypisanie
    matrixSS[2][2] = matrixFS[2][2]; //przypisanie

    //kolumna 3
    matrixSS[0][3] = matrixFS[0][3]; //przypisanie
    matrixSS[1][3] = matrixFS[1][3]; //przypisanie
    matrixSS[2][3] = matrixFS[2][3]; //przypisanie
    matrixSS[3][3] = matrixFS[3][3]; //przypisanie
    
    int* tab;

    //kolumna 4 - half adder
    tab = new int[2];
    tab[0] = matrixFS[0][4];
    tab[1] = matrixFS[1][4];
    halfadder[0].half_circuit(tab);
    matrixSS[0][4] = halfadder[0].getS(); //przypisanie
    matrixSS[1][4] = matrixFS[2][4]; //przypisanie
    matrixSS[2][4] = matrixFS[3][4]; //przypisanie
    matrixSS[3][4] = matrixFS[4][4]; //przypisanie

    //kolumna 5 - pro2
    matrixSS[0][5] = halfadder[0].getC_out(); //przypisanie
    tab = new int[4];
    tab[0] = matrixFS[0][5];
    tab[1] = matrixFS[1][5];
    tab[2] = matrixFS[2][5];
    tab[3] = matrixFS[3][5];
    pro[0].circuit(tab);
    matrixSS[1][5] = pro[0].getS(); //przypisanie
    matrixSS[2][5] = matrixFS[4][5]; //przypisanie
    matrixSS[3][5] = matrixFS[5][5]; //przypisanie
    
    //kolumna 6 - pro2, half adder
    matrixSS[0][6] = pro[0].getC(); //przypisanie
    tab = new int[4];
    tab[0] = matrixFS[0][6];
    tab[1] = matrixFS[1][6];
    tab[2] = matrixFS[2][6];
    tab[3] = matrixFS[3][6];
    pro[1].circuit(tab);
    tab = new int[2];
    tab[0] = matrixFS[4][6];
    tab[1] = matrixFS[5][6];
    halfadder[1].half_circuit(tab);
    matrixSS[1][6] = pro[1].getS(); //przypisanie
    matrixSS[2][6] = halfadder[1].getS(); //przypisanie
    matrixSS[3][6] = matrixFS[6][6]; //przypisanie

    //kolumna 7 - 2 x pro2
    matrixSS[0][7] = pro[1].getC(); //przypisanie
    matrixSS[1][7] = halfadder[1].getC_out(); //przypisanie
    tab = new int[4];
    tab[0] = matrixFS[0][7];
    tab[1] = matrixFS[1][7];
    tab[2] = matrixFS[2][7];
    tab[3] = matrixFS[3][7];
    pro[2].circuit(tab);
    tab = new int[4];
    tab[0] = matrixFS[4][7];
    tab[1] = matrixFS[5][7];
    tab[2] = matrixFS[6][7];
    tab[3] = matrixFS[7][7];
    pro[3].circuit(tab);
    matrixSS[2][7] = pro[2].getS(); //przypisanie
    matrixSS[3][7] = pro[3].getS(); //przypisanie

    //kolumna 8 - exact, full adder
    matrixSS[0][8] = pro[2].getC(); //przypisanie
    matrixSS[1][8] = pro[3].getC(); //przypisanie
    tab = new int[4];
    tab[0] = matrixFS[1][8];
    tab[1] = matrixFS[2][8];
    tab[2] = matrixFS[3][8];
    tab[3] = matrixFS[4][8];
    exact[0].circuit(tab, 0);
    tab = new int[3];
    tab[0] = matrixFS[5][8];
    tab[1] = matrixFS[6][8];
    tab[2] = matrixFS[7][8];
    fulladder[0].full_circuit(tab);
    matrixSS[2][8] = exact[0].getS(); //przypisanie
    matrixSS[3][8] = fulladder[0].getS(); //przypisanie

    //kolumna 9 - exact, half adder
    matrixSS[0][9] = exact[0].getcarry(); //przypisanie
    matrixSS[1][9] = fulladder[0].getC_out(); //przypisanie
    tab = new int[4];
    tab[0] = matrixFS[2][9];
    tab[1] = matrixFS[3][9];
    tab[2] = matrixFS[4][9];
    tab[3] = matrixFS[5][9];
    exact[1].circuit(tab, exact[0].getC_out());
    tab = new int[2];
    tab[0] = matrixFS[6][9];
    tab[1] = matrixFS[7][9];
    halfadder[2].half_circuit(tab);
    matrixSS[2][9] = exact[1].getS(); //przypisanie
    matrixSS[3][9] = halfadder[2].getS(); //przypisanie

    //kolumna 10 - exact
    matrixSS[0][10] = exact[1].getcarry(); //przypisanie
    matrixSS[1][10] = halfadder[2].getC_out(); //przypisanie
    tab = new int[4];
    tab[0] = matrixFS[3][10];
    tab[1] = matrixFS[4][10];
    tab[2] = matrixFS[5][10];
    tab[3] = matrixFS[6][10];
    exact[2].circuit(tab, exact[1].getC_out());
    matrixSS[2][10] = exact[2].getS(); //przypisanie
    matrixSS[3][10] = matrixFS[7][10]; //przypisanie

    //kolumna 11 - full adder
    matrixSS[0][11] = exact[2].getcarry(); //przypisanie
    tab = new int [3];
    tab[0] = matrixFS[4][11];
    tab[1] = matrixFS[5][11];
    tab[2] = exact[2].getC_out();
    fulladder[1].full_circuit(tab);
    matrixSS[1][11] = fulladder[1].getS(); //przypisanie
    matrixSS[2][11] = matrixFS[6][11]; //przypisanie
    matrixSS[3][11] = matrixFS[7][11]; //przypisanie

    //kolumna 12
    matrixSS[0][12] = fulladder[1].getC_out(); //przypisanie
    matrixSS[1][12] = matrixFS[5][12]; //przypisanie
    matrixSS[2][12] = matrixFS[6][12]; //przypisanie
    matrixSS[3][12] = matrixFS[7][12]; //przypisanie

    //kolumna 13
    matrixSS[0][13] = matrixFS[6][13]; //przypisanie
    matrixSS[1][13] = matrixFS[7][13]; //przypisanie

    //kolumna 14
    matrixSS[0][14] = matrixFS[7][14]; //przypisanie
}

void MultiplierB::secondStage(int* firstNumber, int* secondNumber){

    Adder halfadder, fulladder;
    Pro2 pro[5];
    Exact exact[5];

    // Uwaga! Przypisanie, ktore nastepuje przed procesem wykonania obliczen na danej kolumnie, to przeniesienie
    // z poprzedniej kolumny!

    //kolumna 0
    matrixFinal[0][0] = matrixSS[0][0]; //przypisanie

    //kolumna 1
    matrixFinal[0][1] = matrixSS[0][1]; //przypisanie
    matrixFinal[1][1] = matrixSS[1][1]; //przypisanie

    int* tab;

    //kolumna 2 - half adder
    tab = new int[2];
    tab[0] = matrixSS[0][2];
    tab[1] = matrixSS[1][2];
    halfadder.half_circuit(tab);
    matrixFinal[0][2] = halfadder.getS(); //przypisanie
    matrixFinal[1][2] = matrixSS[2][2]; //przypisanie

    //kolumna 3 - pro2
    matrixFinal[0][3] = halfadder.getC_out(); //przypisanie
    tab = new int[4];
    for(int i = 0; i < 4; i++)
        tab[i] = matrixSS[i][3];
    pro[0].circuit(tab);
    matrixFinal[1][3] = pro[0].getS(); //przypisanie

    //kolumna 4 - pro2
    matrixFinal[0][4] = pro[0].getC(); //przypisanie
    tab = new int[4];
    for(int i = 0; i < 4; i++)
        tab[i] = matrixSS[i][4];
    pro[1].circuit(tab);
    matrixFinal[1][4] = pro[1].getS(); //przypisanie

    //kolumna 5 - pro2
    matrixFinal[0][5] = pro[1].getC(); //przypisanie
    tab = new int[4];
    for(int i = 0; i < 4; i++)
        tab[i] = matrixSS[i][5];
    pro[2].circuit(tab);
    matrixFinal[1][5] = pro[2].getS(); //przypisanie

    //kolumna 6 - pro2
    matrixFinal[0][6] = pro[2].getC(); //przypisanie
    tab = new int[4];
    for(int i = 0; i < 4; i++)
        tab[i] = matrixSS[i][6];
    pro[3].circuit(tab);
    matrixFinal[1][6] = pro[3].getS(); //przypisanie

    //kolumna 7 - pro2
    matrixFinal[0][7] = pro[3].getC(); //przypisanie
    tab = new int[4];
    for(int i = 0; i < 4; i++)
        tab[i] = matrixSS[i][7];
    pro[4].circuit(tab);
    matrixFinal[1][7] = pro[4].getS(); //przypisanie

    //kolumna 8 - exact
    matrixFinal[0][8] = pro[4].getC(); //przypisanie
    tab = new int[4];
    for(int i = 0; i < 4; i++)
        tab[i] = matrixSS[i][8];
    exact[0].circuit(tab, 0);
    matrixFinal[1][8] = exact[0].getS(); //przypisanie

    //kolumna 9 - exact
    matrixFinal[0][9] = exact[0].getcarry(); //przypisanie
    tab = new int[4];
    for(int i = 0; i < 4; i++)
        tab[i] = matrixSS[i][9];
    exact[1].circuit(tab, exact[0].getC_out());
    matrixFinal[1][9] = exact[1].getS(); //przypisanie

    //kolumna 10 - exact
    matrixFinal[0][10] = exact[1].getcarry(); //przypisanie
    tab = new int[4];
    for(int i = 0; i < 4; i++)
        tab[i] = matrixSS[i][10];
    exact[2].circuit(tab, exact[1].getC_out());
    matrixFinal[1][10] = exact[2].getS(); //przypisanie

    //kolumna 11 - exact
    matrixFinal[0][11] = exact[2].getcarry(); //przypisanie
    tab = new int[4];
    for(int i = 0; i < 4; i++)
        tab[i] = matrixSS[i][11];
    exact[3].circuit(tab, exact[2].getC_out());
    matrixFinal[1][11] = exact[3].getS(); //przypisanie

    //kolumna 12 - exact
    matrixFinal[0][12] = exact[3].getcarry(); //przypisanie
    tab = new int[4];
    for(int i = 0; i < 4; i++)
        tab[i] = matrixSS[i][12];
    exact[4].circuit(tab, exact[3].getC_out());
    matrixFinal[1][12] = exact[4].getS(); //przypisanie

    //kolumna 13 - full adder
    matrixFinal[0][13] = exact[4].getcarry(); //przypisanie
    tab = new int[3];
    for(int i = 0; i < 2; i++)
        tab[i] = matrixSS[i][13];
    tab[2] = exact[4].getC_out();
    fulladder.full_circuit(tab);
    matrixFinal[1][13] = fulladder.getS(); //przypisanie

    //kolumna 14
    matrixFinal[0][14] = fulladder.getC_out(); //przypisanie
    matrixFinal[1][14] = matrixSS[0][14]; //przypisanie
}

void MultiplierB::finalStage(){
    int carry = 0;

    for(int i = 0; i <= 15; i++){
        result[i] = 0;

        if(i == 0){
            result[i] += matrixFinal[0][i];
        }
        else if(i < 15){
            for(int j = 0; j < 2; j++)
                result[i] += matrixFinal[j][i];
        }

        result[i] += carry;

        if(result[i] == 2){
            result[i] = 0;
            carry = 1;
        }
        else if(result[i] == 3){
            result[i] = 1;
            carry = 1;
        }
        else
            carry = 0;
    }
}

void MultiplierB::fillMatrixFS(int* firstNumber, int* secondNumber){

    int move = 0;
    int k = 7;

    for(int i = 0; i < 8; i++){

        for(int j = 14; j >= (8 + move); j--)
            matrixFS[i][j] = 0;

        int t = 0;

        for(int j = (7 + move); j >= move; j--){
            if(secondNumber[k] != 0){
                matrixFS[i][j] = firstNumber[t];
                t++;
            }
            else
                matrixFS[i][j] = 0;
        }
        for(int j = move - 1; j >= 0; j--)
            matrixFS[i][j] = 0;
            
        move++;
        k--;
    }
}