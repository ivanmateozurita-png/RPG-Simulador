#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Personaje.h"
#include <cstdlib>

// HERENCIA
class Enemigo : public Personaje {
private:
    string tipoMonstruo;

public:
    Enemigo(string _nombre, int _salud, int _fuerza, string _tipo) 
        : Personaje(_nombre, _salud, _fuerza), tipoMonstruo(_tipo) {}

    // Sobrescritura de método (Polimorfismo)
    void atacar(Personaje* objetivo) override {
        // 20% de probabilidad de fallar el ataque
        if (rand() % 100 < 20) {
            cout << nombre << " (" << tipoMonstruo << ") ha tropezado y fallo su ataque.\n";
        } else {
            cout << nombre << " (" << tipoMonstruo << ") ataca salvajemente causando " << fuerza << " de dano.\n";
            objetivo->recibirDano(fuerza);
        }
    }
};

#endif
