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
        cout << "Ingrese la palabra o caracter a buscar: ";
        cin >> palabraBuscar;

        int totalCoincidencias = 0;
        string linea;

        // Lee el archivo línea por línea
        while (getline(archivo, linea)) {
            string lineaMinusculas = linea;
            // Convierte la línea a minúsculas para una búsqueda sin distinción de mayúsculas/minúsculas
            for (char &c : lineaMinusculas) {
                c = tolower(c);
            }

            string palabraBuscarMinusculas = palabraBuscar;
            // Convierte la palabra a buscar a minúsculas
            for (char &c : palabraBuscarMinusculas) {
                c = tolower(c);
            }

            // Contamos todas las coincidencias en la línea
            size_t pos_contador = lineaMinusculas.find(palabraBuscarMinusculas);
            while (pos_contador != string::npos) {
                totalCoincidencias++;
                pos_contador = lineaMinusculas.find(palabraBuscarMinusculas, pos_contador + 1);
            }

            // Preparamos las posiciones para resaltar las coincidencias en la línea original
            vector<size_t> posiciones;
            size_t posicion_resaltar = lineaMinusculas.find(palabraBuscarMinusculas, 0);
            while (posicion_resaltar != string::npos) {
                posiciones.push_back(posicion_resaltar);
                posicion_resaltar = lineaMinusculas.find(palabraBuscarMinusculas, posicion_resaltar + 1);
            }

            // Imprime la línea, resaltando las coincidencias
            size_t inicio = 0;
            for (size_t i = 0; i < posiciones.size(); ++i) {
                // Imprime la parte de la línea antes de la coincidencia
                cout << linea.substr(inicio, posiciones[i] - inicio);
                // Establece el color a verde para la coincidencia
                cambiarColorTexto("verde");
                // Imprime la coincidencia
                cout << linea.substr(posiciones[i], palabraBuscar.length());
                // Restablece el color a predeterminado
                cambiarColorTexto("reset");
                // Actualiza el inicio para la siguiente parte de la línea
                inicio = posiciones[i] + palabraBuscar.length();
            }
            // Imprime el resto de la línea después de la última coincidencia
            cout << linea.substr(inicio) << endl;
        }

        archivo.close();

        // --- Cambiar el color para la parte de "total de coincidencias encontradas" ---
        // Establece el color a verde para el mensaje final
        cambiarColorTexto("verde");
        cout << "Total de coincidencias encontradas: " << totalCoincidencias << endl;
        // Restablece el color a predeterminado después del mensaje
        cambiarColorTexto("reset");
        // ------------------------------------------------------------------

        cout << "¿Desea repetir el proceso? (s/n): ";
        cin >> repetir;
    }
	
	return 0;
}