#include<iostream>

int main(){
  std::cout<< "*********int***********" << "\n";
  int intunder =1000;
  int intover =1000;
  int N=10000;
  for(int i=1;i<=N;i++){
    intunder=intunder+1;
    intover=intover-1;
    std::cout << i << "\t" <<  intunder  << "\t" << intover << "\n" ;
  }
  std::cout<< "*********double***********"<< "\n";
  double doubleunder =1;
  double doubleover =1;
  for(int i=1;i<=N;i++){
    doubleunder=doubleunder/2;
    doubleover=doubleover*2;
    std::cout << i << "\t" <<  doubleunder  << "\t" << doubleover << "\n" ;
  }
  std::cout<< "*********logdouble***********" << "\n" ;
  long double ldoubleunder =1;
  long double ldoubleover =1;
  for(int i=1;i<=N;i++){
    ldoubleunder=ldoubleunder/2;
    ldoubleover=ldoubleover*2;
    std::cout << i << "\t" <<  ldoubleunder  << "\t" << ldoubleover << "\n" ;
  }
  return 0;
}
