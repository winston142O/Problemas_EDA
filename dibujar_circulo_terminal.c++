#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


const int MAX_WIDTH = 80;
const int MAX_HEIGHT = 25;


/*
implementacion windows


#include <windows.h>
void gotoxy(int x,int y)
{
HANDLE hcon;
hcon = GetStdHandle(STD_OUTPUT_HANDLE);
COORD dwPos;
dwPos.X = x;
dwPos.Y= y;
SetConsoleCursorPosition(hcon,dwPos);
}
*/


// implementacion linux/mac
void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}


void dibujarCirculo(int radio) {
    for (float a = 0.0; a < 360.0; a += 0.1) {
        float x = radio * cos(a);
        float y = radio * sin(a);
        // dibujar en el centro de la pantalla
        int shiftedX = x + MAX_WIDTH / 2;
        int shiftedY = y + MAX_HEIGHT / 2;
        // revisar que este en el rango de la pantalla
        if (shiftedX >= 0 && shiftedX < MAX_WIDTH && shiftedY >= 0 && shiftedY < MAX_HEIGHT) {
            gotoxy(shiftedX, shiftedY);
            std::cout << "*";
        }
    }
}


int main() {
    int radio;
    std::cout << "Ingrese el radio del circulo: ";
    std::cin >> radio;
    // revisar que este en el rango de la pantalla
    if (radio > MAX_WIDTH / 2 || radio > MAX_HEIGHT / 2) {
        std::cout << "El radio es demasiado grande para la pantalla.\n";
        return 1;
    }
    dibujarCirculo(radio);
    return 0;
}
