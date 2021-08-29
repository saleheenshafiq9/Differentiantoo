#include "header.h"

using namespace std;

int token_ex = 0;
int all_e = 0;

bool function_exp(char input[100]) {

    char* if_exp = strstr(input,"e^");

    if(if_exp)
        return true;
    else
        return false;
}

void all_exp(){
    all_e++;
}

void null_exp(){
    all_e = 0;
}

string if_exp(char input[100]) {

    string ans50 = "";
    string ans51 = "";
    char exp_chain[50];
    int j=0,k;
    char var_exp;

    for(int i=0; i<strlen(input); i++) {

        if(input[i]=='(' && i==0)
                continue;
        if(input[i]=='(') {
            if(input[i+2]==')'){
                k=1;
                int i_type = find_char_type(input[i+1]);
                if(i_type==1)
                    var_exp = input[i+1];
                else if(i_type==2)
                    var_exp = '\0';
            }

            else {
                exp_chain[j] = input[i];
                j++;
                exp_chain[j] = input[i+1];
                j++;
            }
        }

        else if(j>0) {
            exp_chain[j] = input[i+1];
            j++;
        }

        if(input[i]==')' && input[i-2]!='(') {
            exp_chain[j] = '\0';
        }
    }
//    Debug(exp_chain);
    bool trigon_tracker_exp = function_trigonometry(exp_chain);

//    if(k==1 && trigon_tracker_ln==true){
//        Debug(exp_chain);
//    }

    if(k!=1 && trigon_tracker_exp==false) {
        if(all_e>0){
            int x50, y50=0;
            char c50 ='\0';

            cout<<"d/d";

            for(int i=0; i<strlen(input); i++){
                if(input[i]!='(' && y50==0)
                    continue;

                else{
                    y50++;
                    x50 = find_char_type(input[i]);
                    if(x50==1){
                        c50 = input[i];
                        break;
                    }
                }
            }

            if(c50=='\0'){
                c50 = 'x';
                cout<<c50;
            }

            else
                cout<<c50;

            cout<<exp_chain;

            }


        ans50 += "(";
        ans50 += partition(exp_chain);
        ans50 += "*e^";
//        cout<<"/"<<exp_chain;
        for(int i=0; exp_chain[i]!='\0'; i++)
            ans50 += exp_chain[i];
        if(all_e>0){
            cout<<"*e^"<<exp_chain;
            cout<<"\n\n\t\t\t    = ";
        }
    }

    else if(k==1 && trigon_tracker_exp==false){
        if(var_exp=='\0'){
            ans50 = "0";
            return ans50;
        }
        else {
            exp_chain[0] = var_exp;
            exp_chain[1] = ')';
            exp_chain[2] = '\0';

//            cout<<"1/"<<"("<<exp_chain;
            ans50 += "e^";
            ans50 += "(";
            for(int i=0; exp_chain[i]!='\0'; i++)
                ans50 += exp_chain[i];
        }
    }

    else if(trigon_tracker_exp==true) {


            if(all_e>0){
                all_trigon();
                cout<<"> First of all, we have to differentiate the part at the power of e.\n\n\t\t\tSo-\n\n\t\t\t    = ";
            }

            if(k==1){
                for(int i=0; i<strlen(exp_chain); i++){
                    if(exp_chain[i]=='(' && exp_chain[i+1]==')'){
                        exp_chain[i+1] = var_exp;
                        exp_chain[i+2] = ')';
                        exp_chain[i+3] = '\0';
                    }
                }
            }
            ans51 += if_trigonometry(exp_chain);
            ans50 += ans51;
            if(all_e>0){
                cout<<ans51;
                cout<<"\n\n\n\t\t\tFinally-\n\n\t\t\t    = ";
            }

//        cout<<"/"<<exp_chain;
        ans50 += "*e^";
        for(int i=0; exp_chain[i]!='\0'; i++){
            if(exp_chain[i]=='(' && i==0)
                continue;
            if(exp_chain[i]=='(' && exp_chain[i+1]=='(')
                continue;
            ans50 += exp_chain[i];
        }
    }

    return ans50;
//
//    for(int i=0; i<strlen(exp_chain); i++)
//s        cout<<exp_chain[i];
}

