#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
 cout<< "criar um novo arquivo especial\n";
 FILE *pArq1, *pArq2;
 char nome1[20], nome2[20];
 cout<<"informe o nome do primeiro arquivo:";
 cin>>nome1;
 cout<<"informe o nome do segundo arquivo :"; 
 cin>>nome2;
 pArq1 = fopen(nome1,"r");
 if(pArq1 == NULL){
    cout<<"erro ao abrir o arquivo"<<nome1<<endl;
    return(EXIT_FAILURE);
 }
 pArq2 = fopen(nome2,"w");
 if(pArq2 == NULL){
    cout<<"erro ao abrir o arquivo"<<nome2<<endl;
    return (EXIT_FAILURE);
 }
 char caracter=' ';
 while (caracter != EOF){
    caracter = tolower (getc(pArq1));
    if(isalpha(caracter)){
        if(caracter == 'a' || caracter=='e'||caracter =='i'|| caracter=='o' ||caracter =='u'){
         fputc('*',pArq2);
        }else
        fputc(caracter,pArq2);
    }
    else
     fputc(caracter , pArq2);
 }
 fclose(pArq1);
 fclose(pArq2);
 cout<<"fim do programa"<<endl;
 return 0;
}