#include<ProgramUI.hpp>
#include<Gate.hpp>
#include<Pro1.hpp>

#include<iostream>

using namespace std;

void ProgramUI::welcomeMessage(){
    Pro1 test;
    int tab[4] = {0, 0, 0, -1};

        while(true){
            tab[3] += 1;
            if(tab[3] == 2){
                tab[3] = 0;
                tab[2] += 1;
            }
            if(tab[2] == 2){
                tab[2] = 0;
                tab[1] += 1;
            }
            if(tab[1] == 2){
                tab[1] = 0;
                tab[0] += 1;
            }
            if(tab[0] == 2){
                break;
            }

            for(int i = 0; i < 4; i++)
                cout << tab[i] << " ";

            test.circuit(tab);
            cout <<"      S: " << test.getS() << "   ";
            cout <<"C: " << test.getC() << endl;
        }
}