#include <stdlib.h>
#include <stdio.h>
#include <string.h>



typedef struct node{
    int dado;
    struct node *next;
    struct node *prev;
}node;

typedef struct list
{
    node *head;
    node *last;
    int qtd;
}list;


list* create_list(){
    list *l;
    l=(list*)malloc(sizeof(list));
    if(l!=NULL){
        l->head=NULL;
        l->last=NULL;
        l->qtd=0;
        return l;
    }
    return NULL;
}

node* create_node(){
    node *no;
    no=(node*)malloc(sizeof(node));
    if(no!=NULL){
        no->next=NULL;
        no->prev=NULL;
        return no;
    }
    return NULL;
}

void insert_node(node *no, int n){
    if(no!=NULL){
        no->dado=n;
    }
}


int insert_list(int n, list *l){
    if(l!=NULL){
        node *no;
        no=create_node();
        insert_node(no, n);


        if(l->head==NULL){
            l->head=no;
            l->last=no;
        }else{
            no->prev=l->last;
            l->last->next=no;
            l->last=no;
        }
        l->qtd=l->qtd + 1;

        return 1;
    }else{
        l=create_list();
        insert_list(n,l);
    }
    return 0;
}

node *search_list( int chave ,list *l){
    if (l!=NULL && l->qtd >0){
        node *aux;
        aux=l->head;

        while(aux!=NULL){
            if(aux->dado==chave){
                return aux;
            }
            aux=aux->next;
        }
        return NULL;
    }
    return NULL;
}

int remove_from_the_end( list *l){
    if (l->last!=NULL && l!=NULL){
        int chave;
        node *aux;

        chave=l->last->dado;
        if(l->qtd==1){
            l->head=NULL;
            l->last=NULL;
        }else{
            aux=l->last->prev;
            l->last=aux;
            aux->next=NULL;
        }
        l->qtd--;
        return chave;
    }
    return 0;
}

int remove_from_the_beg( list *l){
    if (l->head!=NULL && l!=NULL){
        int chave;
        node *aux;

        chave=l->head->dado;
        if(l->qtd==1){
            l->head=NULL;
            l->last=NULL;
        }else{
            aux=l->head->next;
            l->head=aux;
            aux->prev=NULL;
        }
        l->qtd--;
        return chave;
        
    }
    return 0;
}

void insert_beg(int dado, list *l){
    if (l!=NULL){
        node *no;
        no=create_node();
        insert_node(no,dado);

        if(l->head==NULL){
            l->head=no;
            l->last=no;
        }else{
            no->next=l->head;
            l->head->prev=no;
            l->head=no;
        }
        l->qtd++;
    }
}

int remove_itens(int chave, list *l){
    if (l!=NULL){
        node *aux;
        node *tmp;
        int qtd_remove=0;
        tmp=search_list(chave,l);

        while(tmp!=NULL){

            if(tmp->next==NULL){
                aux=tmp->prev;
                aux->next=NULL;
                l->last=aux;
            }else if(tmp->prev==NULL){
                aux=tmp->next;
                aux->prev=NULL;
                l->head=aux;
            }else{
                aux=tmp->prev;
                aux->next=tmp->next;
                aux=tmp->next;
                aux->prev=tmp->prev;
            }
            tmp=search_list(chave,l);
            qtd_remove++;
            l->qtd--;
        }
        return qtd_remove; 
    }
    return -1;
}

void print_list(list *l){
    if(l!=NULL){
        node *aux;
        aux=l->head;

        while(aux!=NULL){
            printf("%i - ",aux->dado);
            if(aux->prev==0){
                printf("0 - ");
            }else{
                printf("1 - ");
            }
            if(aux->next==0){
                printf("0\n");
            }else{
                printf("1\n");
            }
            aux=aux->next;
        }
        printf("Tamanho: %i\n",l->qtd);
    }
}

void print_inverted_list(list *l){
    if(l!=NULL){
        node *aux;
        aux=l->last;

        while(aux!=NULL){
            printf("%i - ",aux->dado);
            if(aux->prev==0){
                printf("0 - ");
            }else{
                printf("1 - ");
            }
            if(aux->next==0){
                printf("0\n");
            }else{
                printf("1\n");
            }
            aux=aux->prev;
        }
        printf("Tamanho: %i\n",l->qtd);
    }
}

void insert_in_pos(int pos,int dado,list *l){
    if(l!=NULL && pos>=1 && l->qtd>0){
        node *aux;
        node *aux2;
        aux=l->head;
        int i;
        node *no;
        no=create_node();
        insert_node(no,dado);

        for(i=1; i<pos; i++){
            aux=aux->next;
        }
        aux2=aux->prev;
        if(aux->prev==NULL){
            aux->prev=no;
            no->prev=NULL;
            no->next=aux;
            l->head=no;
        }else if(aux->next==NULL){
            aux->next=no;
            no->next=NULL;
            no->prev=aux;
            l->last=no;
        }else{
            no->next=aux;
            no->prev=aux2;
            aux->prev=no;
            aux2->next=no;
        }
        l->qtd++;

    }
}

void remove_by_position(int pos, list *l){
    if (l!=NULL && pos >=0 && l->qtd>0){
        node *aux;
        node *tmp;
        int i;
        tmp=l->head;
        
        for(i=1;i<pos;i++){
            tmp=tmp->next;
        }

        if(tmp->next==NULL){
            aux=tmp->prev;
            l->last=aux;
            aux->next=NULL;
        }else if(tmp->prev==NULL){
            aux=tmp->next;
            aux->prev=NULL;
            l->head=aux;
        }else{
            aux=tmp->prev;
            aux->next=tmp->next;
            aux=tmp->next;
            aux->prev=tmp->prev;
        }
        l->qtd--;
    }
}

int main(){
    list *l;
    int esc;

    l=create_list();

    while(scanf("%d",&esc)>0){
        insert_list(esc,l);
    }
    print_list(l);
    //printf("\n");
    insert_list(43,l);
    insert_list(65,l);
    print_list(l);
    //printf("\n");
    insert_beg(56,l);
    insert_beg(12,l);
    print_list(l);
    //printf("\n");
    insert_in_pos(3,10,l);
    insert_in_pos(1,15,l);
    print_list(l);
    //printf("\n");
    remove_from_the_end(l);
    remove_from_the_end(l);
    remove_from_the_end(l);
    print_list(l);
    //printf("\n");
    remove_from_the_beg(l);
    remove_from_the_beg(l);
    remove_from_the_beg(l);
    print_list(l);
    //printf("\n");
    remove_from_the_end(l);
    remove_by_position(3,l);
    print_list(l);
    //printf("\n");
    print_inverted_list(l);
    free(l);
}