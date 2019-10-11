#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//===>>> Funções para "empurrar" grande quantidade de dados para o arquivo

// 1) read (char *, int); {ifstream}
// 2) write(char *, int);{ofstream}

//<<<===


int main (){
	char * texto = {"texto"};

	ofstream Saida("Arq.dat");

	saida.write(texto, strlen(texto));

	saida.close();

}

//--------------------------------------------//
typedef _csv_{
	int a;
	char nome[10];
	float c;

}csv;

int main (){
	csv *linha;
	int tamanho = 5;

	linhas = new csv[5];
	.
	.
	.
	. ///{spoiler do trabalho (algo com getline, e ; ou , para identificar )}
	.
	.
	.

	//supondo que eu saiba o tamanho do arquivo;
	ofstream saida ("arq.dat");
	saida.write((char*) linha, tamanho * sizeof(csv));

	//1
	ifstream entrada("arq.dat");
	entrada.read((char *) linhas, tamanho * sizeof(csv));

	//2
	ifstream entrada("arq.dat"); // função que lê todo o arquivo
		csv elemento;

		while(entrada.good()){
			entrada.read((char *) elemento, sizeof(csv));
			cout << csv.a <<"\n";		
	}

	//3 ===> coloca o ponteiro no final do arquivo (caso eu não saiba o tamanho do arquiv[maior parte dos casos])
	ifstream entrada("arq.dat");
	entrada.seekg(0, entrada,0);

	int tam = entrada.tellg()/sizeof(csv);

	entrada.seekg(0, entrada.beg);

	csv *novo = new csv[tamanho];
	entrada.read((char *)) novo, tamanho * sizeof(csv);


}

