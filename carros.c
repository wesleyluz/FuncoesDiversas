#include "lista.h"

int main() {
  Sllist *l=NULL;
  Carro *c;
  Carro *res;
  void *remov;
  long int placa;
  char *marca;
  int verif;
  marca = (char*)malloc(sizeof(char)*100);
  int opc=1,n,i;
  do{
    printf("###################### MENU ####################\n");
    printf("[1] - criar uma lista\n");
    printf("[2] - destruir a lista\n");
    printf("[3] - inserir dados de uma estrutura do tipo T em uma lista\n");
    printf("[4] - consultar uma estrutura do tipo T identificada pelo campo F que esta na lista\n");
    printf("[5] - remover uma estrutura do tipo T identifcada pelo campo F que esta na lista\n");
    printf("[6] - listar todas as estruturas armazenadas na lista\n");
    printf("[0] - Sair do programa.\n");
    printf("#################### MENU ####################\n");
    scanf("%d",&opc);
    switch(opc){
      case 1:
        if(l==NULL){
          l = sllCreate();
          if(l!=NULL){
            printf("Sua lista foi criada com sucesso.\n");
          }else{
            printf("Nao foi possivel criar sua lista.\n");
          }
        }else{
          printf("Voce deve excluir a lista ja existente.\n");
        }
          fflush(stdin);
        break;
      case 2:
        if(l!=NULL){
			verif = RemoveAll(l);
			if(verif==TRUE){
				verif = sllDestroy(l);
				if(verif == TRUE){
					l = NULL;
					printf("Sua lista foi destruida com sucesso.\n");
				}else{
					printf("Nao foi possivel destruir sua lista.\n");
				}
			}
		}else{
			printf("Nao existe lista para destruir.\n");
		}
        break;
      case 3:
        if(l!=NULL){
          c = (Carro*)malloc(sizeof(Carro));
          if(c!=NULL){
            c->marca = (char*)malloc(sizeof(char)*100);
            if(c->marca!=NULL){
              printf("Digite a marca do carro:\n");
              scanf("%s",(c->marca));
              fflush(stdin);
              printf("Digite a potencia do carro:\n");
              scanf("%d",&(c->pot));
              fflush(stdin);
              printf("Digite o numero de portas do carro:\n");
              scanf("%d",&(c->nPortas));
              fflush(stdin);
              printf("Digite o preco do carro:\n");
              scanf("%f",&(c->preco));
              fflush(stdin);
              printf("Digite a placa do carro:\n");
              scanf("%ld",&(c->placa));
              fflush(stdin);
            }
            verif = sllInsertLast(l,(void*)c);
            if(verif==TRUE){
              imprimirCarro(c);
            }else{
              printf("Os elementos não foram inseridos.\n");
            }
          }
        }else{
          printf("Não lista para inserir elementos.\n");
        }
        break;
      case 4:
        if(l!=NULL){
          printf("Digite a placa do carro a ser pesquisado.\n");
          scanf("%ld",&placa);
          printf("Digite a marca do carro a ser pesquisado.\n");
          scanf("%s",marca);
          res = (Carro*)sllQuery(l,(void*)placa,(void*)marca);
          if(res!=NULL){
            printf("O Carro foi encontrado.\n");
            imprimirCarro(res);
          }else{
            printf("Este Carro nao esta na lista.\n");
          }
        }else{
          printf("Nao existe lista para procurar o elemento.\n");
        }
        break;
      case 5:
        if(l!=NULL){
			if(l->first!=NULL){	
				printf("Digite a placa do carro a ser removido.\n");
				scanf("%ld",&placa);
				printf("Digite a marca do carro a ser removido.\n");
				scanf("%s",marca);
				remov = sllRemoveSpec(l,(void*)marca,(void*)placa);
				if(remov!=NULL){
					imprimirCarro(remov);
					printf("O elemento foi removido.\n");
				}
			}else{
				printf("Nao tem elementos na lista.\n");
			}
		}else{
			printf("Nao tem elementos na lista.\n");
		}
        break;
      case 6:
        if(l!=NULL){
			if(l->first!=NULL){
          		imprimirLista(l);
			}else{
				printf("Nao tem elementos para imprimir.\n");
			}
        }else{
          printf("Nao tem lista para imprimir.\n");
        }
        break;
    }
  }while(opc!=0);
}
       
