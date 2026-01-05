#include <iostream>
#include <string>
#include <vector>

using namespace std;

void analizarChats(string chats[], int tam) {
    vector<string> horas;
    vector<string> usuarios;
    vector<string> mensajes;
    int countRoberto = 0;
    int countBelen = 0;

    for (int i = 0; i < tam; i++) {
        string linea = chats[i];
        
        size_t primerSep = linea.find("//");
        string hora = linea.substr(0, primerSep);
        
        size_t segundoSep = linea.find("//", primerSep + 2);
        string usuario = linea.substr(primerSep + 2, segundoSep - (primerSep + 2));
        
        string mensaje = linea.substr(segundoSep + 2);

        horas.push_back(hora);
        usuarios.push_back(usuario);
        mensajes.push_back(mensaje);

        cout << "Hora: " << hora << " | Usuario: " << usuario << " | Msj: " << mensaje << endl;

        if (usuario == "Roberto") countRoberto++;
        if (usuario == "Belen") countBelen++;
    }

    cout << "\nReporte Total:" << endl;
    cout << "Mensajes de Roberto: " << countRoberto << endl;
    cout << "Mensajes de Belen: " << countBelen << endl;
}

int main() {
    string chat[] = {
        "08:15//Roberto//Hola perdida, como estas?",
        "08:17//Belen//Bien, gracias. Y tu?",
        "08:20//Roberto//Aqui pensandote. Quieres salir al cine hoy?",
        "08:21//Belen//Tu novia, si te da permiso?",
        "08:22//Roberto//Cual novia?. Es una amiga nomas",
        "08:23//Roberto//mejor tu pide permiso a tu novio?"
    };

    analizarChats(chat, 6);

    return 0;
}