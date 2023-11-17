#include <iostream>
using namespace std;

void Espacios(int n) {
    for (int i = 0; i < n; i++) {
        cout << " ";
    }
}

void MuestraRombo(int f) {
    int i = 0;
    for (int x = 0; x < f; x++) {
        int k;
        if (x < (f / 2)) {
            k = f / 2 - x;
        }
        else {
            k = x - f / 2;
        }

        Espacios(k);

        int suc = 2 * i + 1;
        for (int y = 0; y < 2 * suc; y++) {
            cout << "*";
            if (y == suc - 1) {
                Espacios(2 * k);
            }
        }

        if (x < (f / 2)) {
            i++;
        }
        else {
            i--;
        }

        cout << endl;
    }
}

int main() {
    int f;
    cout << "Ingrese un valor entero positivo para el tamaño del rombo: ";
    cin >> f;

    if (f % 2 == 0) {
        cout << "El tamaño del rombo debe ser un número impar." << endl;
    }
    else {
        MuestraRombo(f);
    }

    return 0;
}