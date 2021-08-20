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

string if_ln(char input[100]) {

    string ans6 = "";
    char ln_chain[50];
    int j=0,k;
    char var_ln;

    for(int i=0; i<strlen(input); i++) {

        if(input[i]=='(') {
            if(input[i+2]==')' && input[i+3]==')'){
                k=1;
                int i_type = find_char_type(input[i+1]);
                if(i_type==1)
                    var_ln = input[i+1];
                else if(i_type==2)
                    var_ln = '\0';
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

    bool trigon_tracker_ln = function_trigonometry(ln_chain);
    bool ln_tracker_ln = function_ln(ln_chain);

    if(k!=1 && trigon_tracker_ln==false && ln_tracker_ln==false) {
        cout<<"(";
        ans6 += "(";
        ans6 += partition(ln_chain);
        cout<<"/("<<ln_chain;
        ans6 += "/(";
        for(int i=0; ln_chain[i]!='\0'; i++)
            ans6 += ln_chain[i];
    }

    else if(k==1 && trigon_tracker_ln==false && ln_tracker_ln==false){
        if(var_ln=='\0'){
            ans6 = "0";
            return ans6;
        }
        else {
            ln_chain[0] = var_ln;
            ln_chain[1] = ')';
            ln_chain[2] = '\0';

            cout<<"1/"<<"("<<ln_chain;
            ans6 += "1/";
            ans6 += "(";
            for(int i=0; ln_chain[i]!='\0'; i++)
                ans6 += ln_chain[i];
        }
    }

    else if(trigon_tracker_ln==true || ln_tracker_ln==true) {
        if(trigon_tracker_ln==true)
            ans6 += if_trigonometry(ln_chain);

        else if(ln_tracker_ln==true)
            ans6 += if_ln(ln_chain);

        cout<<"/"<<ln_chain;
        ans6 += "/";
        for(int i=0; ln_chain[i]!='\0'; i++)
            ans6 += ln_chain[i];
    }

    return ans6;
//
//    for(int i=0; i<strlen(ln_chain); i++)
//s        cout<<ln_chain[i];
}
