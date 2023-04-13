#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

float n1, n2, n3, med;
char op;

void media(){
    if(op == 'a'){
    med = (n1 + n2 + n3)/3;
    cout<<"Media aritmetica="<<med;
    }
    else if(op == 'p'){
    med = (5*n1 + 3*n2 + 2*n3)/10;
    cout<<"Media ponderada="<<med;
    }
    else{
        cout<<"Opcao invalida.\n\n";
    }
}

int main(){
    cout<<"Digite as notas a para calcular a media:\n";
    cout<<"Primeira nota: ";
    cin>>n1;
    cout<<"Segunda nota: ";
    cin>>n2;
    cout<<"Terceira nota: ";
    cin>>n3;

    cout<<"Digite [p] para media ponderada ou [a] para media aritmetica: ";
    cin>>op;

    media();
}
