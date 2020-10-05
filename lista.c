#ifndef _lista_c_
#define _lista_c_
#include "lista.h"

Sllist *sllCreate(){//CIRAR LISTA
  Sllist *l;
  l = (Sllist*)malloc(sizeof(Sllist));
  if(l!=NULL){
    l->first = NULL;//papel de GOD
    return l;
  }
  return NULL;
}

int cmpPlaca(void *key,void *elem){//COMPARANDO A PLACA
   long int ik = (long int)key;
   Carro *Aelem = (Carro*)elem;
   if(ik==Aelem->placa){
        return TRUE;
    }else{
        return FALSE;
    }
}

int cmpMarca(void *key,void *elem){//COMPARANDO A MARCA
  char *ik = (char*)key;
  Carro *Aelem = (Carro*)elem;
  if(strcmp(ik,Aelem->marca)==0){
    return TRUE;
  }else{
    return FALSE;
  }
}

void *sllQuery(Sllist *l,void *key,void *key2){//ENCONTRAR ELEMENTO DENTRO DA LISTA
  SllNode *aux;
  int stat,stat2;
  if(l!=NULL){
    if(l->first!=NULL){  
      aux = l->first;
      while(aux!=NULL){
        stat = cmpPlaca(key,(void*)aux->data);
        stat2 = cmpMarca(key2,(void*)aux->data);
        if(stat==TRUE && stat2==TRUE){
          return aux->data;
        }
        aux = aux->next;
      }
    }
  }
  return NULL;
}

int sllDestroy(Sllist *l){//DESTRUIR A LISTA
  if(l!=NULL){
    if(l->first==NULL){
      free(l);
      return TRUE;
    }
  }
  return FALSE;
}

int RemoveAll(Sllist *l){
	if(l!=NULL){
		l->first = NULL;
		return TRUE;
	}else{
		return FALSE;
	}
}

int sllInsertFirst(Sllist *l,void *elem){//INSERIR COMO PRIMEIRO ELEMENTO
  SllNode *newnode;//criando novo no para elementos
  if(l!=NULL){
    newnode = (SllNode*)malloc(sizeof(SllNode));
    if(newnode!=NULL){
      newnode->data = elem;
      newnode->next = l->first;
      for(int i=0;i<=3;i++){
	      printf("\n");
	      for(int j=0;j<i;j++){
		      printf("#");
	      }
	  
      }
    }
      l->first = newnode;
      return TRUE;
    }
  }
  return FALSE;
}

int sllInsertLast(Sllist *l,void *elm){//INSERIR ELEMENTO NA ULTIMA POSIÇÃO
  SllNode *aux;
  SllNode *res;
  if(l!=NULL){
    res = (SllNode*)malloc(sizeof(SllNode));
    if(res!=NULL){
      aux = l->first;
      if(l->first!=NULL){
        while(aux->next!=NULL){
          aux = aux->next;
        }
        res->data = elm;
        res->next = NULL;
        aux->next = res;
      }else{
        sllInsertFirst(l,elm);
      }
      return TRUE;     
    }
  }
  return FALSE;
}

void *sllRemoveSpec(Sllist *l,void *key,void *key2){//REMOVER UM ESPECIFICO
  SllNode *prev,*prox,*aux;
  void *data;
  int stat,stat2;
  if(l!=NULL){
    if(l->first!=NULL){
      prev = NULL;
      aux = l->first;
      prox = aux->next;
      stat = cmpMarca(key,aux->data);
      stat2 = cmpPlaca(key2,aux->data);
      while(stat!=TRUE && stat2!=TRUE){
        prev = aux;
        aux = aux->next;
        stat = cmpMarca(key,aux->data);
        stat2 = cmpPlaca(key2,aux->data);
      }
      if(stat==TRUE && stat2==TRUE){
		if(prev!=NULL){
			prev->next = aux->next;
		}else{
			l->first = aux->next;
		}
		data = aux->data;
		free(aux);
		return data;
      }
    }
  }
  return NULL;
}

void imprimirCarro(Carro *c1){//IMPRIMIR A ESTRUTURA DO CARRO
  if(c1!=NULL){
    printf("Placa:%ld\nPotencia:%d\nPreco:%.2f\nNumero de Portas:%d\nMarca:%s\n------------------------\n",c1->placa,c1->pot,c1->preco,c1->nPortas,c1->marca);
    }
}

void imprimirLista(Sllist *l){//IMPRIMIR A LISTA
  SllNode *aux;
  if(l!=NULL){
    aux = l->first;
    while(aux->next!=NULL){
      imprimirCarro((Carro*)aux->data);
      aux = aux->next;
    }
	imprimirCarro((Carro*)aux->data);
  }
}
#endif