#include <iostream>

using namespace std;

int main() {
	int qn,i,j,k,MDC,menor;
	// qn= quantidade de numeros
	// k= usado pra saber se todos os numeros sao divisiveis por j
	MDC=1;
	
	cout << "Quantos numeros: ";
	cin >> qn;
	int n[qn];
	// n = vetor que guarda todos os numeros dados pelo usuario
	
	for (i=0; i<qn; i++){
		cout<<"numero "<<i+1<<":";
		cin >> n[i];
		
	}
	menor=n[0];
	for (i=1; i<qn; i++){
		if(n[i]<menor)
			menor =n[i];
	}
	j=1;
	while(j<=menor){
		j++;
		k=0;
		for (i=0; i<qn; i++){
			if ((n[i]%j)==0)
				k=k+1;
		}
		if (k==qn)
			MDC=j;
	}
	cout<<"MDC: "<<MDC;
	
}