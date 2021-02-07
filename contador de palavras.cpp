#include<iostream>
#include<string.h>

using namespace std;

int main(){

char *text,**palavras;
int tam,i,j,n=50;
int cont_p=1;
int cont;

text=new char[200];

cout<<"digite o texto"<<endl;
cin.getline(text,n);
n=strlen(text);//tamanho do vetor text

//conta o numero de palavras
for(i=0;i<n;i++){
    if(text[i]==' ')
        cont_p++;
}

cout<<"total de palavras:"<<cont_p<<endl;
palavras=new char*[cont_p];
char *aux;
//colocar a palavras no vetor de palavras
palavras[0]=text;
for(i=1;i<cont_p;i++){
    palavras[i]=(strstr(text," ")+1);
    aux=strstr(text," ");
    aux[0]='\n';
}
//substituir \n
for(i=0;i<n;i++){
    if(text[i]=='\n'){
            text[i]='\0';
    }
}

//comparar
for(i=0;i<cont_p;i++){

    int flag=0;
    cont=1;
    for(j=i-1;j>=0;j--){
        if((strcmp(palavras[i],palavras[j]))==0)
            flag=1;
    }
    if(flag!=1){
     for(j=i+1;j<(cont_p-1);j++){
        if(strcmp(palavras[i],palavras[j])==0)
           cont++;
     }
     cout<<palavras[i]<<" :"<<cont<<endl;
    }

}

}

