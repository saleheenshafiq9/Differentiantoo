#include "header.h"

using namespace std;
char derivative[100];
char universal_sign = '\0';

void differentiate(int coeff, char variable, int power, char sign) {


    if(sign=='f') {
        universal_sign = '\0';
//        cout<<"check";
    }
    if(coeff==1001)
        return;

    int new_coeff = coeff*power;
    int new_power = power-1;

    if(universal_sign=='+' || universal_sign=='-') {
        if(new_coeff>0)
            cout<<" "<<universal_sign<<" ";
        else if(new_coeff<0) {
            if(universal_sign=='+')
                cout<<" "<<"-"<<" ";
            else
                cout<<" "<<"+"<<" ";
        }
        if(new_coeff!=1)
            cout<<abs(new_coeff);
        if(new_coeff==1 && new_power==0)
            cout<<new_coeff;
    }

    else {
        if(new_coeff!=1)
            cout<<new_coeff;
        if(new_coeff==1 && new_power==0)
            cout<<new_coeff;
    }

    if(new_power!=0)
        cout<<"*"<<variable;
    if(new_power!=1 && new_power!=0)
        cout<<"^"<<new_power;
    universal_sign = sign;


}

