#include <iostream>
#include <string>

using namespace std;

struct Vehiculo {
    string marca;
    string modelo;
    int anio;
};

void ingresarVehiculos(Vehiculo vehiculos[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << "Vehiculo " << i + 1 << endl;
        cout << "Marca: ";
        cin >> vehiculos[i].marca;
        cout << "Modelo: ";
        cin >> vehiculos[i].modelo;
        cout << "Anio: ";
        cin >> vehiculos[i].anio;
    }
}

void mostrarMasReciente(Vehiculo vehiculos[], int tam) {
    int indiceMasReciente = 0;
    for (int i = 1; i < tam; i++) {
        if (vehiculos[i].anio > vehiculos[indiceMasReciente].anio) {
            indiceMasReciente = i;
        }
    }
    cout << "\nVehiculo mas reciente:" << endl;
    cout << "Marca: " << vehiculos[indiceMasReciente].marca << endl;
    cout << "Modelo: " << vehiculos[indiceMasReciente].modelo << endl;
    cout << "Anio: " << vehiculos[indiceMasReciente].anio << endl;
}

int main() {
    Vehiculo listaVehiculos[5];
    ingresarVehiculos(listaVehiculos, 5);
    mostrarMasReciente(listaVehiculos, 5);
    return 0;
}