#include<iostream>
#include<cmath>

double f_x(double x);
double q_x(double x);
double r_x(double x);

int main(){
  std::cout.precision(20);
  std::cout.setf(std::ios::scientific);
  double x=0.01, f, q, r;
  f= f_x(x);
  q= q_x(x);
  r= r_x(x);
  std::cout << "******1.CPP*********" << std::endl;
  std::cout << "f(x)"<< "\t"<< "q(x)"<< "\t"<< "r(x)" << std::endl;
  std::cout << "----_" << "\t" << "----_" << "\t" << "----" << std::endl;
  std::cout << f << "\t"<< q  << "\t"<< r  << std::endl;
 
  std::cout << "********************" << std::endl;
  return 0;
}

double f_x(double x){
  double fx= std::pow(1-x,8);
  return fx;
}

double q_x(double x){
  double qx= 1 - 8*x + 28*x*x - 56*x*x*x+70*x*x*x*x-56*x*x*x*x*x+28*x*x*x*x*x*x-8*x*x*x*x*x*x*x+x*x*x*x*x*x*x*x;
    return qx; 
}

double r_x(double x){
  double rx= 1 - 8*x + 28*std::pow(x,2)-56*std::pow(x,3)+70*std::pow(x,4)-56*std::pow(x,5)+28*std::pow(x,6)-8*std::pow(x,7)+std::pow(x,8);
  return rx;
}
