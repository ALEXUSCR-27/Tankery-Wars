#ifndef TANQUE_HPP
#define TANQUE_HPP
#include <stdlib.h>
#include <string>
using namespace std;

class Tanque {
    private:
        string aNombre;
        int aVida;
        int aDano;
        int aPosicion;
        int aEspecial;
    public:
        Tanque (string nombre,int vida, int dano) {
            aNombre = nombre;
            aVida = vida;
            aDano = dano;
            aPosicion = 0;
            aEspecial = 0;
        }

        void SetVida(int vida) {
            aVida = vida;
        }

        void SetDano(int dano) {
            aDano = dano;
        }

        void SetPosicion(int posicion) {
            aPosicion = posicion;
        }

        string GetNombre() {
            return aNombre;
        }

        int GetVida() {
            return aVida;
        }

        int GetDano() {
            return aDano;
        }

        int GetPosicion() {
            return aPosicion;
        }
        int GetEspecial() {
            return aEspecial;
        }

        void SetEspecial(int n) {
            aEspecial = n;
        }
    
};


#endif
