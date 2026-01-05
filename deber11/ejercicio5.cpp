#include <iostream>
#include <string>

using namespace std;

int contarPalabras(string texto) {
    if (texto.empty()) return 0;
    
    int contador = 0;
    bool enPalabra = false;

    for (size_t i = 0; i < texto.length(); i++) {
        if (texto[i] != ' ') {
            if (!enPalabra) {
                contador++;
                enPalabra = true;
            }
        } else {
            enPalabra = false;
        }
    }
    return contador;
}

int main() {
    string frase;
    cout << "Ingrese una frase: ";
    getline(cin, frase);

    int cantidad = contarPalabras(frase);
    cout << "La frase tiene " << cantidad << " palabras." << endl;

    return 0;
}