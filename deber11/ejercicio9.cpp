#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Pelicula {
    int id;
    string titulo;
    string director;
    bool enCartelera;
};

void registrarPelicula(vector<Pelicula>& cine) {
    Pelicula p;
    cout << "ID: "; cin >> p.id;
    cin.ignore();
    cout << "Titulo: "; getline(cin, p.titulo);
    cout << "Director: "; getline(cin, p.director);
    cout << "En cartelera (1=Si, 0=No): "; cin >> p.enCartelera;
    cine.push_back(p);
}

void listarPeliculas(const vector<Pelicula>& cine) {
    for (size_t i = 0; i < cine.size(); i++) {
        cout << cine[i].id << " | " << cine[i].titulo << " | " 
             << (cine[i].enCartelera ? "En Cartelera" : "Fuera") << endl;
    }
}

void buscarPelicula(const vector<Pelicula>& cine) {
    int id;
    cout << "ID a buscar: "; cin >> id;
    for (size_t i = 0; i < cine.size(); i++) {
        if (cine[i].id == id) {
            cout << cine[i].titulo << " dir: " << cine[i].director << endl;
            return;
        }
    }
    cout << "No encontrada." << endl;
}

void cambiarEstado(vector<Pelicula>& cine) {
    int id;
    cout << "ID para cambiar estado: "; cin >> id;
    for (size_t i = 0; i < cine.size(); i++) {
        if (cine[i].id == id) {
            cine[i].enCartelera = !cine[i].enCartelera;
            cout << "Estado cambiado." << endl;
            return;
        }
    }
}

void eliminarPelicula(vector<Pelicula>& cine) {
    int id;
    cout << "ID a eliminar: "; cin >> id;
    for (size_t i = 0; i < cine.size(); i++) {
        if (cine[i].id == id) {
            cine.erase(cine.begin() + i);
            cout << "Eliminada." << endl;
            return;
        }
    }
}

void filtrarPorEstado(const vector<Pelicula>& cine) {
    bool estado;
    cout << "Ver (1=Cartelera, 0=Fuera): "; cin >> estado;
    for (size_t i = 0; i < cine.size(); i++) {
        if (cine[i].enCartelera == estado) {
            cout << cine[i].titulo << endl;
        }
    }
}

int main() {
    vector<Pelicula> catalogo;
    int op;
    do {
        cout << "\n1.Registrar 2.Listar 3.Buscar 4.Cambiar Estado 5.Eliminar 6.Filtrar 0.Salir: ";
        cin >> op;
        if (op == 1) registrarPelicula(catalogo);
        else if (op == 2) listarPeliculas(catalogo);
        else if (op == 3) buscarPelicula(catalogo);
        else if (op == 4) cambiarEstado(catalogo);
        else if (op == 5) eliminarPelicula(catalogo);
        else if (op == 6) filtrarPorEstado(catalogo);
    } while (op != 0);
    return 0;
}