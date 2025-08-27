#include <iostream>
using namespace std;

void multiplyMatrices(int A[][10], int B[][10], int C[][10], int rowA, int colA, int colB) {
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < colA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int rowA, colA, rowB, colB;
    cin >> rowA >> colA;
    cin >> rowB >> colB;
    if (colA != rowB) return -1;

    int A[10][10], B[10][10], C[10][10];
    for (int i = 0; i < rowA; i++)
        for (int j = 0; j < colA; j++)
            cin >> A[i][j];
    for (int i = 0; i < rowB; i++)
        for (int j = 0; j < colB; j++)
            cin >> B[i][j];

    multiplyMatrices(A, B, C, rowA, colA, colB);

    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
}
