#include <iostream>

using namespace std;

void llenarMatriz(int matriz[4][6]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            cout << "Ingrese dulzura (1-9) [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}

float calcularPromedio(int matriz[4][6]) {
    int suma = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            suma += matriz[i][j];
        }
    }
    return (float)suma / 24.0;
}

int main() {
    int tableta[4][6];
    llenarMatriz(tableta);
    float promedio = calcularPromedio(tableta);
    cout << "El nivel de dulzura promedio es: " << promedio << endl;
    return 0;
}