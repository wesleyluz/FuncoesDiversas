#include <stdio.h>
#include <stdlib.h>

int **AlocaMatriz(int nl,int mc){
	int **matrizA,ia,ja;
	matrizA = (int**)malloc(sizeof(int*)*nl);
	if(matrizA!=NULL){
		for(ia=0;ia<nl;ia++){
			matrizA[ia] = (int*)malloc(sizeof(int)*mc);
			if(matrizA[ia]!=NULL){
				for(ja=0;ja<mc;ja++){
					scanf("%d",&matrizA[ia][ja]);
					for(ja=ia;ja>=0;ja++){
						free(matrizA[ja]);
						ia=ja;
					}
				}
				free(matrizA);
			}
		}
	}
	return matrizA;
}


int main(void) {
  int n,m,p,q;
  int **matrizA,**matrizB,**matrizC,*vetorDiag,**prodMBC;
  scanf("%d %d",&n,&m);
  scanf("%d %d",&p,&q);

  matrizA = AlocaMatriz(n,m);


}