#include <iostream>
using namespace std;

// Function to multiply two matrices A and B
void multiplyMatrices(int A[][10], int B[][10], int C[][10], int rowA, int colA, int colB) {
    // Initialize the resulting matrix C to zero
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            C[i][j] = 0;
        }
    }

    // Multiply the matrices
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            for (int k = 0; k < colA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int rowA, colA, rowB, colB;
    
    cout << "Enter the number of rows and columns for matrix A: ";
    cin >> rowA >> colA;
    
    cout << "Enter the number of rows and columns for matrix B: ";
    cin >> rowB >> colB;
    
    // Check if matrices can be multiplied
    if (colA != rowB) {
        cout << "Error: Matrices cannot be multiplied (column count of A must equal row count of B)." << endl;
        return -1;
    }

    int A[10][10], B[10][10], C[10][10];

    // Input matrix A
    cout << "Enter elements of matrix A:" << endl;
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colA; j++) {
            cin >> A[i][j];
        }
    }

    // Input matrix B
    cout << "Enter elements of matrix B:" << endl;
    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < colB; j++) {
            cin >> B[i][j];
        }
    }

    // Multiply matrices
    multiplyMatrices(A, B, C, rowA, colA, colB);

    // Output the resulting matrix C
    cout << "Resulting matrix C after multiplication:" << endl;
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
