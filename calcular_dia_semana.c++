/*
Crear un programa el cual al introducir una fecha (ejemplo yyyy/mm/dd) te dice el dia de la semana de tal fecha.
*/

#include <iostream>
using namespace std;

string dias[] = { 
    "Domingo",
    "Lunes",
    "Martes",
    "Miercoles",
    "Jueves",
    "Viernes",
    "Sabado"
}; 

int calcularCodigoSiglo(int n, int k, int l) { 
    if (n > l) {
        return k;
    } else {
        n += 100;
        if (k < 0) {
            k = 6;
        }
        return calcularCodigoSiglo(n, k - 2, l);
    }
} 

bool esBisiesto(int n) {
    return n % 4 == 0 && (n % 100 != 0 || n % 400 == 0);
}

int codigosMeses[] = { 
    0, // Enero
    3, // Febrero
    3, // Marzo
    6, // Abril
    1, // Mayo
    4, // Junio
    6, // Julio
    2, // Agosto
    5, // Septiembre
    0, // Octubre
    3, // Noviembre
    5, // Diciembre
    6, // Enero BISIESTO
    2, // Febrero BISIESTO
};

int calcularDiaSemana(int a, int m, int d) {
    int codigo_m;
    if (esBisiesto(a)) {
        codigo_m = codigosMeses[m + 11];
    } else {
        codigo_m = codigosMeses[m - 1];
    }
    return (d + codigo_m + (a % 100) + ((a % 100) / 4) + calcularCodigoSiglo(0, 8, a)) % 7;
}

int main() {
    cout << "Introduzca el anio: " << endl;
    int year; cin >> year;
    cout << "Introduzca el # del mes: " << endl;
    int month; cin >> month;
    cout << "Introduzca el # del dia: " << endl;
    int day; cin >> day;

    cout << "El dia de la semana es: " << dias[calcularDiaSemana(year, month, day)+1] << endl;
    return 0;
}