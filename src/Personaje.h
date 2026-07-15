#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>
#include <iostream>

using namespace std;

// CLASE BASE ABSTRACTA
class Personaje {
protected:
    // Encapsulamiento
    string nombre;
    int salud;
    int fuerza;

public:
    Personaje(string _nombre, int _salud, int _fuerza) : nombre(_nombre), salud(_salud), fuerza(_fuerza) {}
    virtual ~Personaje() {}

    // Getters y Setters
    string getNombre() const { return nombre; }
    int getSalud() const { return salud; }
    void setSalud(int _salud) { salud = _salud; }
    int getFuerza() const { return fuerza; }

    bool estaVivo() const { return salud > 0; }
    void recibirDano(int dano) {
        salud -= dano;
        if (salud < 0) salud = 0;
    }

    // Método virtual puro (Polimorfismo)
    virtual void atacar(Personaje* objetivo) = 0;
};

#endif
