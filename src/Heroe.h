#ifndef HEROE_H
#define HEROE_H

#include "Personaje.h"
#include <cstdlib>

// HERENCIA
class Heroe : public Personaje {
private:
    int pociones;

public:
    Heroe(string _nombre, int _salud, int _fuerza, int _pociones) 
        : Personaje(_nombre, _salud, _fuerza), pociones(_pociones) {}

    // Sobrescritura de método (Polimorfismo)
    void atacar(Personaje* objetivo) override {
        int dano = fuerza;
        // 30% de probabilidad de golpe crítico
        if (rand() % 100 < 30) {
            dano *= 2;
            cout << "!!! GOLPE CRITICO DE " << nombre << " !!!\n";
        }
        cout << nombre << " ataca con su espada causando " << dano << " puntos de dano.\n";
        objetivo->recibirDano(dano);
    }

    void usarPocion() {
        if (pociones > 0) {
            salud += 40;
            if (salud > 100) salud = 100;
            pociones--;
            cout << nombre << " usa una pocion. Salud restaurada a " << salud << ". Quedan " << pociones << " pociones.\n";
        } else {
            cout << "¡No te quedan pociones!\n";
        }
    }
};

#endif
