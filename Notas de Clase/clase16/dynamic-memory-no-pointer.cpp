#include<iostream>

int main(void){
  const int M = 7000;
  const int N = 500;
  
  double *data = nullptr;
  data = new double [M*N];
  // [id][jd] -> id*n+id
  // std::cout << data[M/2][N/2] << std::endl;
  std::cout << data[M*N/2+M/2] << std::endl;

  delete [] data;

  return 0;
}
