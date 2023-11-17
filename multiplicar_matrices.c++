#include <iostream>
using namespace std;

const int SIZE = 3;

void multiplicarMatrices(int mat1[SIZE][SIZE], int mat2[SIZE][SIZE], int res[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            res[i][j] = 0;
            for (int k = 0; k < SIZE; ++k) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void mostrarMatriz(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int mat1[SIZE][SIZE] = {
        {1, 2, 0},
        {3, 2, -1}, 
        {5, 1, -2}
        };
    int mat2[SIZE][SIZE] = {
        {3, 4, 0}, 
        {1, 0, -2}, 
        {-1, 2, 1}
        };
    int res[SIZE][SIZE];

    multiplicarMatrices(mat1, mat2, res);

    cout << "Matrix 1:" << endl;
    mostrarMatriz(mat1);

    cout << "\nMatrix 2:" << endl;
    mostrarMatriz(mat2);

    cout << "\Resultado:" << endl;
    mostrarMatriz(res);

    return 0;
}
