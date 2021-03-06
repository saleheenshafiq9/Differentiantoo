#include "header.h"

using namespace std;

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


void value_partition(char input[100], int tokens[100]) {
    int power=1, coeff=1;
    char variable, sign;

    for(int i=0; i<strlen(input); i++) {
        if(tokens[i]==1) {
            variable = input[i];
            if(tokens[i+1]!=4)
                power=1;
        }
        else if(tokens[i]==2) {
            if(input[i+1]=='*')
                coeff = (int)(input[i])-48;
            if(input[i-1]=='-' && tokens[i-2]=='\0'){
                coeff = -coeff;
            }
        }
        else if(tokens[i]==3) {
            if(tokens[i-1]=='\0')
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
        else if(tokens[i]==5) {
            if(input[i]=='(')
                continue;
        }

        if(sign=='+' || sign=='-' || input[i]==')') {
            differentiate(coeff, variable, power, sign);
            sign = '\0';
        }
    }
    //cout<<variable<<"\n"<<coeff<<"\n"<<power;
}


void partition(char input[100]) {

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
    value_partition(input, tokens);
    cout<<"\n\n\n\n";
}

