#include<iostream>
#include<cmath>


int signo(int n);
int factorial(int n);
double fnaive(double x, int N);

int main(){
  std::cout.precision(8);
  std::cout.setf(std::ios::scientific);
  double x=0.1;
   std::cout << "N"
	     << "\t" << "Valor calculado"
	     << "\t" << "valor real"
	     << std::endl;
   for(int NMAX=1; NMAX<=100; ++NMAX){
     std::cout << NMAX
	       << "\t" << fnaive(x, NMAX)
	       << "\t" << sin(x)
	       << std::endl;
   }
   return 0; 
}


double fnaive(double x, int N){
  double term=x, suma =x;
  for (int k=1; k<=N; ++k){
    term *=-(x/(2*k+1))*(x/2*k) ;
    suma += term;
  } 
  return suma;
}
