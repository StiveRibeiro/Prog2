#include <iostream>
#include <math.h>
using namespace std;

int n = 0, s, m, h;

int main(){
    cout<<"Insira o tempo em segundos: ";
    cin>>s;

    if(0<s && s<60){
        cout<<s<<"segundos";
    }
    else if(60<=s && s<1200){
        m = s/60;
        s = s - (m * 60);
        cout<<m<<"min e "<<s<<"seg.";
    }
    else {
        h = s/1200;
        s = s - (h * 1200);
        m = s/60;
        s = s - (m * 60);
        cout<<h<<"horas, "<<m<<"min e "<<s<<"seg.\n\n";
    }
}
