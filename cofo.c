#ifndef _COFO_C_
#define _COFO_C_
#include "cofo.h"


Cofo *cofCreate(int n){ // Criando coleção de Cavaleiros
    Cofo *c;
    c = (Cofo*)malloc(sizeof(Cofo));
    if(c!=NULL){
        c->cavs = (void**)malloc(sizeof(void*)*n);
    }
    if(c->cavs!=NULL){
        c->nCav = 0;
        c->maxCav = n;
        c->cur = -1;
        return c;
    }else{
      free(c);
    }
    return NULL;
}

int cofInsert(Cofo *c,void* caval){  //INSERINDO CAVALEIROS DENTRO DA COLECAO
    if(c!=NULL){
        if(c->nCav<c->maxCav){
                //printf("nelms:%d//max:%d",c->nElms,c->max);
            c->cavs[c->nCav] = caval;
            c->nCav++;
            return TRUE;
        }
    }
    return FALSE;
}

int cmpSigno(void *key, void *caval) { //COMPARANDO O SIGNO
   char *ik = (char*)key;
   Cavaleiros *Acav = (Cavaleiros*)caval;
   if(strcmp(ik,Acav->signo)==0){
        return TRUE;
    }else{
        return FALSE;
    }
}

int cmpNome(void *key,void *caval){  //COMPARANDO A NOME
  char *ik = (char*)key;
  Cavaleiros *Acav = (Cavaleiros*)caval;
  if(strcmp(ik,Acav->nome)==0){
    return TRUE;
  }else{
    return FALSE;
  }
}

void* cofQuery(Cofo *c,void *key,void *key2){  //PROCURANDO O CAVALEIRO DENTRO DA COLECAO
    int i,stat,stat2;
    if(c!=NULL){
        if(c->nCav>0){
            i=0;
            while(i<c->nCav){
                stat = cmpSigno(key,c->cavs[i]);
                stat2 = cmpNome(key2,c->cavs[i]);
                if(stat==TRUE && stat2==TRUE){
                    return c->cavs[i];
                }
                i++;
            }
        }

    }
    return NULL;
}


int cofDestroy(Cofo *c){  //DESTRUIR A COLECAO DE CAVALEIROS
    if(c!=NULL){
        if(c->nCav == 0){
            free(c->cavs);
            free(c);
            return TRUE;
        }
    }
    return FALSE;
}

void imprimirCavaleiros(Cavaleiros *c1){ //IMPRIMIR A ESTRUTURA DO CAVALEIRO
    if(c1!=NULL){
        printf("Signo:%s\nIdade:%d\nAltura:%.2f\nVitorias:%d\nNome:%s\n\n------------------------\n",c1->signo,c1->id,c1->alt,c1->vit,c1->nome);
    }
}


void imprimirCofo(Cofo *c){  //IMPRIMIR O QUE ESTA DENTRO DA COLECAO
    if(c!=0){
        for(int i=0;i<c->nCav;i++){
            imprimirCavaleiros((Cavaleiros*)c->cavs[i]);
        }
    }
}


int cofRemove(Cofo *c,void *key,void *key2){  //REMOVER UM CAVALEIRO DA COLECAO
    int i,stat,stat2;
    if(c!=NULL){
        if(c->nCav>0){
            i=0;
            while(i<c->nCav){
                stat = cmpSigno(key,c->cavs[i]);
                stat2 = cmpNome(key2,c->cavs[i]);
                if(stat==TRUE && stat2==TRUE){
                    for(int j=i;j<c->nCav-1;j++){
                        c->cavs[j] = c->cavs[j+1];
                    }
                    c->nCav--;
                    return TRUE;
                }
                i++;
            }
        }

    }
    return FALSE;
}

int RemoveAll(Cofo *c){  //REMOVER TODOS OS CAVALEIROS DA COLECAO
    if(c!=NULL){
        c->nCav = 0;
        return TRUE;
    }
    return FALSE;
}

#endif // _cofo_c_