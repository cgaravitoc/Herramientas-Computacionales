#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int N = 9;

    vector<double> A(N * N);

    //LLeno arreglo unidimensional tamaño N*N
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i + N * j] = j + 1;
        }
    }

    //Imprimo arreglo en forma de matriz
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i + N * j];
        }
        cout << endl;
    }

    cout << endl;

    //Pasos para la transpuesta de matriz
    vector<double> At(N * N);
    int blocksize = 5;

    for (int i = 0; i < N; i += blocksize) {
        for (int j = 0; j < N; j += blocksize) {
            // transpose the block beginning at [i,j]
            for (int k = i; k < min(N, i + blocksize); ++k) {
                for (int l = j; l < min(N, j + blocksize); ++l) {
                    At[k + l * N] = A[l + k * N];
                }
            }
        }
    }

    //Imprimo la transpuesta
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << At[i + N * j];
        }
        cout << endl;
    }

    return 0;
}

