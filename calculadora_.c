#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

//PROTÓTIPOS DAS FUNÇÕES QUE SERÃO USADAS
  int menu();
  float soma();
  float multip();
  float divide();
  float subtrai();

//VARIÁVEIS GLOBAIS
     char opc;
     char tecla,total;
     float n1,n2, restult;
     int  sair,cont;

//INÍCIO DA FUNÇÃO PRINCIPAL
int main(){


    setlocale(LC_ALL, "Portuguese");



      menu();

                if (opc=='1'){
                   soma();
                  }


                        else if(opc=='2'){
                              subtrai();
                              }



                                 else if (opc=='3'){
                                       multip();
                                      }


                           else if(opc=='4'){
                                 divide();
                                }


                     else if(opc=='5')
                           exit;



               else
                  printf("\n\n OPÇÃO INVÁLIDA!!!\n");

   return 0;
}

//INÍCIO DA FUNÇÃO MENU
   int menu(){
      system("cls");


     do{
        printf("\n\n\t *** CALCULADORA *** \n\n\n");

        printf("\n\n\t    Escolha a opção: \n\n");

        printf("\n\t     SOMA:          1 \n");
        printf("\n\t     SUBTRAÇÃO:     2 \n");
        printf("\n\t     MULTIPLICAÇÃO: 3 \n");
        printf("\n\t     DIVISÃO:       4 \n");
        printf("\n\t     SAIR:          5 \n");

        scanf("%c%*c", &opc);

        }

     while(opc < '1' || opc > '5');

     getchar();

  }





//INÍCIO DA FUNÇÃO SOMA
    float soma(){

       int valores,cont;
       float result, memor, total=0;
       char guardar;
       system("cls");


            printf("\n\t\t S O M A \n\n");

            printf("\n\t--------------------\n");
            printf("\n\n\tTotal na memória:  %.2f  \n", memor);
            printf("\n\t--------------------\n");



                printf("\n\tQuantos valores você quer somar?   ");
                scanf(" %d%*c", &valores);

                        for(cont=0; cont<valores; cont++){
                           printf("\n\t %d.º valor: ", cont+1);
                           scanf("%f", &result);
                           total+=result;
                           }


                printf("\n\t--------------------");
                printf("\n\t TOTAL: %.2f \n\n", total);
                printf("\n\t--------------------");


                printf("\n\t Deseja guardar o resultado na memória? S / N \n");
                scanf(" %c", &guardar);


              if (guardar =='s'|| guardar =='S'){

                 memor+=total;
                 printf("\n\t--------------------\n");
                 printf("\n\t Total na memória: %.2f", memor);
                 printf("\n\t--------------------\n");
                }

              else {
                 memor=0;
                 printf("\n\t--------------------\n");
                 printf("\n\tTotal memória: %.2f \n", memor);
                 printf("\n\t--------------------\n");
                 fflush(stdin);
              }
        getchar();
        return menu();

}



//INÍCIO DA FUNÇÃO SUBTRAI
   float subtrai(){
       float result;
       system("cls");

               printf("\n\t SUBTRAÇÃO \n\n");
               printf("\n\t1º valor: ");
               scanf(" %f" , &n1);
               printf("\n\t2º valor: ");
               scanf(" %f" , &n2);

                printf("\n");

                  result=n1-n2;
                  printf("\n\t   Total SUBTRAÇÃO: %.2f \n", result);

     getchar();
     return menu();

  }


//INÍCIO DA FUNÇÃO MULTIP
   float multip(){
      float result;
      system("cls");


               printf("\n\t MULTIPLICAÇÃO \n\n");
               printf("\n\t1º valor: ");
               scanf(" %f" , &n1);
               printf("\n\t2º valor: ");
               scanf(" %f" , &n2);


               result=n1*n2;

               printf("\n\t  Total MULTIPLICAÇÃO: %.2f \n", result);

     getchar();
     return menu();
   }


//INÍCIO DA FUNÇÃO DIVIDE
    float divide(){
         float result;
         system("cls");


            printf("\n\t DIVISÃO \n\n");

            printf("\n\t1º valor: ");
            scanf(" %f" , &n1);

            printf("\n\t2º valor: ");
            scanf(" %f" , &n2);

            if (n2==0){
              printf("\n\tImpossível dividir por ZERO! \n");
              getchar();
            }
            else{
               result=n1/n2;
               printf("\n\t   Total DIVISÃO: %.2f \n", result);
               }
     getchar();
     return menu();

  }