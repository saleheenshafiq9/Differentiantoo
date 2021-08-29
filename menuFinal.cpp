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

    int x11, y11;
    char c11 ='\0';
//    cout<<"(";
    y11 = as_we_know_type(input2);
    if(y11==1){
        cout<<"\n\n\t\t"<<"As we know-"<<"\n\n\t\t\t";
        cout<<"d/dx(x^n) = n*x^(n-1) [The Power Rule of Derivatives]";
    }
    else if(y11>1){
        cout<<"\n\n\t\t"<<"As we know-"<<"\n\n\t\t\t";
        cout<<"d/dx(u+v) = d/dx(u) + d/dx(v) ; Thus we have to find the derivatives of each parts separately"<<"\n\n\t\t\t";
        cout<<"d/dx(x^n) = n*x^(n-1) [The Power Rule of Derivatives]";
    }

    cout<<"\n\n\t\t"<<"Given-"<<"\n\t\t\t";
    cout<<"  f = "<<input2<<"\n\n\t\t    d/d";

    for(int i=0; i<strlen(input2); i++){
        x11 = find_char_type(input2[i]);
        if(x11==1){
            c11 = input2[i];
            break;
        }
    }

    if(c11=='\0'){
        c11 = 'x';
        cout<<c11;
    }

    else
        cout<<c11;

    cout<<"(f) = d/d"<<c11<<input2<<"\n\n\t\t\t    = ";
    if(y11>1){
        uplusv(input2, c11);
    }
    cout<<"(";
    ans += "(";
    all_algebraic();
    all_partition();
    ans += partition(input2);
    fans.push_back(ans);
}

void vect_show(){
    for (int i = 0; i < fans.size(); ++i){
        cout << fans[i] << "\n";
    }
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
    int n,l=50,xx;
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
            cout<<"\n\n\t\tAnswer :  ";

        partition_null();
        algebraic_null();

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
            bool exp_tracker = function_exp(input);

            if(trigonometry_tracker==true){
                all_trigon();
                int x15, y15=0;
                char c15 ='\0';

                cout<<"\n\n\t\t"<<"Given-"<<"\n\t\t\t";
                cout<<"  f = "<<input<<"\n\n\t\t    d/d";

                for(int i=0; i<strlen(input); i++){
                    if(input[i]!='(' && y15==0)
                       continue;

                    else{
                        y15++;
                        x15 = find_char_type(input[i]);
                        if(x15==1){
                            c15 = input[i];
                            break;
                        }
                    }
                }

                if(c15=='\0'){
                    c15 = 'x';
                cout<<c15;
                }

                else
                    cout<<c15;

                cout<<"(f) = d/d"<<c15<<" "<<input<<"\n\n\t\t\t    = ";

                ans += if_trigonometry(input);
                fans.push_back(ans);
                ans = "";
                null_trigon();
            }

            else if(ln_tracker==true){
                    all_ln();
                int x16, y16=0;
                char c16 ='\0';

                cout<<"\n\n\t\t"<<"Given-"<<"\n\t\t\t";
                cout<<"  f = "<<input<<"\n\n\t\t    d/d";

                for(int i=0; i<strlen(input); i++){
                    if(input[i]!='(' && y16==0)
                       continue;

                    else{
                        if(find_char_type(input[i+1])==1 && find_char_type(input[i+2])==1){
                            continue;
                        }
                        y16++;
                        x16 = find_char_type(input[i]);
                        if(x16==1){
                            c16 = input[i];
                            break;
                        }
                    }
                }

                if(c16=='\0'){
                    c16 = 'x';
                cout<<c16;
                }

                else
                    cout<<c16;

                cout<<"(f) = d/d"<<c16<<" "<<input<<"\n\n\t\t\t    = ";

                ans += if_ln(input);
                fans.push_back(ans);
                ans = "";
                null_ln();
            }

            else if(root_tracker==true){
                all_root();
                int x17, y17=0;
                char c17 ='\0';

                cout<<"\n\n\t\t"<<"Given-"<<"\n\t\t\t";
                cout<<"  f = "<<input<<"\n\n\t\t    d/d";

                for(int i=0; i<strlen(input); i++){
                    if(input[i]!='(' && y17==0)
                       continue;

                    else{
                        y17++;
                        x17 = find_char_type(input[i]);
                        if(x17==1){
                            c17 = input[i];
                            break;
                        }
                    }
                }

                if(c17=='\0'){
                    c17 = 'x';
                    cout<<c17;
                }

                else
                    cout<<c17;

                cout<<"(f) = d/d"<<c17<<" "<<input<<"\n\n\t\t\t    = ";

                ans += if_root(input);
                fans.push_back(ans);
                ans = "";

                null_root();
            }

            else if(exp_tracker==true){
                all_exp();
                int x25, y25=0;
                char c25 ='\0';

                cout<<"\n\n\t\t"<<"Given-"<<"\n\t\t\t";
                cout<<"  f = "<<input<<"\n\n\t\t    d/d";

                for(int i=0; i<strlen(input); i++){
                    if(input[i]!='(' && y25==0)
                       continue;

                    else{
                        if(find_char_type(input[i+1])==1 && find_char_type(input[i+2])==1){
                            continue;
                        }
                        y25++;
                        x25 = find_char_type(input[i]);
                        if(x25==1){
                            c25 = input[i];
                            break;
                        }
                    }
                }

                if(c25=='\0'){
                    c25 = 'x';
                cout<<c25;
                }

                else
                    cout<<c25;

                cout<<"(f) = d/d"<<c25<<" "<<input<<"\n\n\t\t\t    = ";

                ans += if_exp(input);
                fans.push_back(ans);
                ans = "";
                null_exp();
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
            cout << fans[i];
        }
        cout<<"\t"<<"[Ans]"<<"\n";

            menu3();

        }

        else if(n==2) {
            clrscr();
            displayhead();
            cout<<"\n\n\t GENERAL FORMULA :";
            cout<<"\n\n\t\t\t--> 1) d/dx(c) = 0 ; c is any constant."<<"\tPRESS '1' to see examples";
            cout<<"\n\n\t\t\t--> 2) d/dx(x^n) = n*x^(n-1) [The Power Rule of Derivatives]"<<"\tPRESS '2' to see examples";
            cout<<"\n\n\t\t\t--> 3) d/dx(x) = 1";
            cout<<"\n\n\t\t\t--> 4) d/dx(u+v) = d/dx(u) + d/dx(v) ; u and v are two functions consist of variable 'x'."<<"\tPRESS '4' to see examples";
            cout<<"\n\n\t\t\t--> 5) d/dx(u*v) = u*d/dx(v) + v*d/dx(u) ; u and v are two functions consist of variable 'x'."<<"\tPRESS '5' to see examples";
            cout<<"\n\n\t\t\t--> 6) d/dx(u/v) = [v*d/dx(u) - u*d/dx(v)]/v^2 ; u and v are two functions consist of variable 'x'."<<"\tPRESS '6' to see examples";
            cout<<"\n\n\t\t\t--> 7) d/dx(sqrt(x)) = 1/2*sqrt(x)"<<"\tPRESS '7' to see examples";

            cout<<"\n\n\n\n\t DERIVATIVES OF LOGARITHMIC FUNCTIONS :";
            cout<<"\n\n\t\t\t--> 8) d/dx(ln(x)) = 1/x"<<"\tPRESS '8' to see examples";
            cout<<"\n\n\t\t\t--> 9) d/dx(ln(u)) = d/dx(u)/u ; u is a function consists of variable 'x'."<<"\tPRESS '9' to see examples";

            cout<<"\n\n\n\n\t DERIVATIVES OF TRIGONOMETRIC FUNCTIONS :";
            cout<<"\n\n\t\t\t--> 10) d/dx(sin(x)) = cos(x)"<<"\tPRESS '10' to see examples";
            cout<<"\n\n\t\t\t--> 11) d/dx(cos(x)) = -sin(x)"<<"\tPRESS '11' to see examples";
            cout<<"\n\n\t\t\t--> 12) d/dx(tan(x)) = sec^2(x)"<<"\tPRESS '12' to see examples";
            cout<<"\n\n\t\t\t--> 13) d/dx(sec(x)) = sec(x)*tan(x)"<<"\tPRESS '13' to see examples";
            cout<<"\n\n\t\t\t--> 14) d/dx(cot(x)) = -cosec^2(x)"<<"\tPRESS '14' to see examples";
            cout<<"\n\n\t\t\t--> 15) d/dx(cosec(x)) = -cosec(x)*cot(x)"<<"\tPRESS '15' to see examples";

            cout<<"\n\n\n\n\t DERIVATIVES OF HYPERBOLIC FUNCTIONS :";
            cout<<"\n\n\t\t\t--> 16) d/dx(sinh(x)) = cosh(x)";
            cout<<"\n\n\t\t\t--> 17) d/dx(cosh(x)) = sinh(x)";
            cout<<"\n\n\t\t\t--> 18) d/dx(tanh(x)) = sech^2(x)";
            cout<<"\n\n\t\t\t--> 19) d/dx(sech(x)) = -sech(x)*tanh(x)";
            cout<<"\n\n\t\t\t--> 20) d/dx(coth(x)) = -cosech^2(x)";
            cout<<"\n\n\t\t\t--> 21) d/dx(cosech(x)) = -cosech(x)*coth(x)";

            cout<<"\n\n\n\n\t DERIVATIVES OF EXPONENTIAL FUNCTIONS :";
            cout<<"\n\n\t\t\t--> 22) d/dx(e^x) = e^x"<<"\tPRESS '22' to see examples";
            cout<<"\n\n\t\t\t--> 23) d/dx(x^x) = x^x*(1+ln(x))"<<"\tPRESS '23' to see examples";
            cout<<"\n\n\t\t\t--> 24) d/dx(a^x) = a^x*ln(a)"<<"\tPRESS '24' to see examples";

            cout<<"\n\n";
            cin>>xx;

            if(xx==1){
                if_algebric("(5)");
                vect_show();
//                cout<<
            }

            else if(xx==2){
                if_algebric("(x^5)");
                vect_show();
//                cout<<
            }
            else if(xx==4){
                if_algebric("(x^5+5*x^4)");
                vect_show();
//                cout<<
            }

            else if(xx==5){
                ans += if_uv("(x^5)*sin(x)");
                fans.push_back(ans);
                ans = "";
                vect_show();
//                cout<<
            }

            else if(xx==6){
                ans += if_ubyv("tan(x)/(x^3)");
                fans.push_back(ans);
                ans = "";
                vect_show();
//                cout<<
            }

            else if(xx==7){
                ans += if_root("sqrt(5*x)");
                fans.push_back(ans);
                ans = "";
                vect_show();
//                cout<<
            }

            else if(xx=8){
                ans += if_ln("ln(x)");
                fans.push_back(ans);
                ans = "";
                vect_show();
            }

            else if(xx=9){
                ans += if_ln("ln(5*x^3)");
                fans.push_back(ans);
                ans = "";
                vect_show();
            }

            else if(xx=22){
                ans += if_exp("e^(5*x^3)");
                fans.push_back(ans);
                ans = "";
                vect_show();
            }

            menu3();
        }
        else if(n==4)
            exit(1);
}
