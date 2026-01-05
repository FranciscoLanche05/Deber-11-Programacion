#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct PocionMagica {
    string nombre;
    vector<string> ingredientes;
    int tiempo;
    string efecto;
};

void buscarIngrediente(vector<PocionMagica>& libro, string ingrediente) {
    cout << "\nPociones que usan '" << ingrediente << "':" << endl;
    for (size_t i = 0; i < libro.size(); i++) {
        for (size_t j = 0; j < libro[i].ingredientes.size(); j++) {
            if (libro[i].ingredientes[j] == ingrediente) {
                cout << "- " << libro[i].nombre << endl;
                break;
            }
        }
    }
}

int main() {
    vector<PocionMagica> libroPociones;

    PocionMagica p1;
    p1.nombre = "Pocion de Invisibilidad";
    p1.ingredientes.push_back("Ojo de triton");
    p1.ingredientes.push_back("Luz de luna");
    p1.tiempo = 30;
    p1.efecto = "Te hace invisible";
    libroPociones.push_back(p1);

    PocionMagica p2;
    p2.nombre = "Elixir de la Verdad";
    p2.ingredientes.push_back("Ojo de triton");
    p2.ingredientes.push_back("Pluma de fenix");
    p2.tiempo = 45;
    p2.efecto = "Obliga a decir la verdad";
    libroPociones.push_back(p2);

    PocionMagica p3;
    p3.nombre = "Filtro de Amor";
    p3.ingredientes.push_back("Petalos de rosa");
    p3.ingredientes.push_back("Polvo de hada");
    p3.tiempo = 20;
    p3.efecto = "Enamoramiento instantaneo";
    libroPociones.push_back(p3);

    string busqueda;
    cout << "Ingresa un ingrediente para buscar: ";
    getline(cin, busqueda);

    buscarIngrediente(libroPociones, busqueda);

    return 0;
}