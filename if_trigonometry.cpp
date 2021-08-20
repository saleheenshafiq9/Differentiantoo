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

    for(int i=0; i<strlen(input); i++){

        if(input[i]=='s' && input[i+2]=='n'){
            token_trigo = 2;
            return true;
        }

        else if(input[i]=='c' && input[i+2]!='t' && input[i+3]!='e'){
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

//    char* if_cosec = strstr(input,"cosec");
//
//    if(if_cosec){
//        token_trigo = 6;
//        return true;
//    }
//
//    char* if_cos = strstr(input,"cos");
//
//    if(if_cos) {
//        token_trigo = 1;
//        return true;
//    }
//
//    char* if_sin = strstr(input,"sin");
//
//    if(if_sin) {
//        token_trigo = 2;
//        return true;
//    }
//
//    char* if_tan = strstr(input,"tan");
//
//    if(if_tan) {
//        token_trigo = 3;
//        return true;
//    }
//
//    char* if_cot = strstr(input,"cot");
//
//    if(if_cot) {
//        token_trigo = 4;
//        return true;
//    }
//
//    char* if_sec = strstr(input,"sec");
//
//    if(if_sec) {
//        token_trigo = 5;
//        return true;
//    }
//    cout<<if_sec<<"check";

    if(token_trigo==0)
        return false;
}

string if_trigonometry(char input[100]) {

//    char* if_cos, if_sin, if_tan, if_cot, if_sec, if_cosec;
//
    string ans5 = "";

    char trigonometry_chain[50];
    int j=0,k;
    char var_trigon;

    for(int i=0; i<strlen(input); i++) {

        if(input[i]=='(') {
            if(input[i+2]==')'){
                k=1;
                int i_type = find_char_type(input[i+1]);
                if(i_type==1)
                    var_trigon = input[i+1];
                else if(i_type==2)
                    var_trigon = '\0';
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

//    for(int i=0; i<strlen(trigonometry_chain); i++)
//        cout<<trigonometry_chain[i];

    if(token_trigo==1 || token_trigo==6 || token_trigo==4){
        cout<<"-";
        ans5 += "-";
    }

    if(k!=1) {
        cout<<"(";
        ans5 += "(";
        ans5 += partition(trigonometry_chain);
        cout<<"*";
        ans5 += "*";
    }

    else {
        if(var_trigon=='\0'){
            ans5 = "";
            return ans5;
        }

        else {
            trigonometry_chain[0] = var_trigon;
            trigonometry_chain[1] = ')';
            trigonometry_chain[2] = '\0';
        }
    }

    if(token_trigo==1){
        cout<<"sin("<<trigonometry_chain;
        ans5 += "sin(";

        for(int i=0; trigonometry_chain[i]!='\0'; i++)
            ans5 += trigonometry_chain[i];
//        ans5 += trigonometry_chain;
    }

    else if(token_trigo==6){
        cout<<"cosec("<<trigonometry_chain<<"*cot("<<trigonometry_chain;
        ans5 += "cosec(";
        for(int i=0; trigonometry_chain[i]!='\0'; i++)
            ans5 += trigonometry_chain[i];
        ans5 += "*cot(";
        for(int i=0; trigonometry_chain[i]!='\0'; i++)
            ans5 += trigonometry_chain[i];
    }

    else if(token_trigo==2){
        cout<<"cos("<<trigonometry_chain;
        ans5 += "cos(";
        for(int i=0; trigonometry_chain[i]!='\0'; i++)
            ans5 += trigonometry_chain[i];
    }

    else if(token_trigo==3){
        cout<<"sec^2("<<trigonometry_chain;
        ans5 += "sec^2(";
        for(int i=0; trigonometry_chain[i]!='\0'; i++)
            ans5 += trigonometry_chain[i];
    }

    else if(token_trigo==4){
        cout<<"cosec^2("<<trigonometry_chain;
        ans5 += "cosec^2(";
        for(int i=0; trigonometry_chain[i]!='\0'; i++)
            ans5 += trigonometry_chain[i];
    }

    else if(token_trigo==5){
        cout<<"sec("<<trigonometry_chain<<"*tan("<<trigonometry_chain;
        ans5 += "sec(";
        for(int i=0; trigonometry_chain[i]!='\0'; i++)
            ans5 += trigonometry_chain[i];
        ans5 += "*tan(";
        for(int i=0; trigonometry_chain[i]!='\0'; i++)
            ans5 += trigonometry_chain[i];
    }

    token_trigo = 0;
    return ans5;

}
