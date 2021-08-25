#include "header.h"

using namespace std;

int all_p = 0;

bool is_alphabte(int str)
{
    if((str >= 'a' && str <= 'z') || (str >= 'A' && str <= 'Z'))
        return true;
    else
        return false;
}

bool is_digit(int str)
{
    if(str >= '0' && str <= '9')
        return true;
    else
        return false;
}

bool is_operator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/')
        return true;
    else
        return false;
}

bool is_power(char c)
{
    if(c=='^')
        return true;
    else
        return false;
}

bool is_bracket(char c)
{
    if(c=='[' || c==']' || c=='{' || c=='}' || c=='(' || c==')')
        return true;
    else
        return false;
}

void all_partition(){
    all_p++;
}

void partition_null(){
    all_p = 0;
}

string value_partition(char input[100], int tokens[100]) {
    int power=1, coeff=1;
    char variable, sign='\0';
    string ans3 = "";

    for(int i=0; i<strlen(input); i++) {
        if(tokens[i]==1) {
            variable = input[i];
            if(tokens[i+1]!=4)
                power=1;
            if(input[i-1]=='+')
                coeff=1;
            else if(input[i-1]=='-')
                coeff=-1;
        }
        else if(tokens[i]==2) {
            if(input[i+1]=='*')
                coeff = (int)(input[i])-48;
            if(input[i-1]=='-' && input[i-2]=='('){
                coeff = coeff*(-1);
            }
            if((input[i-1]=='+' || input[i-1]=='-') && (input[i+1]=='+' || input[i+1]=='-') && input[i-2]!='^')
                coeff = 1005;
            else if((input[i-1]=='+' || input[i-1]=='-') && (input[i+1]=='(' || input[i+1]==')') && input[i-2]!='^'){
                coeff = 1011;
                variable = input[i];
            }
            else if((input[i-1]=='(' || input[i-1]==')') && (input[i+1]=='+' || input[i+1]=='-')){
                coeff = 1001;
                variable = input[i];
            }
            else if((input[i-1]=='(' || input[i-1]==')') && (input[i+1]=='(' || input[i+1]==')')){
                coeff = 1002;
                variable = input[i];
            }
       }
        else if(tokens[i]==3) {
            if(input[i-1]=='(')
                continue;
            else if(input[i]=='*')
                continue;
            else if(input[i-1]!='^')
                sign = input[i];
            else
                continue;
        }
        else if(tokens[i]==4) {
            if(tokens[i+1]==2)
                power = (int)(input[i+1])-48;
            else if(input[i+1]=='-') {
                power = (int)input[i+2]-48;
                power = -power;
            }
        }

        if(sign=='+' || sign=='-' || input[i]==')') {
//    cout<<variable<<"6"<<coeff<<"\n"<<power;
//            if(input[i]==')')
//                sign = 'f';
            ans3 += differentiate(coeff, variable, power, sign);

            if(all_p>0 && coeff!=1001)
                cout<<")";

            sign = '\0';
            coeff = 1;
            power = 1;
        }
    }

    coeff = 0;
    power = 0;
    variable = '\0';
    sign = '\0';
    null_universe();
//    cout<<")";
//    cout<<ans3;
    ans3 += ")";
    if(all_p>0)
        cout<<"\n\n\t\t\t= ";
    return ans3;
}


string partition(char input[100]) {
    string ans4="";
    int j=0,k;
    int tokens[100];
    for(int i=0; i<strlen(input); i++) {
            bool x;
            int token_type;
            if(is_alphabte(input[i]))
                tokens[i] = 1;
            else if(is_digit(input[i]))
                tokens[i] = 2;
            else if(is_operator(input[i]))
                tokens[i] = 3;
            else if(is_power(input[i]))
                tokens[i] = 4;
            else if(is_bracket(input[i]))
                tokens[i] = 5;
  }
    ans4 += value_partition(input, tokens);
    return ans4;
}

