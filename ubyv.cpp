#include "header.h"

using namespace std;

bool function_ubyv(char input[100]){

    for(int i=0; i<strlen(input); i++){
        if(input[i]=='/' && input[i-1]==')' && (input[i+1]=='(' || (input[i+1]>96 && input[i+1]<123)))
            return true;
        else
            continue;
    }
    return false;
}

string if_ubyv(char input[100]) {

    string ans9 = "";
    string ddx_f1 = "", ddx_s1 = "";
    char first_uv1[50], second_uv1[50];
    int find_delimit1=0, j1=0, k1=0, sign_comp, sing_comp;

    cout<<"\n\n\t\t"<<"This expression follows the U/V method as it's a division among two functions."<<"\n\n\t\tAs we know-"
    <<"\n\n\t\t\t"<<"d/dx(u/v) = [v*d/dx(u) - u*d/dx(v)]/v^2"<<"\n\n\t\t"<<"Here-\n\n\t\t\t";

    for(int i=0; i<strlen(input); i++){

        if(input[i]=='/' && input[i-1]==')' && (input[i+1]=='(' || (input[i+1]>96 && input[i+1]<123))){
            find_delimit1 = 1;
            continue;
        }

        if(find_delimit1==0){
            first_uv1[i] = input[i];
            k1++;
        }

        else if(find_delimit1==1){
            second_uv1[j1] = input[i];
            j1++;
        }
    }

    first_uv1[k1] = '\0';
    second_uv1[j1] = '\0';

    cout<<"u = "<<first_uv1<<"\n\n\t\t\t";
    cout<<"v = "<<second_uv1<<"\n\n\t\t\n\t\t";

//    Debug(second_uv1);

    ans9 += "[";

    bool trigonometry_tracker5 = function_trigonometry(first_uv1);
    bool ln_tracker5 = function_ln(first_uv1);
    bool root_tracker5 = function_root(first_uv1);

    if(trigonometry_tracker5==true){
        sing_comp = trigon_sign();

        if(sing_comp==1 || sing_comp==6 || sing_comp==4){
            if(if_trigonometry(first_uv1)!="0")
                ans9 += "-";
        }
    }

    if(trigonometry_tracker5==true){

        if(sing_comp==1 || sing_comp==6 || sing_comp==4){
            if(if_trigonometry(first_uv1)!="0")
                ddx_f1 += "-";
        }

        string s7 = if_trigonometry(first_uv1);
        if(s7!="0"){
            ans9 += second_uv1;
            ans9 += "*";
            ans9 += s7;
        }
        ddx_f1 += s7;
    }

    else if(ln_tracker5==true){
        if(if_ln(first_uv1)!="0"){
            ans9 += second_uv1;
            ans9 += "*";
            ans9 += if_ln(first_uv1);
        }
        ddx_f1 += if_ln(first_uv1);
    }

    else if(root_tracker5==true){
        if(if_root(first_uv1)!="0"){
            ans9 += second_uv1;
            ans9 += "*";
            ans9 += if_root(first_uv1);
        }
        ddx_f1 += if_root(first_uv1);
    }

    else {
        string s8 = "(";
        s8 += partition(first_uv1);
        if(s8!="(0)"){
            ans9 += second_uv1;
            ans9 += "*";
            ans9 += s8;
        }
        ddx_f1 += s8;
    }

    bool trigonometry_tracker4 = function_trigonometry(second_uv1);
    bool ln_tracker4 = function_ln(second_uv1);
    bool root_tracker4 = function_root(second_uv1);

    if(trigonometry_tracker4==true){
        sign_comp = trigon_sign();

        if(sign_comp==1 || sign_comp==6 || sign_comp==4)
            ans9 += "+";
        else
            ans9 += "-";
    }

    else
        ans9 += "-";

    if(trigonometry_tracker4==true){

        if(sign_comp==1 || sign_comp==6 || sign_comp==4){
            if(if_trigonometry(second_uv1)!="0")
                ddx_s1 += "-";
        }

        string s5 = if_trigonometry(second_uv1);
//        Debug(s5);
        if(s5!="0"){
            ans9 += first_uv1;
            ans9 += "*";
            ans9 += s5;
        }
        ddx_s1 += s5;
    }

    else if(ln_tracker4==true){
        if(if_ln(second_uv1)!="0"){
            ans9 += first_uv1;
            ans9 += "*";
            ans9 += if_ln(second_uv1);
        }
        ddx_s1 += if_ln(second_uv1);
    }

    else if(root_tracker4==true){
        if(if_root(second_uv1)!="0"){
            ans9 += first_uv1;
            ans9 += "*";
            ans9 += if_root(second_uv1);
        }
        ddx_s1 += if_root(second_uv1);
    }

    else {

        string s6 = "(";
        s6 += partition(second_uv1);
        if(s6!="(0)"){
            ans9 += first_uv1;
            ans9 += "*";
            ans9 += s6;
        }
        ddx_s1 += s6;
    }

    cout<<"d/dx(u) = d/dx "<<first_uv1<<"\n\n\t\t\t= ";

    for(int i=0; i<ddx_f1.size(); i++)
        cout<<ddx_f1[i];

    cout<<"\n\n\t\t"<<"d/dx(v) = d/dx "<<second_uv1<<"\n\n\t\t\t= ";

    for(int i=0; i<ddx_s1.size(); i++)
        cout<<ddx_s1[i];

    cout<<"\n\n\t\tSo-\n\n\t\t\td/d/dx(u/v) = [v*d/dx(u)-u*d/dx(v)]/v^2\n\n\t\t\t\t    = ";

    ans9 += "]/";

    if(trigonometry_tracker4==true || ln_tracker4==true || root_tracker4==true)
        ans9 += "[";

    ans9 += second_uv1;

    if(trigonometry_tracker4==true || ln_tracker4==true || root_tracker4==true)
        ans9 += "]";

    ans9 += "^2";
    ddx_f1 = "";
    ddx_s1 = "";

    return ans9;
}


