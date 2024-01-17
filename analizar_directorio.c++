/*
Escribir un programa que muestre todos los archivos en un directorio y muestre información sobre dichos archivos.
*/

#include <iostream>
#include <cstring>
#include <ctime>
#include <dirent.h>
#include <sys/stat.h>

using namespace std;
void mostrarArchivosYTamanos(const string& directorio) {
    DIR* dir = opendir(directorio.c_str());
    if (dir != nullptr) {
        struct dirent* elemento;
        while ((elemento = readdir(dir)) != nullptr) {
            if (elemento->d_type == DT_REG) {  // Verificar si es un archivo regular
                string nombreArchivo = elemento->d_name;
                // Construir la ruta completa del archivo
                string rutaCompleta = directorio + "/" + nombreArchivo;
                // Obtener la información del archivo (tamaño)
                struct stat st;
                if (stat(rutaCompleta.c_str(), &st) == 0) {
                    time_t timestamp = st.st_mtime;
                    struct tm* fecha = localtime(&timestamp);
                    // Usar strftime para formatear la fecha y hora
                    char buffer[80];
                    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", fecha);
                    cout << "Archivo: " << nombreArchivo << ", Tamano: " << st.st_size << " bytes, Ultima modificacion: " << buffer << endl;
                } else {
                    cerr << "Error al obtener informacion del archivo " << nombreArchivo << endl;
                }
            }
        }
        closedir(dir);
    } else {
        cerr << "Error al abrir el directorio " << directorio << endl;
    }
}

int main() {
    string directorio;
    cout << "Introduce la ruta del directorio: ";
    cin >> directorio;
    mostrarArchivosYTamanos(directorio);
    return 0;
}
