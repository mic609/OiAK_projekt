#include<ErrorMetrics.hpp>
#include<Multiplier.hpp>
#include<ExactMultiplier.hpp>

#include<iostream>
#include<cmath>

void ErrorMetrics::show_ER(){
    double number_of_errors = 0;
    double ER = 0;

    int tab1[8] = {0, 0, 0, 0, 0, 0, 0, -1};
    int tab2[8] = {0, 0, 0, 0, 0, 0, 0, -1};

    int i = 0;

    while(true){

        tab1[7] += 1;

        for(int i = 7; i >= 0; i--){
            int j = i - 1;
            if((i == 0)&&(tab1[i] == 2)){
                break;
            }
            else if(tab1[i] == 2){
                tab1[i] = 0;
                tab1[j] += 1;
            }
        }

        if(tab1[0] == 2){
            tab1[0] = 0;
            break;
        }

        while(true){
            tab2[7] += 1;

            for(int i = 7; i >= 0; i--){
                int j = i - 1;
                if((i == 0)&&(tab2[i] == 2)){
                    break;
                }
                else if(tab2[i] == 2){
                    tab2[i] = 0;
                    tab2[j] += 1;
                }
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

    std::cout << "ER: " << std::ceil(ER * 100.0) / 100.0 << std::endl << std::endl; // wartosc zaokraglona !
}

void ErrorMetrics::show_NMED(){
    double sum  = 0; // suma roznic wynikow dokladnych i niedokladnych
    double NMED = 0;

    int tab1[8] = {0, 0, 0, 0, 0, 0, 0, -1};
    int tab2[8] = {0, 0, 0, 0, 0, 0, 0, -1};

    int i = 0;

    while(true){

        tab1[7] += 1;

        for(int i = 7; i >= 0; i--){
            int j = i - 1;
            if((i == 0)&&(tab1[i] == 2)){
                break;
            }
            else if(tab1[i] == 2){
                tab1[i] = 0;
                tab1[j] += 1;
            }
        }

        if(tab1[0] == 2){
            tab1[0] = 0;
            break;
        }

        while(true){
            tab2[7] += 1;

            for(int i = 7; i >= 0; i--){
                int j = i - 1;
                if((i == 0)&&(tab2[i] == 2)){
                    break;
                }
                else if(tab2[i] == 2){
                    tab2[i] = 0;
                    tab2[j] += 1;
                }
            }
            
            if(tab2[0] == 2){
                tab2[0] = 0;
                break;
            }

            Multiplier test;
            ExactMultiplier p;

            test.multiply(tab1, tab2);
            p.multiply(tab1, tab2);

            int difference = p.getDecimalResult() - test.getDecimalResult();
            if(difference < 0) difference *= (-1);

            sum += difference;
        }
    }

    NMED = sum / (256*256) / 65025;

    std::cout << "NMED: " << NMED << std::endl << std::endl;
}

void ErrorMetrics::show_MRED(){
    double sum  = 0;
    double MRED = 0;

    int tab1[8] = {0, 0, 0, 0, 0, 0, 0, -1};
    int tab2[8] = {0, 0, 0, 0, 0, 0, 0, -1};

    int i = 0;

    while(true){

        tab1[7] += 1;

        for(int i = 7; i >= 0; i--){
            int j = i - 1;
            if((i == 0)&&(tab1[i] == 2)){
                break;
            }
            else if(tab1[i] == 2){
                tab1[i] = 0;
                tab1[j] += 1;
            }
        }

        if(tab1[0] == 2){
            tab1[0] = 0;
            break;
        }

        while(true){
            tab2[7] += 1;

            for(int i = 7; i >= 0; i--){
                int j = i - 1;
                if((i == 0)&&(tab2[i] == 2)){
                    break;
                }
                else if(tab2[i] == 2){
                    tab2[i] = 0;
                    tab2[j] += 1;
                }
            }
            
            if(tab2[0] == 2){
                tab2[0] = 0;
                break;
            }

            Multiplier test;
            ExactMultiplier p;

            test.multiply(tab1, tab2);
            p.multiply(tab1, tab2);

            double element = (p.getDecimalResult() - test.getDecimalResult()) ;
            if(element < 0) element *= (-1);

            if(p.getDecimalResult() != 0){
                element /= p.getDecimalResult();
                sum += element;
            }
            else{
                element = 520;
                element /= 65025;
                sum += element;
            }
        }
    }

    MRED = sum / 65536;

    std::cout << "MRED: " << std::scientific << MRED << std::endl << std::endl << std::fixed;
}

void ErrorMetrics::show_NoEB(){
    double sum  = 0;
    double NoEB = 0;

    int tab1[8] = {0, 0, 0, 0, 0, 0, 0, -1};
    int tab2[8] = {0, 0, 0, 0, 0, 0, 0, -1};

    int i = 0;
    int divide = 0;

    while(true){

        tab1[7] += 1;

        for(int i = 7; i >= 0; i--){
            int j = i - 1;
            if((i == 0)&&(tab1[i] == 2)){
                break;
            }
            else if(tab1[i] == 2){
                tab1[i] = 0;
                tab1[j] += 1;
            }
        }

        if(tab1[0] == 2){
            tab1[0] = 0;
            break;
        }

        while(true){
            tab2[7] += 1;

            for(int i = 7; i >= 0; i--){
                int j = i - 1;
                if((i == 0)&&(tab2[i] == 2)){
                    break;
                }
                else if(tab2[i] == 2){
                    tab2[i] = 0;
                    tab2[j] += 1;
                }
            }
            
            if(tab2[0] == 2){
                tab2[0] = 0;
                break;
            }

            Multiplier test;
            ExactMultiplier p;

            test.multiply(tab1, tab2);
            p.multiply(tab1, tab2);

            double element = (p.getDecimalResult() - test.getDecimalResult()) ;
            double element_pov = pow(element, 2);
            sum += element_pov;
        }
    }

    NoEB = 2 * 8 - log2(1 + sqrt(sum / 65536));

    std::cout << "NoEB: " << NoEB << std::endl << std::endl;
}

void ErrorMetrics::show_PRED(){
    double sum  = 0;
    double PRED = 0;

    int tab1[8] = {0, 0, 0, 0, 0, 0, 0, -1};
    int tab2[8] = {0, 0, 0, 0, 0, 0, 0, -1};

    int i = 0;

    while(true){

        tab1[7] += 1;

        for(int i = 7; i >= 0; i--){
            int j = i - 1;
            if((i == 0)&&(tab1[i] == 2)){
                break;
            }
            else if(tab1[i] == 2){
                tab1[i] = 0;
                tab1[j] += 1;
            }
        }

        if(tab1[0] == 2){
            tab1[0] = 0;
            break;
        }

        while(true){
            tab2[7] += 1;

            for(int i = 7; i >= 0; i--){
                int j = i - 1;
                if((i == 0)&&(tab2[i] == 2)){
                    break;
                }
                else if(tab2[i] == 2){
                    tab2[i] = 0;
                    tab2[j] += 1;
                }
            }
            
            if(tab2[0] == 2){
                tab2[0] = 0;
                break;
            }

            Multiplier test;
            ExactMultiplier p;

            test.multiply(tab1, tab2);
            p.multiply(tab1, tab2);

            double element = (p.getDecimalResult() - test.getDecimalResult()) ;
            if(element < 0) element *= (-1);

            if(p.getDecimalResult() != 0){
                element /= p.getDecimalResult();
                if(element > 0.02)
                    sum ++;
            }
            else{
                sum ++;
            }
        }
    }
    PRED = sum / 65536;

    std::cout << "PRED: " << std::scientific << PRED << std::endl << std::endl;
}