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

}

void menu(){
    int n,l=50;
    displayhead();
    cout<<"\n\n\t\t\t\t--> INPUT AN EQUATION (Press '1')";
    cout<<"\n\n\t\t\t\t--> DERIVATIVE FORMULAS (Press '2')";
    cout<<"\n\n\t\t\t\t--> USER MANUAL (Press '3')";
    cout<<"\n\n\t\t\t\t--> EXIT (Press '4')\n";
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

        bool uv_tracker = function_uv(input);
        bool ubyv_tracker = function_ubyv(input);

        if(uv_tracker==true){
            ans += if_uv(input);
            fans.push_back(ans);
            ans = "";
        }

        else if(ubyv_tracker==true){
            ans += if_ubyv(input);
            fans.push_back(ans);
            ans = "";
        }

        else {
            bool trigonometry_tracker = function_trigonometry(input);
            bool ln_tracker = function_ln(input);
            bool root_tracker = function_root(input);

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

            else if(root_tracker==true){
                ans += if_root(input);
                fans.push_back(ans);
                ans = "";
            }

            else {
                if_algebric(input);
            }
        }

//            cout<<"\n"<<fans[0]<<"\n";
//            if_algebric(c_str(fans[0]));
//            cout<<"\n"<<fans[1]<<"\n";
////            fans.push_back(input.c_string());
        for (int i = 0; i < fans.size(); ++i){
            cout << fans[i] << "\n";
        }

            menu3();

        }

        else if(n==2) {
            clrscr();
            displayhead();
            cout<<"\n\n\t GENERAL FORMULA :";
            cout<<"\n\n\t\t\t--> 1) d/dx(c) = 0 ; c is any constant.";
            cout<<"\n\n\t\t\t--> 2) d/dx(x^n) = n*x^(n-1) [The Power Rule of Derivatives]";
            cout<<"\n\n\t\t\t--> 3) d/dx(x) = 1";
            cout<<"\n\n\t\t\t--> 4) d/dx(u+v) = d/dx(u) + d/dx(v) ; u and v are two functions consist of variable 'x'.";
            cout<<"\n\n\t\t\t--> 5) d/dx(u*v) = u*d/dx(v) + v*d/dx(u) ; u and v are two functions consist of variable 'x'.";
            cout<<"\n\n\t\t\t--> 6) d/dx(u/v) = [v*d/dx(u) - u*d/dx(v)]/v^2 ; u and v are two functions consist of variable 'x'.";
            cout<<"\n\n\t\t\t--> 7) d/dx(sqrt(x)) = 1/2*sqrt(x)";

            cout<<"\n\n\n\n\t DERIVATIVES OF LOGARITHMIC FUNCTIONS :";
            cout<<"\n\n\t\t\t--> 8) d/dx(ln(x)) = 1/x";
            cout<<"\n\n\t\t\t--> 9) d/dx(ln(u)) = d/dx(u)/u ; u is a function consists of variable 'x'.";

            cout<<"\n\n\n\n\t DERIVATIVES OF TRIGONOMETRIC FUNCTIONS :";
            cout<<"\n\n\t\t\t--> 10) d/dx(sin(x)) = cos(x)";
            cout<<"\n\n\t\t\t--> 11) d/dx(cos(x)) = -sin(x)";
            cout<<"\n\n\t\t\t--> 12) d/dx(tan(x)) = sec^2(x)";
            cout<<"\n\n\t\t\t--> 13) d/dx(sec(x)) = sec(x)*tan(x)";
            cout<<"\n\n\t\t\t--> 14) d/dx(cot(x)) = -cosec^2(x)";
            cout<<"\n\n\t\t\t--> 15) d/dx(cosec(x)) = -cosec(x)*cot(x)";

            cout<<"\n\n\n\n\t DERIVATIVES OF HYPERBOLIC FUNCTIONS :";
            cout<<"\n\n\t\t\t--> 16) d/dx(sinh(x)) = cosh(x)";
            cout<<"\n\n\t\t\t--> 17) d/dx(cosh(x)) = sinh(x)";
            cout<<"\n\n\t\t\t--> 18) d/dx(tanh(x)) = sech^2(x)";
            cout<<"\n\n\t\t\t--> 19) d/dx(sech(x)) = -sech(x)*tanh(x)";
            cout<<"\n\n\t\t\t--> 20) d/dx(coth(x)) = -cosech^2(x)";
            cout<<"\n\n\t\t\t--> 21) d/dx(cosech(x)) = -cosech(x)*coth(x)";

            cout<<"\n\n\n\n\t DERIVATIVES OF EXPONENTIAL FUNCTIONS :";
            cout<<"\n\n\t\t\t--> 22) d/dx(e^x) = e^x";
            cout<<"\n\n\t\t\t--> 23) d/dx(x^x) = x^x*(1+ln(x))";
            cout<<"\n\n\t\t\t--> 24) d/dx(a^x) = a^x*ln(a)";


            menu3();
        }
        else if(n==4)
            exit(1);
}
