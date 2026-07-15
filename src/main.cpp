#include <iostream>
#include <ctime>
#include "Heroe.h"
#include "Enemigo.h"
#include "Registro.h"

using namespace std;

void limpiarConsola() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    srand(time(0));
    
    cout << "=======================================\n";
    cout << "      SIMULADOR RPG (C++ Edition)      \n";
    cout << "=======================================\n\n";

    string nombreJugador;
    cout << "Ingresa el nombre de tu Heroe: ";
    getline(cin, nombreJugador);

    // Polimorfismo mediante punteros
    Personaje* heroe = new Heroe(nombreJugador, 100, 25, 3);
    Personaje* enemigo = new Enemigo("Dragon de las Sombras", 120, 18, "Dragon");

    cout << "\nUn " << enemigo->getNombre() << " ha aparecido!\n";
    
    while (heroe->estaVivo() && enemigo->estaVivo()) {
        cout << "\n---------------------------------------\n";
        cout << heroe->getNombre() << " - HP: " << heroe->getSalud() << "\n";
        cout << enemigo->getNombre() << " - HP: " << enemigo->getSalud() << "\n";
        cout << "---------------------------------------\n";
        cout << "1. Atacar\n";
        cout << "2. Usar Pocion (Curar)\n";
        cout << "Elige tu accion: ";
        
        int opcion;
        cin >> opcion;
        cout << "\n";

        limpiarConsola();

        if (opcion == 1) {
            heroe->atacar(enemigo);
        } else if (opcion == 2) {
            // Hacemos un cast dinámico para usar un método específico de Heroe
            Heroe* h = dynamic_cast<Heroe*>(heroe);
            if (h) h->usarPocion();
        } else {
            cout << "Opcion invalida. Pierdes el turno por distraerte.\n";
        }

        // Turno del enemigo
        if (enemigo->estaVivo()) {
            cout << "\n--- Turno del Enemigo ---\n";
            enemigo->atacar(heroe);
        }
    }

    bool victoria = false;
    cout << "\n=======================================\n";
    if (heroe->estaVivo()) {
        cout << "¡VICTORIA! Has derrotado al enemigo.\n";
        victoria = true;
    } else {
        cout << "HAS MUERTO... El enemigo prevalece.\n";
    }
    cout << "=======================================\n";

    Registro::guardarPuntuacion(nombreJugador, victoria);

    // Liberar memoria
    delete heroe;
    delete enemigo;

    cout << "\nPresiona ENTER para salir...";
    cin.ignore();
    cin.get();

    return 0;
}
