#include <iostream>

using namespace std;

bool isPrime(int);

int main(void){

	for(int i = 500; i <=1400; i++){
		if(isPrime(i)){cout << i << " , ";}
	}
	cout << endl;

	return 0;
}

bool isPrime(int j){

	if(i == 1){return false;}
	if(i == 2){return true;}

	for(int j = 2; i < j; j++){
		if(n%i == 0){return false;}
	}

	return true;
}
