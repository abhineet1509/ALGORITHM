#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int** mat;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        mat = new int*[rows];
        for (int i = 0; i < rows; ++i)
            mat[i] = new int[cols];
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i)
            delete[] mat[i];
        delete[] mat;
    }

    void getMatrix() {
        cout << "Enter elements for a " << rows << "x" << cols << " matrix:\n";
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j) {
                cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
                cin >> mat[i][j];
            }
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            cout << "Matrix multiplication not possible due to size mismatch.\n";
            exit(EXIT_FAILURE);
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j) {
                result.mat[i][j] = 0;
                for (int k = 0; k < cols; ++k)
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
            }
        return result;
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    int r1, c1, r2, c2;

    cout << "Enter rows and columns for the first matrix: ";
    cin >> r1 >> c1;
    Matrix matrix1(r1, c1);
    matrix1.getMatrix();

    cout << "Enter rows and columns for the second matrix: ";
    cin >> r2 >> c2;
    Matrix matrix2(r2, c2);
    matrix2.getMatrix();

    if (c1 != r2) {
        cout << "Error: The number of columns in the first matrix must equal the number of rows in the second matrix.\n";
        return 1;
    }

    Matrix result = matrix1 * matrix2;

    cout << "The resulting matrix is:\n";
    result.display();

    return 0;
}
