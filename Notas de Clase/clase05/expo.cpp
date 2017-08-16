#include<iostream>
#include<cmath>
int factorial(int n);
double fniave(double x, int N);
double fsmart(double x, int N);

/*
double ingresaValor(){
  std:: cout<<"Introduce un número x : ";
  std:: cin>>x;
  std:: cout << "ingrese el limite de la suma: ";
  std:: cin >> n;
  return x,n;
  }*/

int main(void){
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  double x= 4.2;
  for (int NMAX=0;NMAX<=100; ++NMA){
    std::cout << NMAX << "\t" << fsmart(x, NMAX) << std::endl;
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
