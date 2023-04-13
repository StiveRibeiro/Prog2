#include <iostream>

using namespace std;

int fatorial(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}

void troca(int a[], long FATS[], int e){
    int i;
    for(i = 0; i < e; i++){
        FATS[i] = fatorial(a[i]);
    }

}

int main(){
    int a[10], i;
    long FATS[10];

    cout<<"Digite apenas numeros naturais: "<<endl;
    for(i=0;i<10;i++){
        cout<<"Numero "<<i+1<<": ";
        cin>>a[i];
    }
    troca(a, FATS, 10);

    cout<<"Fatoriais: ";
    for(i=0;i<10;i++){
        cout<<FATS[i]<<" | ";
    }
}
