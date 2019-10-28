#include<iostream>
#include<string.h>

using namespace std;

int main(){

    char *text,*aux,*txt;
    int tam;

    text=new char[200];
    txt=new char[200];

    cout<<"digite uma frase"<<endl;
    cin.getline(text,200);

    cout<<"digite uma frase2"<<endl;
    cin.getline(txt,200);

    tam=strlen(text);

    aux=strtok(text,txt);

    while(aux !=NULL){
    cout<<aux;
        aux=strtok(NULL,txt);
    }
}
