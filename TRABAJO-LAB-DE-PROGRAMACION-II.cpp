#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

void setColor(int color) {
    cout << "\033[" << color << "m";
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
	}
	
	return 0;
}