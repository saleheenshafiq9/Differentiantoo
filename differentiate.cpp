#include "header.h"

using namespace std;
char derivative[100];

void differentiate(int coeff, char variable, int power, char sign) {

    int new_coeff = coeff*power;
    int new_power = power-1;

    if(new_coeff!=1)
        cout<<new_coeff;
    if(new_power!=0)
        cout<<"*"<<variable;
    if(new_power!=1 && new_power!=0)
        cout<<"^"<<new_power;
    if(sign=='+' || sign=='-')
        cout<<sign;
}
