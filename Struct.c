#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

/*10. Utilizando uma estrutura, faça um programa que permita a entrada de nome, endereço e telefone de 5 pessoas e os imprima em ordem alfabética.*/


typedef struct{
	char nome[30];
	char endereco[30];
	long int tel;
}Pessoa;

void Mostrar(int n,Pessoa* pessoa){
	for(int i=0;i<n;i++){
		printf("##################################\n");
		printf("Nome: %s\n",pessoa[i].nome);
		printf("Endereço: %s\n",pessoa[i].endereco);
		printf("Telefone: %ld\n",pessoa[i].tel);
		printf("##################################\n");	
	}
}

//int IsLast(Pessoa *pessoa){
//	if(pessoa==NULL){
//		return true;
//	}
//	return false;
//}


int main(){
	Pessoa *pessoa;
	pessoa = (Pessoa*)malloc(sizeof(Pessoa)*2);
	for(int i=0;i<2;i++){
		printf("Digite o nome da %dº pessoa: ",i+1);
		scanf("%[^\n]",pessoa[i].nome);
		setbuf(stdin, NULL);
		printf("Digite o endereço da %dº pessoa: ",i+1);
		scanf("%[^\n]",pessoa[i].endereco);
		setbuf(stdin, NULL);
		printf("Digite o telefone da %dº pessoa: ",i+1);
		scanf("%ld",&pessoa[i].tel );
		setbuf(stdin, NULL);
	}

	Mostrar(2,pessoa);

	Pessoa* aux;
	aux = (Pessoa*)malloc(sizeof(Pessoa)*2);
	for(int i=0;i<2;i++){
		//if(IsLast(&pessoa[i+1])==true){
		//	printf("sadas");
		//	break;
		//}
		for(int j=0;j<strlen(pessoa[i].nome);j++){
			if(pessoa[i].nome[j]>pessoa[i+1].nome[j]){
				aux[i] = pessoa[i];
				pessoa[i] = pessoa[i+1];
				pessoa[i+1] = aux[i];
				break;
			}
		}
		Mostrar(2,pessoa);
		printf("\n");
	}
	//printf("\n");
	//Mostrar(2,pessoa);
	return 0;
}