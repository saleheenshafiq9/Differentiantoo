#include "header.h"

using namespace std;

char input[100];
vector<string> fans;
string ans =  "";

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

void if_algebric(char input2[100]){

    cout<<"(";
    ans += "(";
    ans += partition(input2);
    fans.push_back(ans);
    ans = "";
}

void menu(){
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
            bool ln_tracker = function_ln(input);

            if(trigonometry_tracker==true){
                ans += if_trigonometry(input);
                fans.push_back(ans);
                ans = "";
            }

            else if(ln_tracker==true)
                if_ln(input);

            else {
                if_algebric(input);
            }
//            cout<<"\n"<<fans[0]<<"\n";
//            if_algebric(c_str(fans[0]));
//            cout<<"\n"<<fans[1]<<"\n";
////            fans.push_back(input.c_string());
            for (int i = 0; i < fans.size(); ++i){
                cout << fans[i] << '\n';
            }


            cout<<"\n\n";
            ans = "";
            fans.pop_back();
            menu();
        }

        else if(n==2) {
            clrscr();
            displayhead();
            cout<<"\n\n\t\t\t\t-->";
        }
        else if(n==3)
            exit(1);
    }
}
