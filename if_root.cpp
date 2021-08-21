#include "header.h"

using namespace std;

int token_root = 0;

bool function_root(char input[100]) {

    char* if_root = strstr(input,"root");

    if(if_root)
        return true;
    else
        return false;
}

string if_root(char input[100]) {

    string ans7 = "";
    char root_chain[50];
    int j=0,k;
    char var_root;

    for(int i=0; i<strlen(input); i++) {

        if(input[i]=='(') {
            if(input[i+2]==')' && input[i+3]==')'){
                k=1;
                int i_type3 = find_char_type(input[i+1]);
                if(i_type3==1)
                    var_root = input[i+1];
                else if(i_type3==2)
                    var_root = '\0';
            }

            else {
                root_chain[j] = input[i];
                j++;
                root_chain[j] = input[i+1];
                j++;
            }
        }

        else if(j>0) {
            root_chain[j] = input[i+1];
            j++;
        }

        if(input[i]==')') {
            root_chain[j] = '\0';
        }
    }

    bool trigon_tracker_root = function_trigonometry(root_chain);
    bool ln_tracker_root = function_ln(root_chain);

    if(k!=1 && trigon_tracker_root==false && ln_tracker_root==false) {
//        cout<<"(";
        ans7 += "(";
        ans7 += partition(root_chain);
//        cout<<"/"<<ln_chain;
        ans7 += "/2*root";
        for(int i=0; root_chain[i]!='\0'; i++)
            ans7 += root_chain[i];
    }

    else if(k==1 && trigon_tracker_root==false && ln_tracker_root==false){
        if(var_root=='\0'){
            ans7 = "0";
            return ans7;
        }
        else {
            root_chain[0] = var_root;
            root_chain[1] = ')';
            root_chain[2] = '\0';

//            cout<<"1/"<<"("<<ln_chain;
            ans7 += "1/";
            ans7 += "2*root(";
            for(int i=0; root_chain[i]!='\0'; i++)
                ans7 += root_chain[i];
        }
    }

    else if(trigon_tracker_root==true || ln_tracker_root==true) {
        if(trigon_tracker_root==true)
            ans7 += if_trigonometry(root_chain);

        else if(ln_tracker_root==true)
            ans7 += if_ln(root_chain);

//        cout<<"/"<<ln_chain;
        ans7 += "/2*root(";
        for(int i=0; root_chain[i]!='\0'; i++){
            if(root_chain[i]=='(' && i==0)
                continue;
            if(root_chain[i]=='(' && root_chain[i+1]=='(')
                continue;
            ans7 += root_chain[i];
        }
        ans7 += ")";
    }

    return ans7;
//
//    for(int i=0; i<strlen(ln_chain); i++)
//s        cout<<ln_chain[i];
}

