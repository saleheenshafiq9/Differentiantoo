#include "header.h"

using namespace std;
char derivative[100];
char universal_sign = '\0';
int sign_remover = 0;

void null_universe(){
    universal_sign = '\0';
}

string differentiate(int coeff, char variable, int power, char sign) {

    string ans2 = "";

    if(coeff==1001){
        return ans2;
    }

    if(coeff==1005)
        return "";

    else if(coeff==1002){
//        cout<<"0";
        ans2 += "0";
        return ans2;
    }

    int new_coeff = coeff*power;
    int new_power = power-1;

    if(universal_sign=='+' || universal_sign=='-') {
        if(new_coeff>0){
//            cout<<universal_sign;
            ans2 += universal_sign;
        }
        else if(new_coeff<0 && new_power!=0) {
            if(sign_remover==0){
                sign_remover++;
                if(universal_sign=='+'){
//                    cout<<"-";
                    ans2 += "-";
                }
            }
            else {
                if(universal_sign=='+'){
//                    cout<<"-";
                    ans2 += "-";
                }
                else if(new_power<0 && universal_sign=='-'){
//                    cout<<"+";
                    ans2 += "+";
                }
                else{
//                    cout<<"-";
                    ans2 += "-";
                }
            }
        }
        else if(new_power==0 || new_power==1) {
//            cout<<universal_sign;
            ans2 += universal_sign;
        }
        if(new_coeff!=1 && new_coeff!=-1){
//            cout<<abs(new_coeff);
            ans2 += num_to_str(abs(new_coeff));
        }
        if(new_coeff==1 && new_power==0){
//            cout<<new_coeff;
            ans2 += "1";
        }
        if(new_coeff==-1 && new_power==0){
//            cout<<abs(new_coeff);
            ans2 += "1";
        }
    }

    else {
        if(new_coeff!=1){
//            cout<<new_coeff;
            if(new_coeff<0){
                ans2 += "-";
                ans2 += num_to_str(abs(new_coeff));
            }
            else
                ans2 += num_to_str(new_coeff);
        }
        if(new_coeff==1 && new_power==0){
//            cout<<new_coeff;
            ans2 += "1";
        }
    }

    if(new_power!=0){
//        cout<<"*"<<variable;
        ans2 += "*";
        ans2 += variable;
    }
    if(new_power!=1 && new_power!=0){
//        cout<<"^"<<new_power;
        ans2 += "^";
        if(new_power<0){
            ans2 += "-";
            ans2 += num_to_str(abs(new_power));
        }
        else
            ans2 += num_to_str(new_power);
    }
    universal_sign = sign;
    sign_remover++;

//        if(sign=='f') {
//        universal_sign = '\0';
//        cout<<"check";
//    }
//    for(int i=0; i<ans2.size(); i++)
//        cout<<ans2[i]<<"\t";
    return ans2;
}

