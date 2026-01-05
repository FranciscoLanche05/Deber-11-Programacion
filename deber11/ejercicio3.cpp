#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void inicializarTablero(char tablero[6][6]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            tablero[i][j] = '~';
        }
    }
}

void colocarBarco(char tablero[6][6]) {
    srand(time(0));
    int fila = rand() % 6;
    int col = rand() % 4; 
    for (int k = 0; k < 3; k++) {
        tablero[fila][col + k] = 'B';
    }
}

void mostrarTablero(char tablero[6][6]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}

bool disparar(char tablero[6][6], int f, int c) {
    if (f >= 0 && f < 6 && c >= 0 && c < 6) {
        if (tablero[f][c] == 'B') {
            return true;
        }
    }
    return false;
}

int main() {
    char mar[6][6];
    inicializarTablero(mar);
    colocarBarco(mar);
    
    mostrarTablero(mar); 

    int fila, col;
    cout << "Ingrese fila (0-5) para disparar: ";
    cin >> fila;
    cout << "Ingrese columna (0-5) para disparar: ";
    cin >> col;

    if (disparar(mar, fila, col)) {
        cout << "Tocado!" << endl;
    } else {
        cout << "Agua." << endl;
    }

    return 0;
}