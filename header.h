#include<iostream>
#include<string.h>
#include<sstream>
#include<cstdlib>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<conio.h>
#include<cctype>
#include<cstring>
#include<vector>
#include<math.h>

using namespace std;

void menu();
string partition(char[]);
string differentiate(int,char,int,char);
void calculate(int,int,char);
void displayhead();
void clrscr();
string if_trigonometry(char[]);
string if_ln(char[]);
bool function_trigonometry(char[]);
bool function_ln(char[]);
char *removeSpaces(char *);
string num_to_str(int);
char* c_str(string);
int find_char_type(char);
void func_checker();
bool function_root(char[]);
string if_root(char[]);
string if_uv(char[]);
bool function_uv(char[]);
string if_ubyv(char[]);
bool function_ubyv(char[]);
int trigon_sign();
int as_we_know_type(char[]);
void uplusv(char[],char);
void all_trigon();
void null_trigon();
void all_ln();
void null_ln();
void all_root();
void null_root();
void all_exp();
void null_exp();
string if_exp(char[]);
bool function_exp(char[]);
#define Debug(x)  cout<< #x<< ": "<< x<< '\n';

bool is_bracket(char);
bool is_power(char);
bool is_operator(char);
bool is_digit(int);
bool is_alphabte(int);
void null_universe();
void all_algebraic();
void all_partition();
void algebraic_null();
void partition_null();
