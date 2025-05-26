#ifndef JUGADOR_HPP
#define JUGADOR_HPP
#include <stdlib.h>
#include <string>
#include "Tanque.hpp"

using namespace std;
class Jugador {
    private:
    string aNombre;
    Tanque *aTanque;
    int aTurnos;
    int aEspecial;
    public:
    Jugador() {
        aTurnos = 0;
        aEspecial = 0;
    }

    void SetTanque(Tanque *tanque) {
        aTanque = tanque;
    }

    void SetTurnos(int turnos) {
        aTurnos = turnos;
    }
    void SetNombre(string nombre) {
        aNombre = nombre;
    }

    Tanque *GetTanque() {
        return aTanque;
    }
    int GetTurnos() {
        return aTurnos;
    }
    string GetNombre() {
        return aNombre;
    }

    int GetEspecial() {
        return aEspecial;
    }

    void SetEspecial(int n) {
        aEspecial = n;
    }

};
#endif