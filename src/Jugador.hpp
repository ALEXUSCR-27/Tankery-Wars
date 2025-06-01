#ifndef JUGADOR_HPP
#define JUGADOR_HPP
#include <stdlib.h>
#include <string>
#include "Tanque.hpp"

using namespace std;
class Jugador {
    private:
    string aNombre;
    Tanque *aTank;
    int aTurnos;
    int aEspecial;
    public:
    Jugador() {
        aTurnos = 0;
        aEspecial = 0;
    }

    void SetTank(Tanque *Tanque) {
        aTank = Tanque;
    }

    void SetTurnos(int turnos) {
        aTurnos = turnos;
    }
    void SetNombre(string nombre) {
        aNombre = nombre;
    }

    Tanque *GetTank() {
        return aTank;
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