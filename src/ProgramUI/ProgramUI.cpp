#include<ProgramUI.hpp>
#include<Gate.hpp>

#include<iostream>

using namespace std;

void ProgramUI::welcomeMessage(){
    Gate test;
    int tab[6] = {0, 0, 0, 0, 0, -1};

        while(true){
            tab[5] += 1;
            if(tab[5] == 2){
                tab[5] = 0;
                tab[4] += 1;
            }
            if(tab[4] == 2){
                tab[4] = 0;
                tab[3] += 1;
            }
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

            for(int i = 0; i < 6; i++)
                cout << tab[i] << " ";

            int result = test.f_ao222(tab);
            cout << "result: " << result;
            cout << endl;
        }
}