#include "header.h"

using namespace std;

void partition(char input[100]) {
    char partial_function[100];
    int j=0,k;
    for(int i=strlen(input)-1; i>=0; i--) {
        input[i+1]=input[i];
        if(i==strlen(input) && input[i]!=')')
            input[i+2]=')';

        else if(i==0)
            input[0]='(';
    }
    for(int i=0; i<strlen(input); i++) {
        if(input[i]=='(' || input[i]=='+' || input[i]=='-' || input[i]==')') {

                if(input[i]=='(') {
                        k=input[i];
                        continue;
                   }

                else {
                    partial_function[j]='\0';
                //cout<<partial_function<<"\t";
                j=0;
                differentiate(partial_function,k);
                k=input[i];
                }
           }

        else if(input[i]!='+' && input[i]!='-' && input[i]!='(') {
            partial_function[j]=input[i];
            j++;
        }
//        else if(input[i]=='+' || input[i]=='-' || input[i]==')') {
//                partial_function[j]='\0';
//               // cout<<partial_function<<"\t";
//                j=0;
//                differentiate(partial_function,input[i]);
//                cout<<input[i]<<" ";
//        }
    }
    cout<<" )\n\n\n\n";
}
