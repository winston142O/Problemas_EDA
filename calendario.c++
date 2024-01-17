/*
Escriba un programa que imprima un calendario dado el año, el calendario debe incluir 12 meses, y los días de la semana deben comenzar en un día correcto del año, si es su decisión puede iniciar que la semana empiece en Domingo o Lunes, pero debe imprimir los días verticalmente, y los meses horizontales. Recuerde verificar si es año bisiesto. Ejemplo:

DICIEMBRE (2023)
L   M  M  J  V  S  D
             1  2  3
4   5  6   7  8  9 10
11 12 13 14 15 16 17
18 19 20 21 22 23 24
25 26 27 28 29 30 31
*/

#include <iostream>
#include <iomanip>
using namespace std;

string meses[] = {
    "Enero",
    "Febrero",
    "Marzo",
    "Abril",
    "Mayo",
    "Junio",
    "Julio",
    "Agosto",
    "Septiembre",
    "Octubre",
    "Noviembre",
    "Diciembre"
};

int calcularCodigoSiglo(int n, int k, int l) {
    if (n > l) {
        return k;
    } 
    else {
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

int calcularPrimerDia(int year) {
    int m = 0;
    if (esBisiesto(year)) {
        m = 6;
    }
    // retorna dia de la semana para 1/1/year
    return (1 + m + (year % 100) + ((year % 100)/4) + calcularCodigoSiglo(0, 8, year)) % 7;
}

int calcularDiasEnMes(int month, int year) {
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else if (month == 2) {
        return (esBisiesto(year)) ? 29 : 28;
    } else {
        return 31;
    }
}

void lineaDivisora(string str) {
    for (int i = 1; i < str.length(); i++) {
        cout << "-";
    }
    cout << endl;
}

void mostrarCalendario(int year, int primerDia) {
    string encabezado = "  D   L   M   M   J   V   S  ";                           
    cout << "------------" << year << "-------------" << endl;    
    for (int mes = 0; mes < 12; mes++) {
        cout << meses[mes] << endl;
        lineaDivisora(encabezado);
        cout << encabezado << endl;
        int diasMes = calcularDiasEnMes(mes, year);
        int c = 0;
        // setw == padding
        if (mes == 0) {
            for (int i = 0; i < primerDia + 1; i++) {
                cout << setw(4) << " "; 
                c++;
            }
        }
        for (int dia = 1; dia <= diasMes; dia++) {
            cout << setw(3) << right << dia << " "; 
            c++;
            if (c == 7 || dia == diasMes) {
                cout << endl;
                c = 0;
            }
        }
        lineaDivisora(encabezado);
        cout << endl;               
    }
}

int main() {    
    cout << "Introduzca el año: ";    
    int year; cin >> year;  
    int primerDia = calcularPrimerDia(year);
    mostrarCalendario(year, primerDia);
    return 0;
}
