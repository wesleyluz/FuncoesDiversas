#include <iostream>

using namespace std;

int main() {
	int i,n0,n1,n2,n;
	n1 = 0;
	n2 = 1;
	cout << "Série de Fibonacci\n";
	cout << "Quantos termos?\n";
	cin >> n;
	if (n<=0){
		return 0;
	}
	else {
		if (n==1) cout << n1<<" ";
		else{
			cout <<n1<<" "<< n2<<" ";
			for (i=3; i<=n; i++) {
				cout <<n1+n2<<" ";
        n0 = n1;
				n1 = n2;
				n2 = n0+n2;
			}	
		}	
	}
}