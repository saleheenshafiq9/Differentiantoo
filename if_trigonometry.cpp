#include "header.h"

using namespace std;

int token_trigo = 0;
bool function_trigonometry(char input[100]) {

    int countTrig, countLn;
    for(int i=0; i<strlen(input); i++){
        if(input[i]=='l')
            countLn = i;
        else if(input[i]=='t' || input[i]=='s' || input[i]=='c')
            countTrig = i;
    }

    if(countLn<countTrig)
        return false;

    char* if_cos = strstr(input,"cos");
    char* if_sin = strstr(input,"sin");
    char* if_tan = strstr(input,"tan");
    char* if_cot = strstr(input,"cot");
    char* if_sec = strstr(input,"sec");
    char* if_cosec = strstr(input,"cosec");
//    cout<<if_sec<<"check";
    if(if_cos) {
        if(if_cosec)
            token_trigo = 6;
        else
            token_trigo = 1;
    }

    else if(if_sin)
        token_trigo = 2;

    else if(if_tan)
        token_trigo = 3;

    else if(if_cot)
        token_trigo = 4;

    else if(if_sec)
        token_trigo = 5;

    if(token_trigo!=0)
        return true;
    else
        return false;
}

void if_trigonometry(char input[100]) {

//    char* if_cos, if_sin, if_tan, if_cot, if_sec, if_cosec;
//
    char trigonometry_chain[50];
    int j=0,k;
    char var_trigon;

    for(int i=0; i<strlen(input); i++) {

        if(input[i]=='(') {
            if(input[i+2]==')'){
                k=1;
                var_trigon = input[i+1];
            }

            else {
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

    if(token_trigo==1 || token_trigo==6 || token_trigo==4)
        cout<<"-";

    if(k!=1) {
        cout<<"(";
        partition(trigonometry_chain);
        cout<<"*";
    }

    else {
        trigonometry_chain[0] = var_trigon;
        trigonometry_chain[1] = ')';
        trigonometry_chain[2] = '\0';
    }

    if(token_trigo==1)
        cout<<"sin("<<trigonometry_chain;

    else if(token_trigo==6)
        cout<<"cosec("<<trigonometry_chain<<"*cot("<<trigonometry_chain;

    else if(token_trigo==2)
        cout<<"cos("<<trigonometry_chain;

    else if(token_trigo==3)
        cout<<"sec^2("<<trigonometry_chain;

    else if(token_trigo==4)
        cout<<"cosec^2("<<trigonometry_chain;

    else if(token_trigo==5)
        cout<<"sec("<<trigonometry_chain<<"*tan("<<trigonometry_chain;

    token_trigo = 0;

}
