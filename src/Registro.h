#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>
#include <fstream>
#include <iostream>
#include <ctime>

using namespace std;

class Registro {
public:
    static void guardarPuntuacion(const string& nombreJugador, bool victoria) {
        ofstream archivo("registro_partidas.txt", ios::app);
        if (archivo.is_open()) {
            time_t now = time(0);
            char* dt = ctime(&now);
            
            string resultado = victoria ? "VICTORIA" : "DERROTA";
            archivo << "Fecha: " << dt;
            archivo << "Jugador: " << nombreJugador << " | Resultado: " << resultado << "\n";
            archivo << "-------------------------------------------\n";
            archivo.close();
            cout << "\n[SISTEMA] Partida guardada en registro_partidas.txt exitosamente.\n";
        } else {
            cout << "[ERROR] No se pudo abrir el archivo de registro.\n";
        }
    }
};

#endif
