#include "header.h"
//#include "vh.h"
//
//using namespace std;
//
//string convertToString(char* a, int size)
//{
//    int i;
//    string s = "";
//    for (i = 0; i < size; i++) {
//        s = s + a[i];
//    }
//    return s;
//}
//
string num_to_str(int num){
    string dec_stri = "";
    if(num>9){
        int num_new = num/10;
        dec_stri += (48 + num_new);

        int num_new_2 = num - (num_new)*10;
        dec_stri += (48 + num_new_2);
    }

    else {
        dec_stri += (48 + num);
    }

    return dec_stri;
}

char* c_str(string s){
    char c[100];

    for(int i=0; i<100; i++){
        c[i] = s[i];
    }
    c[s.size()] = '\0';
    for(int i=0; i<strlen(c); i++)
        cout<<c[i];
    cout<<"\n";
    return c;
}

int find_char_type(char c){

    if(is_alphabte(c))
        return 1;
    else if(is_digit(c))
        return 2;
    else if(is_operator(c))
        return 3;
    else if(is_power(c))
        return 4;
    else if(is_bracket(c))
        return 5;
    else
        return 0;
}

