#include <stdio.h>
#include <conio.h>
main(){
       int i, cont, qtd, numeros[10];
           
           
           printf("Digite a Quantidade Cosumidores que deseja Calcular: ");
           fflush(stdin);
           scanf("%d",&qtd);
           
       typedef struct { char nome[30];
                        int matricula;
                        int tipo;
                        float vlrconta, gastou;
                        }TCliente;
                        
       TCliente consumidor[qtd];
                   for(cont=0; cont < qtd; cont++){
                              
                               fflush(stdin);
                               printf("\nDigite o Nome do Cliente: ");  
                               gets(consumidor[cont].nome);   
                                 
                               fflush(stdin);                          
                               printf("\nDigite a Matricula do Cliente: "); 
                               scanf("%d",&consumidor[cont].matricula);
                               fflush(stdin);                               
                               printf("\nDigite o gasto do Cliente: "); 
                               scanf("%f",&consumidor[cont].gastou);
                               fflush(stdin);                                
                               printf("\nTipo de cliente: 1-comercial, 2-industrial, 3-residencial: ");   
                               scanf("%d",&consumidor[cont].tipo);
                                
                               }
                               
                               
                               
                              
                   for(cont = 0; cont < qtd; cont++){  
                                                            
                               printf("\n\n \n%s \n%.0d \n%.2f \n%.0d, ", consumidor[cont].nome, consumidor[cont].matricula, consumidor[cont].gastou, consumidor[cont].tipo);
                   }
                   getch();
                   
                   }
 
