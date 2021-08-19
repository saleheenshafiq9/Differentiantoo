#include "header.h"

using namespace std;

int token_ln = 0;
bool function_ln(char input[100]) {

    char* if_ln = strstr(input,"ln");

    if(if_ln)
        return true;
    else
        return false;
}

void if_ln(char input[100]) {

    char ln_chain[50];
    int j=0,k;

    char var_ln;

    for(int i=0; i<strlen(input); i++) {

        if(input[i]=='(') {
            if(input[i+2]==')'){
                k=1;
                var_ln = input[i+1];
            }

            else {
                ln_chain[j] = input[i+1];
                j++;
            }
        }

        else if(j>0) {
            ln_chain[j] = input[i+1];
            j++;
        }

        if(input[i]==')') {
            ln_chain[j] = '\0';
        }
    }

    if(k!=1) {
        cout<<"(";
        partition(ln_chain);
        cout<<"/("<<ln_chain;
    }

    else {
        ln_chain[0] = var_ln;
        ln_chain[1] = ')';
        ln_chain[2] = '\0';

        cout<<"1/"<<"("<<ln_chain;
    }
}
