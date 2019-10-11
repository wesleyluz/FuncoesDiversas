#ifndef _lista_h_
#define _lista_h_
#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _carro_{
    char *marca;
    int pot;
    int nPortas;
    float preco;
    long int placa;
}Carro;

typedef struct _sllelm_{
  struct _sllelm_ *next;
  void *data;
}SllNode;

typedef struct _sllist_{
  SllNode *first;
}Sllist;

#ifndef _lista_c_
  Sllist *sllCreate();
  int sllInsertFirst(Sllist *l,void *elm);
  int sllDestroy(Sllist *l);
  int sllInsertLast(Sllist *l,void* elm);
  void *sllRemoveSpec(Sllist *l,void *key,void *key2);
  void imprimirCarro(Carro *c1);
  void imprimirLista(Sllist *l);
  void *sllQuery(Sllist *l,void *key,void *key2);
  int RemoveAll(Sllist *l);
#else
  extern Sllist *sllCreate();
  extern int sllInsertFirst(Sllist *l,void *elm);
  extern int sllDestroy(Sllist *l);
  extern int sllInsertLast(Sllist *l,void* elm);
  extern void *sllRemoveSpec(Sllist *l,void *key,void *key2);
  extern void imprimirCarro(Carro *c1);
  extern void imprimirLista(Sllist *l);
  extern void *sllQuery(Sllist *l,void *key,void *key2);
  extern int RemoveAll(Sllist *l);
#endif
#endif