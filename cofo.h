#ifndef _COFO_H_
#define _COFO_H_
#define TRUE 1
#define FALSE 0
#define ERRO 8555523
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _cofo_{
    int maxCav;
    int nCav;
    int cur;
    void **cavs;
}Cofo;

typedef struct _Cavaleiros_{
    char *nome;
    int id;
    int vit;
    float alt;
    char *signo;
}Cavaleiros;

#ifdef _cofo_c_
    Cofo *cofCreate(int n);
    int cofInsert(Cofo *c,void* caval);
    void *cofRemoveLast(Cofo *c);
    void *cofRemoveFirst(Cofo *c);
    int cofDestroy(Cofo *c);
    void* cofQuery(Cofo *c,void *key,void *key2);
    int cmpSigno(void *key,void *caval);
    int cmpNome(void *key,void *caval);
    void imprimirCavaleiros(Cavaleiros *c1);
    void imprimirCofo(Cofo *c);
    int cofRemove(Cofo *c,void *key,void *key2);
    int RemoveAll(Cofo *c);
#else
    extern Cofo *cofCreate(int n);
    extern int cofInsert(Cofo *c,void* caval);
    extern void *cofRemoveLast(Cofo *c);
    extern void *cofRemoveFirst(Cofo *c);
    extern int cofDestroy(Cofo *c);
    extern void* cofQuery(Cofo *c,void *key,void *key2);
    extern int cmpSigno(void *key,void *caval);
    extern int cmpNome(void *Key,void *caval);
    extern void imprimirCavaleios(Cavaleiros *c1);
    extern void imprimirCofo(Cofo *c);
    extern int cofRemove(Cofo *c,void *key,void *key2);
    extern int RemoveAll(Cofo *c);
#endif
#endif // _cofo_h_


 