#include<iostream>
#include<vector>

int main(void){
  const int M = 7000;
  const int N = 500;

  std::vector<double> data;
  data.resize(M*N);
  
  std::cout << data[M*N/2+M/2] << std::endl;


  return 0;
}
