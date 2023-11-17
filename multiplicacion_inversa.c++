#include <iostream>
using namespace std;

int numeroInverso(int num) {
    int inverso = 0;
    while (num > 0) {
        inverso = (num % 10) + (inverso * 10);
        num /= 10;
    }
    return inverso;
}

int main() {
    cout << "Introduzca el numero a multiplicar: " << endl;
    int input; cin >> input;    
    cout << "Numero: " << input << endl;
    int inverso = numeroInverso(input);
    cout << "Inverso: " << inverso << endl;
    int resultado = input * inverso;
    cout << resultado << endl;
    return 0;
}
