#include <iostream>
#include <cmath>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;
using Eigen::MatrixXd;

int main (){
  
  Matrix3d A;
  //= MatrixXd::Random(6,6);
  
  A << 1, 2, 3,
    4, 5, 6,
    7, 8, 9;
  
  cout << "Here is a random 6x6 matrix, A:" << endl << A << endl << endl;
  EigenSolver<MatrixXd> es(A);
  cout << "The eigenvalues of A are:" << endl << es.eigenvalues() << endl;
  cout << "The matrix of eigenvectors, V, is:" << endl << es.eigenvectors() << endl << endl;
  complex<double> lambda = es.eigenvalues()[0];
  cout << "Consider the first eigenvalue, lambda = " << lambda << endl;
  VectorXcd v = es.eigenvectors().col(0);
  cout << "If v is the corresponding eigenvector, then lambda * v = " << endl << lambda * v << endl;
  cout << "... and A * v = " << endl << A.cast<complex<double> >() * v << endl << endl;
  MatrixXcd D = es.eigenvalues().asDiagonal();
  MatrixXcd V = es.eigenvectors();
  cout << "Finally, V * D * V^(-1) = " << endl << V * D * V.inverse() << endl;
}
