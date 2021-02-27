#include "header.h"

using namespace std;

void calculate(int constant,int degree,char sign) {
    if(degree==1)
            cout<<" "<<sign<<" "<<constant<<"*x";
        else if(degree==0)
            cout<<" "<<sign<<" "<<constant;
        else
            cout<<" "<<sign<<" "<<constant<<"*x^"<<degree;
}

