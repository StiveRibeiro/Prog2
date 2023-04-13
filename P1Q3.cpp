#include <iostream>

using namespace std;

int n, i;

int fibo(int n){
    if((n == 1)||(n == 0)){
        return (n);
    }
    else{
        return (fibo(n-1)+fibo(n-2));
    }
}

int main(){
    cout<<"Digite a quantidade de termos da sequencia: ";
    cin>>n;

    while(i < n){
        cout<<", "<<fibo(i);
        i++;
    }
}
