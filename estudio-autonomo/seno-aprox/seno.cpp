#include<iostream>
#include<cmath>


int signo(int n);
int factorial(int n);
double fnaive(double x, int N);

int main(){
  std::cout.precision(20);
  std::cout.setf(std::ios::scientific);
  double x=1;
   std::cout << "N"
	     << "\t" << "Valor calculado"
	     << "\t" << "valor real"
	     << std::endl;
   for(int NMAX=1; NMAX<=50; ++NMAX){
     std::cout << NMAX
	       << "\t" << fnaive(x, NMAX)
	       << "\t" << sin(x)
	       << std::endl;
   }
   return 0; 
}

int signo(int n){
  int j=n-1;
  if (std::pow(-1,j)>=0){
    return 1;
  }
   if (std::pow(-1,j)<=0){
    return -1;
  }
}

int factorial(int n){
if (n <= 0) return 1;
  return n*factorial(n-1);
}

double fnaive(double x, int N){
  double term=0, suma =0;
  for (int k=1; k<=N/2; ++k){
    int j= 2*k-1;
    int l= k-1;
    term = (std::pow(x,j)*std::pow(-1,l))/factorial(j);
    // std::cout << "termino " <<  term << "\n" ;
    if(term>=0){
      std::cout << "termino positivo " << "\t" << k <<  "\t" << term << std::endl;  
    }if(term<=0){
      std::cout << "termino negativo " << "\t" << k <<  "\t" << term<< std::endl;  
    }
  }
  suma += term;
   std::cout << "suma " << "\t" << term<< std::endl;  
  return suma;
}
