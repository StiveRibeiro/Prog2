#include <iostream>
#include <stdio.h>
using namespace std;

int VarA, VarB, *VA, *VB;

int main(){
    VA = &VarA;
    VB = &VarB;
    cout<<"Insira o valor da variavel VarA: ";
    cin>>VarA;
    cout<<"Insira o valor da variavel VarB: ";
    cin>>VarB;

    cout<<"Endereco de VarA e conteudo: "<<VA<<", "<<*VA;
    cout<<"\nEndereco de VarB e conteudo: "<<VB<<", "<<*VB;

    if(VA < VB){
        cout<<"\n\nVariavel com maior endereco e seu conteudo: "<<VB<<", "<<*VB;
    }
    else {
        cout<<"\n\nVariavel com maior endereco e seu conteudo: "<<VA<<", "<<*VA;
    }
}
