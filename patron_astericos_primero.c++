#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int size = pow(5, 2);
    int asteriscos = 0;
    int contador = 0;

    while (contador < size) {
        cout << "*";
        asteriscos++;
        if (asteriscos==sqrt(size)) {
            cout << endl;
            asteriscos = 0;
        }        
        contador++;
    }

    return 0;
}