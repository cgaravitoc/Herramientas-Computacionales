#include<iostream>
#include<cmath>
int factorial(int n);
double fniave(double x, int N);
double fsmart(double x, int N);

int main(void){
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  double x= 4.2;
  for (int NMAX=0;NMAX<=100; ++NMAX){
    std::cout << NMAX
	      << "\t" << fsmart(x, NMAX)
	      << "\t" << fabs(fsmart(x,NMAX) - std::exp(-x))/std::exp(-x)
	      << std::endl;
  }
  return 0;
}

double fnaive(double x, int N){
  double term =0, suma =0;
  for (int k=0; k<=N;++k){
    term = std::pow(-x,k)/factorial(k);
    suma += suma;
  }
  return suma;
}

int factorial(int n){
  if (n <= 0) return 1;
  return n*factorial(n-1);
}

double fsmart(double x, int N){
  double term =1, suma=1;
  for(int k=0; k<N; ++k){
    term *= (-x)/(k+1);
    suma += term;
  }
}

/*
GNUPLOT
en terminal
plot "datos.dat" u 1:3  w lp // grafica tabla de datos 1vs3
plot "datos.dat" u 1:3 w lp, "datos2.dat" u 1:3 w lp, // grafica dos tablas de datos provenientes de dos archivos distintos. Separando por comas se pueden graficar varias tablas de datos.

************para simplificar la sintaxis en terminal
plot for [val in "0 1 2"] "datos".val.".dat" u 1:3 w lp

**********para exportar a pdf
set xlabel "N"
set ylabel "%"
set term "pdf" //imprime en ua terminal de pdf. 
set out "figura.pdf"
plot ...
set term x11 // regresa a la terminal normal
set out "null.pdf"
okular figura.pdf
*/
