#include <iostream>
#include <stdio.h>
using namespace std;

int n = 1, *pn;
char l = 'c', *pl;
float r = 4.2, *pr;

int main(){
    pn = &n;
    pl = &l;
    pr = &r;
    cout<<"Variavel inteira: "<<*pn;
    cout<<"\nVariavel char: "<<*pl;
    cout<<"\nVariavel real: "<<*pr;

    cout<<"\n\nModificacao da variavel inteira: ";
    cin>>n;
    cout<<"Modificacao da variavel char: ";
    cin>>l;
    cout<<"Modificacao da variavel real: ";
    cin>>r;

    cout<<"\n\nVariavel inteira: "<<*pn;
    cout<<"\nVariavel char: "<<*pl;
    cout<<"\nVariavel real: "<<*pr;
}
