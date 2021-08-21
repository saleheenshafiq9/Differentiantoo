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

//    cout<<"(";
    ans += "(";
    ans += partition(input2);
    fans.push_back(ans);
}
void menu3(){
    int p;
    cout<<"\n\n";

    cout<<"\n\n\t\t\t\t--> BACK TO MAIN MENU (Press '1')";
    cout<<"\n\n\t\t\t\t--> EXIT (Press '2')\n";
    cin>>p;

    if(p==1){
        ans = "";
        fans.pop_back();
        clrscr();
        menu();
    }
    else if(p==2)
        exit(1);
}

void func_checker(){
        bool trigonometry_tracker = function_trigonometry(input);
        bool ln_tracker = function_ln(input);

        if(trigonometry_tracker==true){
            ans += if_trigonometry(input);
            fans.push_back(ans);
            ans = "";
        }

        else if(ln_tracker==true){
            ans += if_ln(input);
            fans.push_back(ans);
            ans = "";
        }

        else {
            if_algebric(input);
        }
//            cout<<"\n"<<fans[0]<<"\n";
//            if_algebric(c_str(fans[0]));
//            cout<<"\n"<<fans[1]<<"\n";
////            fans.push_back(input.c_string());
        for (int i = 0; i < fans.size(); ++i){
            cout << fans[i] << "\n";
        }
}

void menu(){
    int n,l=50;
    displayhead();
    cout<<"\n\n\t\t\t\t--> INPUT AN EQUATION (Press '1')";
    cout<<"\n\n\t\t\t\t--> USER MANUAL (Press '2')";
    cout<<"\n\n\t\t\t\t--> EXIT (Press '3')\n";
    cin>>n;


        fflush(stdin);
        if(n==1) {
            for(int i=0; i<100; i++)
                input[i] = '\0';

            clrscr();
            displayhead();
            cout<<"\t\tInput :  ";
            cutSpace();
            cout<<"\n\n\t\tOutput :  ";

            func_checker();
//        cout<<input;
//            bool trigonometry_tracker = function_trigonometry(input);
//            bool ln_tracker = function_ln(input);
//
//            if(trigonometry_tracker==true){
//                ans += if_trigonometry(input);
//                fans.push_back(ans);
//                ans = "";
//            }
//
//            else if(ln_tracker==true){
//                ans += if_ln(input);
//                fans.push_back(ans);
//                ans = "";
//            }
//
//            else {
//                if_algebric(input);
//            }
////            cout<<"\n"<<fans[0]<<"\n";
////            if_algebric(c_str(fans[0]));
////            cout<<"\n"<<fans[1]<<"\n";
//////            fans.push_back(input.c_string());
//            for (int i = 0; i < fans.size(); ++i){
//                cout << fans[i] << "\n";
//            }

            menu3();

        }

        else if(n==2) {
            clrscr();
            displayhead();
            cout<<"\n\n\t\t\t\t-->";
        }
        else if(n==3)
            exit(1);

}
