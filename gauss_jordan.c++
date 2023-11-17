#include <iostream>

using namespace std;

const int SIZE = 3;

void gaussJordan(double mat[SIZE][SIZE * 2]) {
    for (int i = 0; i < SIZE; ++i) {
        double divisor = mat[i][i];
        for (int j = 0; j < SIZE * 2; ++j) {
            mat[i][j] /= divisor;
        }

        for (int k = 0; k < SIZE; ++k) {
            if (k != i) {
                double factor = mat[k][i];
                for (int j = 0; j < SIZE * 2; ++j) {
                    mat[k][j] -= factor * mat[i][j];
                }
            }
        }
    }
}

void displayMatrix(double matrix[SIZE][SIZE * 2]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = SIZE; j < SIZE * 2; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    double mat[SIZE][SIZE * 2] = {{1, 2, 0, 1, 0, 0}, {3, 2, -1, 0, 1, 0}, {5, 1, -2, 0, 0, 1}};

    gaussJordan(mat);

    cout << "Inverse Matrix:" << endl;
    displayMatrix(mat);

    return 0;
}
