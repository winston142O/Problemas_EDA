#include <iostream>
#include <string>
using namespace std;

string rotarCadena(const std::string& str, int N) {
    int len = str.length();    
    if (N >= len) {
        cerr << "Error: N debe ser menor al largo de la cadena." << endl;
        return str;
    }
    string rotatedStr(len, ' '); 
    for (int i = 0; i < len; ++i) {
        rotatedStr[(i + N) % len] = str[i];
    }
    return rotatedStr;
}

int main() {
    string input;
    int n;

    cout << "Introduza un string: ";
    cin >> input;
    cout << "Introduzca N: ";
    cin >> n;

    string res = rotarCadena(input, n);
    cout << "Original: " << input << endl;
    cout << "Resultado: " << res << endl;

    return 0;
}
