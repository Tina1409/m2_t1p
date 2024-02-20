//Required libraries
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib> 

using namespace std;

//Function for geneating a random matrix of N X N size
void generateRandomMatrix(int** matrix, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = rand() % 100;  
        }
    }
}
//Function for performing multiplication
void matrixMultiply(int** A, int** B, int** C, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int N;
    cout <<"Enter the size of the matrices: ";
    cin >> N;

    // Dynamically allocating memory for matrices A, B, and C
    int** A = new int*[N];
    int** B = new int*[N];
    int** C = new int*[N];
    for (int i = 0; i < N; ++i) {
        A[i] = new int[N];
        B[i] = new int[N];
        C[i] = new int[N];
    }

    // Seeding for random number generation
    srand(static_cast<unsigned>(time(0)));

    // Generating random matrices A and B
    generateRandomMatrix(A, N);
    generateRandomMatrix(B, N);

    // Performing matrix multiplication and measuring time
    clock_t start = clock();
    matrixMultiply(A, B, C, N);
    clock_t end = clock();

    // Free allocated memory
    for (int i = 0; i < N; ++i) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    
    delete[] A;
    delete[] B;
    delete[] C;

    // Displaying the time taken
    cout << "Matrix multiplication completed in "<< (double)(end - start) / CLOCKS_PER_SEC << " seconds." << endl;
    return 0;
}
