#include "header.h"

using namespace std;

int all_t = 0;
int token_trigo = 0, k5=0;
bool function_trigonometry(char input[100]) {

    int countTrig, countLn=50, countRoot=50;
    for(int i=0; i<strlen(input); i++){
        if(input[i]=='l')
            countLn = i;
        else if(input[i]=='t' || input[i]=='s' || input[i]=='c')
            countTrig = i;
        else if(input[i]=='s' && input[i+1]=='q')
            countRoot = i;
    }

//    Debug(countLn);
//    Debug(countTrig);

    if(countLn<countTrig)
        return false;

    if(countRoot<countTrig)
        return false;

    for(int i=0; i<strlen(input); i++){

        if(input[i]=='s' && input[i+2]=='n'){
            token_trigo = 2;
            return true;
        }

        else if(input[i]=='c' && input[i+2]=='s' && input[i+3]!='e'){
            token_trigo = 1;
            return true;
        }

        else if(input[i]=='c' && input[i+3]=='e'){
            token_trigo = 6;
            return true;
        }

        else if(input[i]=='s' && input[i+2]=='c'){
            token_trigo = 5;
            return true;
        }

        else if(input[i]=='t' && input[i+2]=='n'){
            token_trigo = 3;
            return true;
        }

        else if(input[i]=='c' && input[i+2]=='t'){
            token_trigo = 4;
            return true;
        }
    }


    if(token_trigo==0)
        return false;
}

int trigon_sign(){
    k5++;
    return token_trigo;
}

void all_trigon(){
    all_t++;
}

void null_trigon(){
    all_t = 0;
}

string if_trigonometry(char input[100]) {

//    char* if_cos, if_sin, if_tan, if_cot, if_sec, if_cosec;
//
    string ans5 = "";

    char trigonometry_chain[50];
    int j=0,k;
    char var_trigon;

    for(int i=0; i<strlen(input); i++) {

        if(input[i]=='(' && i==0)
            continue;
        if(input[i]=='(' && input[i+1]=='(')
            continue;

        if(input[i]=='(' && i!=0) {
            if(input[i+2]==')' && input[i+1]!='('){
                k=1;
                int i_type = find_char_type(input[i+1]);
                if(i_type==1)
                    var_trigon = input[i+1];
                else if(i_type==2)
                    var_trigon = '\0';
            }

            else {
                trigonometry_chain[j] = input[i];
                j++;
                trigonometry_chain[j] = input[i+1];
                j++;
            }
        }

        else if(j>0) {
            trigonometry_chain[j] = input[i+1];
            j++;
        }

        if(input[i]==')') {
            trigonometry_chain[j] = '\0';
        }
    }

//    for(int i=0; i<strlen(trigonometry_chain); i++)
//        cout<<trigonometry_chain[i];
    if(all_t>0 && k!=1){

        cout<<"d/d";

        int x19, y19=0;
        char c19 ='\0';

        for(int i=0; i<strlen(input); i++){
            if(input[i]!='(' && y19==0)
                continue;
            if(find_char_type(input[i])==1 && find_char_type(input[i+1])==1)
               continue;
            if(find_char_type(input[i])==1 && input[i+1]=='(')
                continue;

            else{
                y19++;
                x19 = find_char_type(input[i]);
                if(x19==1){
                    c19 = input[i];
                    break;
                }
            }
        }

        if(c19=='\0'){
            c19 = 'x';
            cout<<c19;
        }

        else
            cout<<c19;

        cout<<trigonometry_chain<<"*";
    }

    if(token_trigo==1 || token_trigo==6 || token_trigo==4){
//        cout<<"-";
        if(k5==0){
            ans5 += "-";
            if(all_t>0 && k!=1)
                cout<<"-";
        }
    }

    if(k!=1) {
//        cout<<"(";
        ans5 += "(";
//        Debug(trigonometry_chain);
        ans5 += partition(trigonometry_chain);
//        cout<<"*";
        ans5 += "*";
    }

    else {
        if(var_trigon=='\0'){
            ans5 = "0";
            return ans5;
        }

        else {
            trigonometry_chain[0] = '(';
            trigonometry_chain[1] = var_trigon;
            trigonometry_chain[2] = ')';
            trigonometry_chain[3] = '\0';
        }
//        Debug(trigonometry_chain);
    }

    if(token_trigo==1){
        if(all_t>0 && k!=1)
            cout<<"sin"<<trigonometry_chain;

        ans5 += "sin";

        for(int i=0; trigonometry_chain[i]!='\0'; i++)
            ans5 += trigonometry_chain[i];
//        ans5 += trigonometry_chain;
    }

    else if(token_trigo==6){
        if(all_t>0 && k!=1)
            cout<<"cosec"<<trigonometry_chain<<"*cot"<<trigonometry_chain;
        ans5 += "cosec";
        for(int i=0; trigonometry_chain[i]!='\0'; i++)
            ans5 += trigonometry_chain[i];
        ans5 += "*cot";
        for(int i=0; trigonometry_chain[i]!='\0'; i++)
            ans5 += trigonometry_chain[i];
    }

    else if(token_trigo==2){
        if(all_t>0 && k!=1)
            cout<<"cos"<<trigonometry_chain;
        ans5 += "cos";
        for(int i=0; trigonometry_chain[i]!='\0'; i++)
            ans5 += trigonometry_chain[i];
    }

    else if(token_trigo==3){
        if(all_t>0 && k!=1)
            cout<<"sec^2"<<trigonometry_chain;
        ans5 += "sec^2";
        for(int i=0; trigonometry_chain[i]!='\0'; i++)
            ans5 += trigonometry_chain[i];
    }

    else if(token_trigo==4){
        if(all_t>0 && k!=1)
            cout<<"cosec^2"<<trigonometry_chain;
        ans5 += "cosec^2";
        for(int i=0; trigonometry_chain[i]!='\0'; i++)
            ans5 += trigonometry_chain[i];
    }

    else if(token_trigo==5){
        if(all_t>0 && k!=1)
            cout<<"sec"<<trigonometry_chain<<"*tan"<<trigonometry_chain;
        ans5 += "sec";
        for(int i=0; trigonometry_chain[i]!='\0'; i++)
            ans5 += trigonometry_chain[i];
        ans5 += "*tan";
        for(int i=0; trigonometry_chain[i]!='\0'; i++)
            ans5 += trigonometry_chain[i];
    }
    if(all_t>0 && k!=1)
        cout<<"\n\n\t\t\t    = ";
    token_trigo = 0;
    k5 = 0;
    return ans5;
    null_trigon();
}
