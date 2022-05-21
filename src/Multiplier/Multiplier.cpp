#include<Multiplier.hpp>
#include<Adder.hpp>
#include<Pro1.hpp>
#include<Exact.hpp>

#include<iostream>

Multiplier::Multiplier(){
        // result = new int [15];

        // matrixFS = new int *[8]; // wierszy
        // matrixSS = new int *[4];

        // for(int i = 0; i < 8; i++)
        //     matrixFS[i] = new int[15]; // ilosc kolumn

        // for(int i = 0; i < 4; i++)
        //     matrixSS[i] = new int[15];
}

int* Multiplier::getResult(){
    return result;
}

void Multiplier::showMatrixSS(){
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

void Multiplier::multiply(int* firstNumber, int* secondNumber){

    fillMatrixFS(firstNumber, secondNumber); // wypelnianie macierzy w pierwszym kroku

    Adder halfadder[3], fulladder[2];
    Pro1 pro[4];
    Exact exact[3];

    matrixSS[0][0] = matrixFS[0][0];
    
    matrixSS[0][1] = matrixFS[0][1];
    matrixSS[1][1] = matrixFS[1][1];

    matrixSS[0][2] = matrixFS[0][2];
    matrixSS[1][2] = matrixFS[1][2];
    matrixSS[2][2] = matrixFS[2][2];

    matrixSS[0][3] = matrixFS[0][3];
    matrixSS[1][3] = matrixFS[1][3];
    matrixSS[2][3] = matrixFS[2][3];
    matrixSS[3][3] = matrixFS[3][3];
    
    int* tab;

    tab = new int[2];
    tab[0] = matrixFS[0][4];
    tab[1] = matrixFS[1][4];
    halfadder[0].half_circuit(tab);
    matrixSS[0][4] = halfadder[0].getS();
    matrixSS[1][4] = matrixFS[2][4];
    matrixSS[2][4] = matrixFS[3][4];
    matrixSS[3][4] = matrixFS[4][4];

    tab = new int[4];
    tab[0] = matrixFS[0][5];
    tab[1] = matrixFS[1][5];
    tab[2] = matrixFS[2][5];
    tab[3] = matrixFS[3][5];
    pro[0].circuit(tab);
    matrixSS[0][5] = halfadder[0].getC_out();
    matrixSS[1][5] = pro[0].getS();
    matrixSS[2][5] = matrixFS[4][5];
    matrixSS[3][5] = matrixFS[5][5];
    
    matrixSS[0][6] = pro[0].getC();
    tab = new int[4];
    tab[0] = matrixFS[0][6];
    tab[1] = matrixFS[1][6];
    tab[2] = matrixFS[2][6];
    tab[3] = matrixFS[3][6];
    pro[1].circuit(tab);
    matrixSS[1][6] = pro[1].getS();
    tab = new int[2];
    tab[0] = matrixFS[4][6];
    tab[1] = matrixFS[5][6];
    halfadder[1].half_circuit(tab);
    matrixSS[2][6] = halfadder[1].getS();
    matrixSS[3][6] = matrixFS[6][6];

    matrixSS[0][7] = pro[1].getC();
    matrixSS[1][7] = halfadder[1].getC_out();
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
    matrixSS[2][7] = pro[2].getS();
    matrixSS[3][7] = pro[3].getS();

    matrixSS[0][8] = pro[2].getC();
    matrixSS[1][8] = pro[3].getC();
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
    matrixSS[2][8] = exact[0].getS();
    matrixSS[3][8] = fulladder[0].getS();

    matrixSS[0][9] = exact[0].getcarry();
    matrixSS[1][9] = fulladder[0].getC_out();
    tab = new int[4];
    int c;
    tab[0] = matrixFS[2][9];
    tab[1] = matrixFS[3][9];
    tab[2] = matrixFS[4][9];
    tab[3] = matrixFS[5][9];
    c = exact[0].getC_out();
    exact[1].circuit(tab, c);
    tab = new int[2];
    tab[0] = matrixFS[6][9];
    tab[1] = matrixFS[7][9];
    halfadder[2].half_circuit(tab);
    matrixSS[2][9] = exact[1].getS();
    matrixSS[3][9] = halfadder[2].getS();

    matrixSS[0][10] = exact[1].getcarry();
    matrixSS[1][10] = halfadder[2].getC_out();
    tab = new int[4];
    tab[0] = matrixFS[3][10];
    tab[1] = matrixFS[4][10];
    tab[2] = matrixFS[5][10];
    tab[3] = matrixFS[6][10];
    c = exact[1].getC_out();
    exact[2].circuit(tab, c);
    tab = new int[4];
    matrixSS[2][10] = exact[2].getS();
    matrixSS[3][10] = matrixFS[7][10];

    matrixSS[0][11] = exact[2].getcarry();
    tab = new int [2];
    tab[0] = matrixFS[4][11];
    tab[1] = matrixFS[5][11];
    tab[2] = exact[2].getC_out();
    fulladder[1].full_circuit(tab);
    matrixSS[1][11] = fulladder[1].getS();
    matrixSS[2][11] = matrixFS[6][11];
    matrixSS[3][11] = matrixFS[7][11];

    matrixSS[0][12] = fulladder[1].getC_out();
    matrixSS[1][12] = matrixFS[5][12];
    matrixSS[2][12] = matrixFS[6][12];
    matrixSS[3][12] = matrixFS[7][12];

    matrixSS[0][13] = matrixFS[6][13];
    matrixSS[1][13] = matrixFS[7][13];

    matrixSS[0][14] = matrixFS[7][14];

}

void Multiplier::fillMatrixFS(int* firstNumber, int* secondNumber){

    int move = 0;
    int k = 7;

    for(int i = 0; i < 8; i++){
        for(int j = 14; j >= (8 + move); j--){
            matrixFS[i][j] = 0;
        }
        int t = 0;
        for(int j = (7 + move); j >= move; j--){
            if(secondNumber[k] != 0){
                matrixFS[i][j] = firstNumber[t];
                t++;
            }
            else
                matrixFS[i][j] = 0;
        }
        for(int j = move - 1; j >= 0; j--){
            matrixFS[i][j] = 0;
        }
        move++;
        k--;
    }
}