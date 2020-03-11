#include "header.h"

using namespace std;

void differentiate(char parts[100],char sign) {

    int j=1,xcount=0;
    int coeff=0,keeper,deg=0,reduced_deg,new_coeff;

    for(int i=0; i<strlen(parts); i++) {
        if(parts[0]=='x') {
            coeff=1;
            xcount++;
            //cout<<"coeff:"<<coeff<<"\t";
        }
        if(parts[strlen(parts)-1]=='x') {
            deg=1;
            xcount++;
            //cout<<"deg:"<<deg<<"\t";
        }
        if(parts[i]!='*' && parts[i]!='^' && parts[i]!='x') {
            if(parts[i+1]=='*') {
                keeper=parts[i]-48;
                coeff=coeff+keeper;
                //cout<<"coeff:"<<coeff<<"\t";

            }
            else if(parts[i+2]=='*') {
                keeper=parts[i]-48;
                coeff=coeff+keeper*10;
                keeper=parts[i+1]-48;
                coeff=coeff+keeper;
                i++;
                //cout<<"coeff:"<<coeff<<"\t";
            }
            else if(parts[i-1]=='^' && parts[i+1]=='\0') {
                keeper=parts[i]-48;
                deg=deg+keeper;
                //cout<<"deg:"<<deg<<"\t";
            }
            else if(parts[i-2]=='^') {
                keeper=parts[i-1]-48;
                deg=deg+keeper*10;
                keeper=parts[i]-48;
                deg=deg+keeper;
                //cout<<"deg:"<<deg<<"\t";
            }
            else {
                    coeff=0;
                    deg=0;
            }
        }
        else if(parts[i]=='x')
            xcount++;
    }
    reduced_deg=deg-1;
    new_coeff=coeff*deg;

    if(deg!=0)
        calculate(new_coeff,reduced_deg,sign);

//    if(xcount!=0) {
//        if(reduced_deg==1)
//            cout<<new_coeff<<"*x"<<" ";
//        else if(reduced_deg==0)
//            cout<<new_coeff<<" ";
//        else
//            cout<<new_coeff<<"*x^"<<reduced_deg<<" ";
//    }
//    else {
//        coeff=0;
//        cout<<coeff;
//    }
//    if(new_coeff<10) {
//        after_diff[1]=new_coeff+48;
//        after_diff[2]='*';
//        after_diff[3]='x';
//        after_diff[4]='^';
//    }
//
//    else if(new_coeff>=10) {
//        after_diff[1]=(new_coeff/10)+48;
//        after_diff[2]=(new_coeff%10)+48;
//        after_diff[3]='*';
//        after_diff[4]='x';
//        after_diff[5]='^';
//    }

}
