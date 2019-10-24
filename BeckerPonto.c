#include <stdio.h>
main ()
{
	float quant, cust, total1, total2, total3, media1, media2;
	int num, tipo, nc1, nc2;
	nc1 = 0;
	nc2 = 0;
	total1 = 0;
	total2 = 0;
	total3 = 0;
	printf ("Entre com o numero do consumidor:");
	scanf ("%i", &num);
		while (num!=0){ 
			printf ("Entre com o  Kw/m:");
				scanf ("%d", &quant);
					printf ("Entre com o tipo de consumidor:");
						scanf ("%i",&tipo);
		if (tipo==1){
			cust = (quant*0.3);     
				nc1 = nc1 + 1;
					total1 = total1 + quant;
		}else if (tipo==2){
			cust = (quant * 0.5);
				nc2 = nc2 + 1;       
					total2 = total2 + quant;     
		}else{
			cust = (quant * 0.7);       
				total3 = total3 + quant;}
		}//while
		printf ("O custo total desse consumidor é: ",cust);    
	
	scanf ("%i", &num);
	printf("O total de consumo de consumidores do tipo 1 é: ",total1);
	printf("O total de consumo de consumidores do tipo 2 é: ",total2);   
	printf("O total de consumo de consumidores do tipo 3 é: ",total3);   
	media1 = total1 / nc1;   
	media2 = total2 / nc2;   
	printf("A média de consumo do consumo de tipo 1 é: ",media1);   
	printf("A média de consumo do consumo de tipo 2 é: ",media2); 		
}
	
	
	
	
	
