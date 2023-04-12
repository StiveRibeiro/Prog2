#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int p1, p2, i, t;
int vet[10];

void troca(){
    t = vet[p2-1];
    vet[p2-1] = vet[p1-1];
    vet[p1-1] = t;
}

int main(){
    cout<<"Digite os 10 numeros(inteiros) do vetor: \n";
    for(i = 0; i < 10; i++){
        cout<<"Posicao "<<i+1<<": ";
        cin>>vet[i];
    }
    cout<<"Digite as posicoes que serao trocadas.\n";
    cout<<"Primeira posicao: ";
    cin>>p1;
    cout<<"Segunda posicao: ";
    cin>>p2;

    troca();

    cout<<"Vetor resultante: \n";
    for(i = 0; i< 10; i++){
        cout<<vet[i]<<" ";
    }

    return 0;
}
