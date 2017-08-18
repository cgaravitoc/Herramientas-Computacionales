#include<iostream>
#include<cstdlib>
typedef float REAL; //Define REAL como una variable de tipo long double
//El primer argumento de la funcion main() es el nombre del archiv y el segundo un dato digitado por teclado en terminal al ejecutar el archivo i.e. ./archivo.out 4
int main(int argc, char **argv){
  int N = std:: atoi(argv[1]);
  REAL under = 1.0, over = 1.0; // under y over son varibles de tipo long double
  for(int ii = 0; ii < N; ++ii){
    under /= 2.0;
    over *=2.0;
    std::cout << ii << "\t"
	      << under << "\t"
	      << over << "\n";
  }
  
}
