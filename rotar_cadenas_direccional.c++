#include <iostream>
#include <string>
using namespace std;

string rotarCadena(const std::string& str, int N, char direccion) {
    int len = str.length();    
    if (N >= len) {
        cerr << "N debe ser menor al largo de la cadena." << endl;
        return str;
    }
    string rotatedStr(len, ' '); 
    for (int i = 0; i < len; ++i) {
        if (direccion == 'D') {
            rotatedStr[(i + N) % len] = str[i];
        } else if (direccion == 'I') {
            rotatedStr[(i - N + len) % len] = str[i];
        } else {
            cerr << "Dirección no válida. Use 'D' para derecha o 'I' para izquierda." << endl;
            return str;
        }
    }
    return rotatedStr;
}

int main() {
    string input;
    int n;
    char dir;

    cout << "Introduza un string: ";
    cin >> input;
    cout << "Introduzca N: ";
    cin >> n;
    cout << "Introduzca la dirección ('D' para derecha, 'I' para izquierda): ";
    cin >> dir;

    string res = rotarCadena(input, n, dir);
    cout << "Original: " << input << endl;
    cout << "Resultado: " << res << endl;

    return 0;
}
