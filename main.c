#ifndef _MAIN_C_
#define _MAIN_C_
#include "cofo.h"


int main(void){
    Cofo *c = NULL;
    Cavaleiros *c1;
    Cavaleiros *res6;
    char *signo;
    int stat,stat2,stat3;
    int res,res3,verif;
    char *nome;
    nome = (char*)malloc(sizeof(char*)*100);
    signo = (char*)malloc(sizeof(char*)*100);
    int opc=1,n,i;
        do{
            printf("[1] - Criar sala\n\n");
            printf("[2] - Excluir sala\n\n");
            printf("[3] - Inserir aluno\n\n");
            printf("[4] - Consultar \n\n");
            printf("[5] - Remover aluno\n\n");
            printf("[6] - Lista \n\n");
            printf("[0] - Sair  Program\n\n");
            scanf("%d",&opc);
            switch(opc){
                case 1:
                    if(c==NULL){
                        printf("Digite o tamanho:\n");
                        scanf("%d",&n);
                        if(n>0){
                            c = cofCreate(n);
                            if(c!=NULL){
                            //printf("\nSua equipe de cavaleiros de  ouro foi criada com sucesso.\n\n");
                            }else{
                            printf("Não foi possível criar\n");
                            }
                        }else{
                            printf("insira um tamanho maior que zero.\n");
                        }
                    }else{
                     
                    }
                        fflush(stdin);
                    break;
                case 2:
                    if(c!=NULL){
                        stat3 = RemoveAll(c);
                        if(stat3==TRUE){
                            stat2 = cofDestroy(c);
                            if(stat2 == TRUE){
                                c = NULL;
                                printf("\nA sua sala foi aniquilada com sucesso.\n");
                            }else{
                                printf("\nDesculpe.A sua sala nao foi possivel de ser excluida.\n\n");
                            }
                        }
                    }else{
                        printf("\nNao existe equipe para destruir.\n\n");
                    }
                    fflush(stdin);
                    break;
                case 3:
                    c1 = (Cavaleiros*)malloc(sizeof(Cavaleiros));
                    c1->nome = (char*)malloc(sizeof(char)*100);
                    c1->signo = (char*)malloc(sizeof(char)*100);
                    if(c!=NULL){
                        if(c1!=NULL){
                            if(c->nCav<c->maxCav){
                                printf("Digite a nome do aluno:\n");
                                scanf("%s",(c1->nome));
                                fflush(stdin);
                                printf("Digite a idade:\n");
                                scanf("%d",&(c1->id));
                                fflush(stdin);
                                printf("Digite o numero de artigos publicados:\n");
                                scanf("%d",&(c1->vit));
                                fflush(stdin);
                                printf("Digite a altura:\n");
                                scanf("%f",&(c1->alt));
                                fflush(stdin);
                                printf("Digite o prato favorito:\n");
                                scanf("%s",(c1->signo));
                                fflush(stdin);
                                verif = cmpSigno((void*)c1->signo,(void*)c1);
                                stat = cofInsert(c,(void*)c1);
                                if(stat == TRUE){
                                      printf("\n:::: Os elementos do aluno foram inseridos na colecao ::::\n\n");
                                      imprimirCavaleiros(c1);
                                }else{
                                      printf("Os elementos do aluno nao conseguiram ser inseridos.\n");
                                }
                            }else{
                                printf("A sua equipe ja foi totalmente preenchida.\n\n");
                            }
                        }
                    }else{
                        printf("A equipe que voce quer inserir esta vazia.\n");
                    }

                    fflush(stdin);
                    break;
                case 4:
                    if(c!=NULL){
                        printf("Digite o signo do aluno a ser consultado:\n");
                        scanf("%s",signo);
                        fflush(stdin);
                        printf("Digite o nome do aluno a ser consultado:\n");
                        scanf("%s",nome);
                        fflush(stdin);
                        res6 = cofQuery(c,(void*)signo,(void*)nome);
                        if(res6 != NULL){
                            printf("\n ::::O aluno foi encontrado ::::\n\n");
                            imprimirCavaleiros(res6);
                        }else{
                            printf("\n ::::O aluno informado nao esta dentro da sala:::: \n\n");
                        }
                    }else{
                        printf("Nao existe sala para consultar aluno.\n\n");
                    }
                    fflush(stdin);
                    break;
                case 5:
                    if(c!=NULL){
                        printf("Digite o prato favorito do aluno a ser removido:\n");
                        scanf("%s",signo);
                        printf("Digite a nome do aluno a ser removido:\n");
                        scanf("%s",nome);
                        res3 = cofRemove(c,(void*)signo,(void*)nome);
                        if(res3 == TRUE){
                            printf("\n :::: o aluno foi removido ::::\n\n");
                        }else{
                                printf("\n ::::o aluno nao foi removido, pois não foi encontrado:::: \n");
                        }
                    }else{
                        printf("\n:::: Nao existe equipe para remover aluno ::::\n");
                    }
                    fflush(stdin);
                    break;
                case 6:
                    if(c!=NULL){
                        if(c->nCav>0){
                            imprimirCofo(c);
                        }else{
                            printf("\n:::: Nao tem alunos ::::\n\n");
                        }
                    }else{
                        printf("\n:::: Nao existe sala para listar ::::\n\n");
                    }
                    fflush(stdin);
                    break;
                default:
                    i=0;
                    if(opc!=0){
                      printf("Opcao invalida, o que quer fazer aluno?\n");
                    }
                    fflush(stdin);
                    break;
            }
        }while(opc!=0);
        printf("Obrigado .\n");
}


#endif // _main_c_
