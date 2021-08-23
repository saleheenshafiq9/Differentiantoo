#include "header.h"

using namespace std;

bool function_uv(char input[100]){

    for(int i=0; i<strlen(input); i++){
        if(input[i]=='*' && input[i-1]==')' && (input[i+1]=='(' || (input[i+1]>96 && input[i+1]<123)))
            return true;
        else
            continue;
    }
    return false;
}

string if_uv(char input[100]) {

    string ans8 = "";
    char first_uv[50], second_uv[50];
    int find_delimit=0, j=0, k=0;

    for(int i=0; i<strlen(input); i++){

        if(input[i]=='*' && input[i-1]==')' && (input[i+1]=='(' || (input[i+1]>96 && input[i+1]<123))){
            find_delimit = 1;
            continue;
        }

        if(find_delimit==0){
            first_uv[i] = input[i];
            k++;
        }

        else if(find_delimit==1){
            second_uv[j] = input[i];
            j++;
        }
    }

    first_uv[k] = '\0';
    second_uv[j] = '\0';

//    cout<<first_uv<<"\n";
//    cout<<second_uv;

    bool trigonometry_tracker2 = function_trigonometry(second_uv);
    bool ln_tracker2 = function_ln(second_uv);
    bool root_tracker2 = function_root(second_uv);

    if(trigonometry_tracker2==true){
        ans8 += first_uv;
        ans8 += "*";
        ans8 += if_trigonometry(second_uv);
    }

    else if(ln_tracker2==true){
        ans8 += first_uv;
        ans8 += "*";
        ans8 += if_ln(second_uv);
    }

    else if(root_tracker2==true){
        ans8 += first_uv;
        ans8 += "*";
        ans8 += if_root(second_uv);
    }

    else {
        ans8 += first_uv;
        ans8 += "*";
        ans8 += "(";
        ans8 += partition(second_uv);
    }

    ans8 += "+";

    bool trigonometry_tracker3 = function_trigonometry(first_uv);
    bool ln_tracker3 = function_ln(first_uv);
    bool root_tracker3 = function_root(first_uv);

    if(trigonometry_tracker3==true){
        ans8 += second_uv;
        ans8 += "*";
        ans8 += if_trigonometry(first_uv);
    }

    else if(ln_tracker3==true){
        ans8 += second_uv;
        ans8 += "*";
        ans8 += if_ln(first_uv);
    }

    else if(root_tracker3==true){
        ans8 += second_uv;
        ans8 += "*";
        ans8 += if_root(first_uv);
    }

    else {
        ans8 += second_uv;
        ans8 += "*";
        ans8 += "(";
        ans8 += partition(first_uv);
    }

    return ans8;
}

