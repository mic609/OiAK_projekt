#include<ErrorMetrics.hpp>
#include<Multiplier.hpp>
#include<MultiplierB.hpp>
#include<ExactMultiplier.hpp>

#include<iostream>
#include<cmath>

void ErrorMetrics::show_ER(){
    double number_of_errors_pro1 = 0;
    double number_of_errors_pro2 = 0;
    double ER_pro1 = 0;
    double ER_pro2 = 0;

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
            MultiplierB testb;
            ExactMultiplier p;

            test.multiply(tab1, tab2);
            testb.multiply(tab1, tab2);
            p.multiply(tab1, tab2);

            int x = test.getDecimalResult();
            int y = testb.getDecimalResult();
            int z = p.getDecimalResult();

            if(x != z)
                number_of_errors_pro1++;

            if(y != z)
                number_of_errors_pro2++;
        }
    }

    ER_pro1 = number_of_errors_pro1 / (256*256);
    ER_pro2 = number_of_errors_pro2 / (256*256);

    std::cout << "ER (pro1): " << ER_pro1 << std::endl; // wartosc zaokraglona !
    std::cout << "ER (pro2): " << ER_pro2 << std::endl << std::endl; // wartosc zaokraglona !
}

void ErrorMetrics::show_NMED(){
    double sum_pro1 = 0; // suma roznic wynikow dokladnych i niedokladnych
    double NMED_pro1 = 0;
    double sum_pro2 = 0;
    double NMED_pro2 = 0;

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
            MultiplierB testb;
            ExactMultiplier p;

            test.multiply(tab1, tab2);
            testb.multiply(tab1, tab2);
            p.multiply(tab1, tab2);

            int x = test.getDecimalResult();
            int y = testb.getDecimalResult();
            int z = p.getDecimalResult();

            int difference = z - x;
            if(difference < 0) difference *= (-1);

            sum_pro1 += difference;

            difference = z - y;
            if(difference < 0) difference *= (-1);

            sum_pro2 += difference;
        }
    }

    NMED_pro1 = sum_pro1 / (256*256) / 65025;
    NMED_pro2 = sum_pro2 / (256*256) / 65025;

    std::cout << "NMED (pro1): " << NMED_pro1 << std::endl;
    std::cout << "NMED (pro2): " << NMED_pro2 << std::endl << std::endl;
}

void ErrorMetrics::show_MRED(){
    double sum_pro1 = 0;
    double sum_pro2 = 0;
    double MRED_pro1 = 0;
    double MRED_pro2 = 0;

    int tab1[8] = {0, 0, 0, 0, 0, 0, 0, -1};
    int tab2[8] = {0, 0, 0, 0, 0, 0, 0, -1};

    int i = 0;

    while(true){

        tab1[7] += 1;

        for(int i = 7; i >= 1; i--){
            int j = i - 1;
            if(tab1[i] == 2){
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

            for(int i = 7; i >= 1; i--){
                int j = i - 1;
                if(tab2[i] == 2){
                    tab2[i] = 0;
                    tab2[j] += 1;
                }
            }
            
            if(tab2[0] == 2){
                tab2[0] = 0;
                break;
            }

            Multiplier test;
            MultiplierB testb;
            ExactMultiplier p;

            test.multiply(tab1, tab2);
            testb.multiply(tab1, tab2);
            p.multiply(tab1, tab2);

            int x = test.getDecimalResult();
            int y = testb.getDecimalResult();
            int z = p.getDecimalResult();

            double element = z - x;
            if(element < 0) element *= (-1);

            if(z != 0){
                element /= z;
                sum_pro1 += element;
            }

            element = z - y;
            if(element < 0) element *= (-1);

            if(z != 0){
                element /= z;
                sum_pro2 += element;
            }
        }
    }
    MRED_pro1 = sum_pro1 / (256*256);
    MRED_pro2 = sum_pro2 / (256*256);

    std::cout << "MRED (pro1): " << std::scientific << MRED_pro1 << std::endl << std::fixed;
    std::cout << "MRED (pro2): " << std::scientific << MRED_pro2 << std::endl << std::endl << std::fixed;
}

void ErrorMetrics::show_NoEB(){
    double sum_pro1  = 0;
    double NoEB_pro1 = 0;
    double sum_pro2  = 0;
    double NoEB_pro2 = 0;

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
            MultiplierB testb;
            ExactMultiplier p;

            test.multiply(tab1, tab2);
            testb.multiply(tab1, tab2);
            p.multiply(tab1, tab2);

            int x = test.getDecimalResult();
            int y = testb.getDecimalResult();
            int z = p.getDecimalResult();

            double element = z - x;
            double element_pov = pow(element, 2);
            sum_pro1 += element_pov;

            element = z - y;
            element_pov = pow(element, 2);
            sum_pro2 += element_pov;
        }
    }

    NoEB_pro1 = 2 * 8 - log2(1 + sqrt(sum_pro1 / 65536));
    NoEB_pro2 = 2 * 8 - log2(1 + sqrt(sum_pro2 / 65536));

    std::cout << "NoEB (pro1): " << NoEB_pro1 << std::endl;
    std::cout << "NoEB (pro2): " << NoEB_pro2 << std::endl << std::endl;
}

void ErrorMetrics::show_PRED(){
    double sum_pro1  = 0;
    double PRED_pro1 = 0;
    double sum_pro2  = 0;
    double PRED_pro2 = 0;

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
            MultiplierB testb;
            ExactMultiplier p;

            test.multiply(tab1, tab2);
            testb.multiply(tab1, tab2);
            p.multiply(tab1, tab2);

            int x = test.getDecimalResult();
            int y = testb.getDecimalResult();
            int z = p.getDecimalResult();

            double element = z - x ;
            if(element < 0) element *= (-1);

            if(z != 0){
                element /= z;
                if(element > 0.02)
                    sum_pro1 ++;
            }

            element = z - y ;
            if(element < 0) element *= (-1);

            if(z != 0){
                element /= z;
                if(element > 0.02)
                    sum_pro2 ++;
            }
        }
    }
    PRED_pro1 = sum_pro1 / (256*256);
    PRED_pro2 = sum_pro2 / (256*256);

    std::cout << "PRED (pro1): " << std::scientific << PRED_pro1 << std::endl;
    std::cout << "PRED (pro2): " << std::scientific << PRED_pro2 << std::endl << std::endl;
}