
//Se imprime la serie limitando la suma hasta n

#include <iostream>

using namespace std;

int main(void){

	const int n = 7;

	double suma = 0;

	for(int i = 1; i <= n; i++){
		suma = suma + 1.0/i;
		cout << i << " | " << suma << endl;
	}

	return 0;
}
