#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Estudiante {
    int id;
    string nombre;
    string carrera;
    float promedio;
};

void registrarEstudiante(vector<Estudiante>& lista) {
    Estudiante e;
    cout << "ID: "; cin >> e.id;
    cin.ignore();
    cout << "Nombre: "; getline(cin, e.nombre);
    cout << "Carrera: "; getline(cin, e.carrera);
    cout << "Promedio: "; cin >> e.promedio;
    lista.push_back(e);
}

void listarEstudiantes(const vector<Estudiante>& lista) {
    for (size_t i = 0; i < lista.size(); i++) {
        cout << lista[i].id << " - " << lista[i].nombre << " - " << lista[i].promedio << endl;
    }
}

void buscarEstudiante(const vector<Estudiante>& lista) {
    int id;
    cout << "Ingrese ID a buscar: "; cin >> id;
    for (size_t i = 0; i < lista.size(); i++) {
        if (lista[i].id == id) {
            cout << "Encontrado: " << lista[i].nombre << ", Carrera: " << lista[i].carrera << endl;
            return;
        }
    }
    cout << "No encontrado." << endl;
}

void actualizarEstudiante(vector<Estudiante>& lista) {
    int id;
    cout << "Ingrese ID a actualizar: "; cin >> id;
    for (size_t i = 0; i < lista.size(); i++) {
        if (lista[i].id == id) {
            cin.ignore();
            cout << "Nuevo Nombre: "; getline(cin, lista[i].nombre);
            cout << "Nueva Carrera: "; getline(cin, lista[i].carrera);
            cout << "Nuevo Promedio: "; cin >> lista[i].promedio;
            return;
        }
    }
    cout << "No encontrado." << endl;
}

void eliminarEstudiante(vector<Estudiante>& lista) {
    int id;
    cout << "Ingrese ID a eliminar: "; cin >> id;
    for (size_t i = 0; i < lista.size(); i++) {
        if (lista[i].id == id) {
            lista.erase(lista.begin() + i);
            cout << "Eliminado." << endl;
            return;
        }
    }
}

vector<Estudiante> obtenerAprobados(const vector<Estudiante>& lista) {
    vector<Estudiante> aprobados;
    for (size_t i = 0; i < lista.size(); i++) {
        if (lista[i].promedio >= 14.0) {
            aprobados.push_back(lista[i]);
        }
    }
    return aprobados;
}

int main() {
    vector<Estudiante> estudiantes;
    int op;
    do {
        cout << "\n1.Registrar 2.Listar 3.Buscar 4.Actualizar 5.Eliminar 6.Ver Aprobados 0.Salir: ";
        cin >> op;
        if (op == 1) registrarEstudiante(estudiantes);
        else if (op == 2) listarEstudiantes(estudiantes);
        else if (op == 3) buscarEstudiante(estudiantes);
        else if (op == 4) actualizarEstudiante(estudiantes);
        else if (op == 5) eliminarEstudiante(estudiantes);
        else if (op == 6) {
            vector<Estudiante> apr = obtenerAprobados(estudiantes);
            cout << "--- Aprobados ---" << endl;
            listarEstudiantes(apr);
        }
    } while (op != 0);
    return 0;
}