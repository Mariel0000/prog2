#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
#include <windows.h> 

using namespace std;

// Función para cambiar el color del texto en la consola de Windows
void cambiarColorTexto(const std::string& color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    if (color == "verde") {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    } else if (color == "reset") { 
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
    } else {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
}

int main() {
    string nombreArchivo;
    string palabraBuscar;
    char repetir = 's';

    while (repetir == 's' || repetir == 'S') {
        cout << "Ingrese el nombre del archivo: ";
        cin >> nombreArchivo;

        ifstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            cerr << "Error al abrir el archivo." << endl;
            return 1;
        }

	
	return 0;
}