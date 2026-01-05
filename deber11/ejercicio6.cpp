#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

void separarExpresion(string expresion) {
    vector<char> numeros;
    vector<char> operadores;
    vector<char> otros;

    for (size_t i = 0; i < expresion.length(); i++) {
        char c = expresion[i];
        if (isdigit(c)) {
            numeros.push_back(c);
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=') {
            operadores.push_back(c);
        } else {
            otros.push_back(c);
        }
    }

    cout << "Numeros: ";
    for (size_t i = 0; i < numeros.size(); i++) cout << numeros[i] << ", ";
    cout << "\nOperadores: ";
    for (size_t i = 0; i < operadores.size(); i++) cout << operadores[i] << ", ";
    cout << "\nOtros: ";
    for (size_t i = 0; i < otros.size(); i++) cout << otros[i] << ", ";
    cout << endl;
}

int main() {
    string expr;
    cout << "Ingrese expresion (ej: (2*3)-5=1): ";
    cin >> expr;
    separarExpresion(expr);
    return 0;
}