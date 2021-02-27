#include "header.h"

using namespace std;
char input[100];

char *removeSpaces(char *input)
{
    int i = 0, j = 0;
    while (input[i])
    {
        if (input[i] != ' ')
           input[j++] = input[i];
        i++;
    }
    input[j] = '\0';
    return input;
}

void cutSpace() {
    cin.get(input,100);
    removeSpaces(input);
}

void clrscr()
{
    system("@cls||clear");
}

int main()
{
    int n,l=50;
    displayhead();
    cout<<"\n\n\t\t\t\t--> INPUT AN EQUATION (Press '1')";
    cout<<"\n\n\t\t\t\t--> USER MANUAL (Press '2')";
    cout<<"\n\n\t\t\t\t--> EXIT (Press '3')\n";
    cin>>n;

    while(l--) {
        fflush(stdin);
        if(n==1) {
            clrscr();
            displayhead();
            cout<<"\t\tInput :  ";
            cutSpace();
            cout<<"\n\n\t\tOutput :  ";
//        cout<<input;
            bool trigonometry_tracker = function_trigonometry(input);

            if(trigonometry_tracker==false) {
                cout<<"(";
                partition(input);
            }
            else if(trigonometry_tracker==true)
                if_trigonometry(input);

            main();
        }

        else if(n==2) {
            clrscr();
            displayhead();
            cout<<"\n\n\t\t\t\t-->";
        }
        else if(n==3)
            exit(1);
    }

    return 0;
}



