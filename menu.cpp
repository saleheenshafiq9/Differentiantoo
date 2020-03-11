#include "header.h"

using namespace std;
char input[100];

void menu() {
    int n;
    cout<<"\n\n\t\t\t\t--> INPUT AN EQUATION (Press '1')";
    cout<<"\n\n\t\t\t\t--> USER MANUAL (Press '2')";
    cout<<"\n\n\t\t\t\t--> EXIT (Press '3')\n";
    cin>>n;

    if(n==1) {
        clrscr();
        displayhead();
        cout<<"\t\tInput :  ";
        cin>>input;
        cout<<"\n\n\t\tOutput :  ";
        partition(input);
    }

    else if(n==2) {
        clrscr();
        displayhead();
        cout<<"\n\n\t\t\t\t-->";
    }
    else if(n==3)
        exit(1);
}

void clrscr()
{
    system("@cls||clear");
}
