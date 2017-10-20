#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "papi.h"
#include <algorithm>
const int M = 1024;

int code_to_be_measured(const double *A, const double *B, double *C);

int main(int argc, char **argv)
{
 
  // declaracion de las matrices a usar, modeladas como 1D


  
  
  /*  int Amatrix[M*M];
  int Bmatrix[M*M];
  int Cmatrix[M*M];*/
  double *Amatrix= NULL;
  Amatrix = new double [M*M];
  double *Bmatrix= NULL;
  Bmatrix = new double [M*M];
    double *Cmatrix= NULL;
  Cmatrix = new double [M*M];
  
  // Inicializacion de las matrices

  for(int ii=0;ii<M;ii++)
      {
	for(int jj=0;jj<M;jj++)
	  {
	    Amatrix[ii*M+jj]=1.5+ii+jj;
	  }
      }

  for(int ii=0;ii<M;ii++)
      {
	for(int jj=0;jj<M;jj++)
	  {
	    Bmatrix[ii*M+jj]=1.5+ii+jj;	 
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
  
  code_to_be_measured(Amatrix,Bmatrix,Cmatrix);
  
  if((retval=PAPI_flops( &real_time, &proc_time, &flpops, &mflops))<PAPI_OK)
    {
      std::cout<<retval<<std::endl;
      exit(1);
    }
  
  std::cout<<"Tamano de matriz: "<<M<<" Real_time: "<<real_time<<" Proc_time: "<<proc_time<<" Total_flops: "<<flpops<<" MFLOPS: "<<mflops<<std::endl;
  
  return 0;
}
int code_to_be_measured(const double *A, const double *B, double *C)
{
  // multiplicacion sencilla de matrices
  for (int ii = 0; ii < M; ii++)
    {
      for (int jj = 0; jj < M; jj++)
	{
	  for (int kk = 0; kk < M; kk++)
	    {
	      C[ii * M + jj] = C[ii * M + jj] + A[ii * M + kk] * B[kk * M + jj];

	    }
	}
    }
  return 0;
}
  
