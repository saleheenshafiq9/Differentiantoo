#include "main.h"

using namespace std;

char afterDiff[50];
int l=0;

void makeItParts(char input[100]) {
    char partsHolder[50];

    int j=0, c=1, h=0;
    for(int i=0; i<strlen(input); i++){
        if(input[i]!='+' && input[i]!='-' && input[i]!=')'){
            partsHolder[j]=input[i];
            j++;
        }
        else if(input[i]==')' || input[i]=='+' || input[i]=='-'){
                partsHolder[j]='\0';
            differentiateParts(partsHolder,input[i]);
            j=0;
        }
    }
    cout<<afterDiff<<'\t';
}


void differentiateParts(char partsHolder[50], char sign){
    char reducedPower;
    int flag=0;
    int parsedIntCoeff, parsedIntPow, parsedIntFin;
    for(int i=0;i<strlen(partsHolder);i++){
            if(partsHolder[i]=='2' || partsHolder[i]=='3' || partsHolder[i]=='4' || partsHolder[i]=='5' || partsHolder[i]=='6' || partsHolder[i]=='7'
               || partsHolder[i]=='8' || partsHolder[i]=='9'){
                    if(partsHolder[i+1]!='*')
                        break;
                    else {
                    parsedIntCoeff = partsHolder[i]-48;
                    flag++;
                    continue;
                    }
               }

        else if(partsHolder[i]=='^' && flag==0){

            reducedPower = partsHolder[i+1] - 1;
            afterDiff[l]= partsHolder[i+1];
            l++;
            afterDiff[l]='*';
            l++;
            afterDiff[l]='x';
            l++;

            if(reducedPower!='1'){
                    afterDiff[l]='^';
                    l++;
                    afterDiff[l]=reducedPower;
            }
            l++;
            afterDiff[l]=sign;
            l++;
        }

        else if(partsHolder[i]=='^' && flag!=0){
            reducedPower = partsHolder[i+1] - 1;
            parsedIntPow = reducedPower-47;
            parsedIntFin = parsedIntCoeff*parsedIntPow;
            cout<<parsedIntFin<<"\n";
            afterDiff[l]=parsedIntFin;
            l++;
            afterDiff[l]='*';
            l++;
            afterDiff[l]='x';
            l++;

            if(reducedPower!='1'){
                    afterDiff[l]='^';
                    l++;
                    afterDiff[l]=reducedPower;
            }
            l++;
            afterDiff[l]=sign;
            l++;
        }

        else if(partsHolder[i]=='x' && partsHolder[i+1]!='^' && partsHolder[i-1]!='*'){
            afterDiff[l]='1';
            l++;
        }

        else if(partsHolder[i]=='x' && partsHolder[i+1]!='^' && partsHolder[i-1]=='*'){
            afterDiff[l]=partsHolder[i-2];
            l++;
        }
    }
    //cout<<partsHolder<<'\t';

}
