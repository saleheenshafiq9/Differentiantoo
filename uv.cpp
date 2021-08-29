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
    string ddx_f = "", ddx_s = "";
    char first_uv[50], second_uv[50];
    int find_delimit=0, j=0, k=0, sign_comp1, sing_comp1;

    cout<<"\n\n\t\t"<<"This expression follows the UV method as it's a product of two functions."<<"\n\n\t\tAs we know-"
    <<"\n\n\t\t\t"<<"d/dx(u*v) = u*d/dx(v) + v*d/dx(u)"<<"\n\n\t\t"<<"Here-\n\n\t\t\t";

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

    cout<<"u = "<<first_uv<<"\n\n\t\t\t";
    cout<<"v = "<<second_uv<<"\n\n\t\t\n\t\t";

    bool trigonometry_tracker2 = function_trigonometry(second_uv);
    bool ln_tracker2 = function_ln(second_uv);
    bool root_tracker2 = function_root(second_uv);

    if(trigonometry_tracker2==true){
        sing_comp1 = trigon_sign();

        if(sing_comp1==1 || sing_comp1==6 || sing_comp1==4){
            if(if_trigonometry(second_uv)!="0")
                ans8 += "-";
        }
    }

    if(trigonometry_tracker2==true){

        if(sing_comp1==1 || sing_comp1==6 || sing_comp1==4){
            if(if_trigonometry(second_uv)!="0")
                ddx_s += "-";
        }

        string s = if_trigonometry(second_uv);
        if(s!="0"){
            ans8 += first_uv;
            ans8 += "*";
            ans8 += s;
        }
        ddx_s += s;
    }

    else if(ln_tracker2==true){
        if(if_ln(second_uv)!="0"){
            ans8 += first_uv;
            ans8 += "*";
            ans8 += if_ln(second_uv);
        }
        ddx_s += if_ln(second_uv);
    }

    else if(root_tracker2==true){
        if(if_root(second_uv)!="0"){
            ans8 += first_uv;
            ans8 += "*";
            ans8 += if_root(second_uv);
        }
        ddx_s += if_root(second_uv);
    }

    else {
        string s3 = "(";
        s3 += partition(second_uv);
        if(s3!="(0)"){
            ans8 += first_uv;
            ans8 += "*";
            ans8 += s3;
        }
        ddx_s += s3;
    }

    bool trigonometry_tracker3 = function_trigonometry(first_uv);
    bool ln_tracker3 = function_ln(first_uv);
    bool root_tracker3 = function_root(first_uv);

    if(trigonometry_tracker3==true){
        sign_comp1 = trigon_sign();

        if(sign_comp1==1 || sign_comp1==6 || sign_comp1==4)
            ans8 += "-";
        else
            ans8 += "+";
    }

    else
        ans8 += "+";

    if(trigonometry_tracker3==true){

        if(sign_comp1==1 || sign_comp1==6 || sign_comp1==4){
            if(if_trigonometry(first_uv)!="0")
                ddx_f += "-";
        }

        string s1 = if_trigonometry(first_uv);
        if(s1!="0"){
            ans8 += second_uv;
            ans8 += "*";
            ans8 += s1;
        }
        ddx_f += s1;
    }

    else if(ln_tracker3==true){
        if(if_ln(first_uv)!="0"){
            ans8 += second_uv;
            ans8 += "*";
            ans8 += if_ln(first_uv);
        }
        ddx_f += if_ln(first_uv);
    }

    else if(root_tracker3==true){
        if(if_root(first_uv)!="0"){
            ans8 += second_uv;
            ans8 += "*";
            ans8 += if_root(first_uv);
        }
        ddx_f += if_root(first_uv);
    }

    else {
        string s2 = "(";
        s2 += partition(first_uv);
        if(s2!="(0)"){
            ans8 += second_uv;
            ans8 += "*";
            ans8 += s2;
        }
        ddx_f += s2;
    }
    cout<<"d/dx(u) = d/dx "<<first_uv<<"\n\n\t\t\t= ";

    for(int i=0; i<ddx_f.size(); i++)
        cout<<ddx_f[i];

    cout<<"\n\n\t\t"<<"d/dx(v) = d/dx "<<second_uv<<"\n\n\t\t\t= ";

    for(int i=0; i<ddx_s.size(); i++)
        cout<<ddx_s[i];

    cout<<"\n\n\t\tSo-\n\n\t\t\td/dx(u*v) = u*d/dx(v)+v*d/dx(u)\n\n\t\t\t\t  = ";
    ddx_f = "";
    ddx_s = "";
    return ans8;
}

