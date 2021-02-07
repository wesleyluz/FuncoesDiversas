#include<iostream>
#include<string.h>

using namespace std;

int main(){
    char *text,*aux,**frases,*aText;
    int i,j,k,cont;
    int cont_f,flag,tam,p=1;

    text=new char[200];
    aText=new char[200];

    cout<<"digite o texto,digite close para encerrar o texto"<<endl;
    cin.getline(text,200);
    while(p){
        cin.getline(aText,200);
        tam=strlen(text);//tamanho do vetor text
        strcat(text,aText);

        if((strcmp(aText,"close"))==0){
            p=0;
        }
    }
    //contar o numero de frases
    cont=0;
    for(i=0;i<strlen(text);i++){
        if(text[i]=='.'){
            cont++;
        }
    }
    frases=new char*[cont];
   //pegar trechos de text
   frases[0]=text;
   k=1;
   while((strstr(text,"."))!='\0') {

        frases[k]=(strstr(text,".")+1);
        aux=strstr(text,".");
        aux[0]='\n';
        k++;
   }
   //quebrando a text
   for(i=0;i<tam;i++){
        if(text[i]=='\n'){
            text[i]='\0';
        }
   }
   //comparar strings
   for(i=0;i<cont;i++){
        cont_f=1;

        if((strcmp(frases[i],""))!=0){
            for(j=i+1;j<(cont-1);j++){
               if(strcmp(frases[i],frases[j])==0){
                   cont_f++;
                   strcpy(frases[j],"");
                }
            }

        cout<<"a frase: "<< frases[i] <<" repete: " <<cont_f<<endl;
        }

   }

   delete[]text;
   delete[]aText;
}
