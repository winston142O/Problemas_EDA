/*
Dado un numero entero, convertirlo en binario y hexadecimal. 
*/

#include <iostream>
#include <string> 
using namespace std;

string Binario(int n) {
    if (n < 2) {
        return to_string(n);
    }
    string res = Binario(n/2);
    return res + (n%2 ? "1":"0");
}
string Hexadecimal(int numero) {
    char hexDigits[] = "0123456789ABCDEF";
    string hexadecimal = "";
    while (numero != 0) {
        int remainder = numero % 16;
        hexadecimal = hexDigits[remainder] + hexadecimal;        
        numero /= 16;
    }    
    return hexadecimal;
}
int main()
{
    int n;
    cout << "introduzca un numero entero:" << endl;
    cin >> n;
    string binario = Binario(n);
    string hexa = Hexadecimal(n);
    cout << "convertido a binario: " << binario << endl;
    cout << "convertido a hexadecimal: " << hexa << endl;
    return 0;
}