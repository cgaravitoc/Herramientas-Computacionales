#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "papi.h"
#include <algorithm>
const int M = 512; //Tama�o de la matriz
const int N =1; //Tama�o del bloque

int code_to_be_measured(const int *A, const int *B);

int main(int argc, char **argv)
{
 
  // declaracion de las matrices a usar, modeladas como 1D

  int Amatrix[M*M];
  int Bmatrix[M*M];
  
  // Inicializacion de las matrices

  for(int ii=0;ii<M;ii++)
      {
	for(int jj=0;jj<M;jj++)
	  {
	    Amatrix[ii*M+jj]=1+ii+jj;
	    Bmatrix[ii*M+jj]=0;
	  }
      }

  
  // Variables de PAPI
  
  float real_time, proc_time,mflops;
  long long flpops;
  float ireal_time, iproc_time, imflops;
  long long iflpops;
  int retval;
  
  // PERFOMANCE MEASURE
  // start PAPI counters
  
  if((retval=PAPI_flops(&ireal_time,&iproc_time,&iflpops,&imflops)) < PAPI_OK)
    {

      std::cout<<"No es posible inicializar PAPI flops \n"<<std::endl;
      
      std::cout<<"Puede que su plataforma/procesador no soporte operaciones de evento flotante \n"<<std::endl;
      
      
      std::cout<<retval<<"\n"<<std::endl;
      
      
      exit(1);
    }
  
  code_to_be_measured(Amatrix,Bmatrix);
  
  if((retval=PAPI_flops( &real_time, &proc_time, &flpops, &mflops))<PAPI_OK)
    {
      std::cout<<retval<<std::endl;
      exit(1);
    }
  
  std::cout<<"Real_time: "<<real_time<<" Proc_time: "<<proc_time<<" Total_flops: "<<flpops<<" MFLOPS: "<<mflops<<std::endl;
  
  return 0;
}
int code_to_be_measured(const int *A, const int *B)
{
  // transposicion sencilla de matrices

  for (int i = 0; i < M; i += N)
    {
      for (int j = 0; j < M; j += N)
	{	  
	  for (int k = i; k < min(M, i +N); ++k)
	    {
	      for (int l = j; l < min(M, j + N); ++l)
		{
		  B[k + (l * M)] = A[l + (k * M)];
		}
	    }
	}
    }

  return 0;
}
