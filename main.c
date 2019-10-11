#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int lerMatriz(char letra,int stat,int **matriz){
	if(letra=='/'){
		return matriz[stat][0];
	}else if(letra == '*'){
		return matriz[stat][1];
	}else{
		return matriz[stat][2];
	}
}

int main(void) {
	int **matriz,stat,newstat;
	int i=0,j=0;
	int aceita=21;
	matriz = (int**)malloc(sizeof(int*)*4*4);
	for(int i=0;i<4;i++){
		matriz[i]=(int*)malloc(sizeof(int));
	}
	char *frase,letra,*frase1;
	frase = (char*)malloc(sizeof(char));
	frase1 = (char*)malloc(sizeof(char));
	if(frase!=NULL){
		scanf("%s",frase);

		if(matriz!=NULL){

			matriz[0][0] = 1;
			matriz[0][1] = 9;
			matriz[0][2] = 9;
			matriz[0][3] = 0;
			matriz[1][0] = 9;
			matriz[1][1] = 2;
			matriz[1][2] = 9;
			matriz[1][3] = 0;
			matriz[2][0] = 2;
			matriz[2][1] = 3;
			matriz[2][2] = 2;
			matriz[2][3] = 0;
			matriz[3][0] = 9;
			matriz[3][1] = 9;
			matriz[3][2] = 9;
			matriz[3][3] = 12;

			stat=0;

			letra = frase[i];

			while(aceita!=12 && stat!=9){
				//printf("%d\n",stat);
				newstat = lerMatriz(letra,stat,matriz);
			//	printf("to aqui");
				if(newstat!=9){
					frase1[j]=letra;
					j++;
					
					i++;

					letra = frase[i];
					frase1[j]=letra;

					
					if(letra == '/' && frase[i-1] == '*'){
						aceita = 12;
					}

					//printf("Aqui.\n");
					if(stat==4){
						printf("aqui");
						aceita = 12;
					}
				}
				stat = newstat;
			}
			
		}
	//	printf("ta aqui");
		if(aceita==12){
			
			printf("Aceita.\n");
			printf("%s\n",frase1);
			
		}else{
			printf("Não Aceita.\n");
		}

	}

}