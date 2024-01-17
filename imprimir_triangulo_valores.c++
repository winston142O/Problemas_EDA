/*
1. Crear un programa que lea 55 valores, y estos deberan presentarse en orden inverso en forma de un triangulo.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>

void generarValores(int *arr, int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    } 
}

void mostrarTrianguloValores(int *arr, int s) {
    std::sort(arr, arr + s, std::greater<int>()); 
    int numRows = static_cast<int>(std::sqrt(2 * s + 0.25) - 0.5);
    int numVals = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numRows - i - 1; j++) {
            std::cout << " ";
        }

        for (int j = 0; j < i + 1; j++) {
            std::cout << arr[numVals++] << " ";
        }

        std::cout << std::endl;
    }
}

int main() {
    int valores[52];
    generarValores(valores, 52);
    mostrarTrianguloValores(valores, 52);
    return 0;
}