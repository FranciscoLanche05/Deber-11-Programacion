#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Jugador {
    int id;
    string nombre;
    string posicion;
    int edad;
};

struct Equipo {
    int id;
    string nombre;
    string entrenador;
    vector<Jugador> jugadores;
};

void registrarEquipo(vector<Equipo>& liga) {
    Equipo eq;
    cout << "ID Equipo: "; cin >> eq.id;
    cin.ignore();
    cout << "Nombre Equipo: "; getline(cin, eq.nombre);
    cout << "Entrenador: "; getline(cin, eq.entrenador);
    liga.push_back(eq);
}

void agregarJugador(vector<Equipo>& liga) {
    int idEq;
    cout << "ID del equipo donde agregar: "; cin >> idEq;
    for (size_t i = 0; i < liga.size(); i++) {
        if (liga[i].id == idEq) {
            Jugador j;
            cout << "ID Jugador: "; cin >> j.id;
            cin.ignore();
            cout << "Nombre: "; getline(cin, j.nombre);
            cout << "Posicion: "; getline(cin, j.posicion);
            cout << "Edad: "; cin >> j.edad;
            liga[i].jugadores.push_back(j);
            return;
        }
    }
    cout << "Equipo no encontrado." << endl;
}

void listarEquipos(const vector<Equipo>& liga) {
    for (size_t i = 0; i < liga.size(); i++) {
        cout << "Equipo: " << liga[i].nombre << " (DT: " << liga[i].entrenador << ")" << endl;
        for (size_t k = 0; k < liga[i].jugadores.size(); k++) {
            cout << "  - " << liga[i].jugadores[k].nombre << " (" << liga[i].jugadores[k].posicion << ")" << endl;
        }
    }
}

void buscarEquipo(const vector<Equipo>& liga) {
    int id;
    cout << "ID Equipo: "; cin >> id;
    for (size_t i = 0; i < liga.size(); i++) {
        if (liga[i].id == id) {
            cout << "Encontrado: " << liga[i].nombre << endl;
            return;
        }
    }
}

void eliminarJugador(vector<Equipo>& liga) {
    int idEq, idJug;
    cout << "ID Equipo: "; cin >> idEq;
    cout << "ID Jugador a borrar: "; cin >> idJug;
    
    for (size_t i = 0; i < liga.size(); i++) {
        if (liga[i].id == idEq) {
            for (size_t k = 0; k < liga[i].jugadores.size(); k++) {
                if (liga[i].jugadores[k].id == idJug) {
                    liga[i].jugadores.erase(liga[i].jugadores.begin() + k);
                    cout << "Jugador eliminado." << endl;
                    return;
                }
            }
        }
    }
}

void filtrarPorEntrenador(const vector<Equipo>& liga) {
    string dt;
    cin.ignore();
    cout << "Nombre Entrenador: "; getline(cin, dt);
    for (size_t i = 0; i < liga.size(); i++) {
        if (liga[i].entrenador == dt) {
            cout << "Equipo: " << liga[i].nombre << endl;
        }
    }
}

void eliminarEquipo(vector<Equipo>& liga) {
    int id;
    cout << "ID Equipo a borrar: "; cin >> id;
    for (size_t i = 0; i < liga.size(); i++) {
        if (liga[i].id == id) {
            liga.erase(liga.begin() + i);
            cout << "Equipo eliminado." << endl;
            return;
        }
    }
}

int main() {
    vector<Equipo> liga;
    int op;
    do {
        cout << "\n1.Crear Equipo 2.Add Jugador 3.Listar 4.Buscar Eq 5.Del Jugador 6.Filtrar DT 7.Del Equipo 0.Salir: ";
        cin >> op;
        if (op == 1) registrarEquipo(liga);
        else if (op == 2) agregarJugador(liga);
        else if (op == 3) listarEquipos(liga);
        else if (op == 4) buscarEquipo(liga);
        else if (op == 5) eliminarJugador(liga);
        else if (op == 6) filtrarPorEntrenador(liga);
        else if (op == 7) eliminarEquipo(liga);
    } while (op != 0);
    return 0;
}