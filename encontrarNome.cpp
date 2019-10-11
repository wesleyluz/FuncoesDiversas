#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

int main (){
	string search; // string que eu vou procurar
	int offset; // inteiro por algum motivo que eu não sei
	string line; // aqui é cada  linha do arquivo

	ifstream Myfile; // meu arquivo

	if (!Myfile){
		cout << "ERROR";
		exit(1);
	}

	while(!Myfile.eof()){ // enquanto meu arquivo não chega ao final
		getline(Myfile,line); // pegando cada linha do arquivo
			if((offset = line.find(search,0)) != string :: npos){ 
				cout << "FOUNDED"<< endl;
			}else{
				cout<< "NOT FOUNDED"<<endl;
			}
	}

	Myfile.close();
}
