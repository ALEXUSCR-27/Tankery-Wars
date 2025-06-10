#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <stdlib.h>
#include <string>
#include "Tank.hpp"

using namespace std;
class Player {
    private:
        string aName;
        Tank *aTank;
        int aTurn;
        int aSpecial;

    public:
        Player() {
            aTurn = 0;
            aSpecial = 0;
        }

    void setTank(Tank *Tank) {
        aTank = Tank;
    }

    void setTurnos(int turnos) {
        aTurn = turnos;
    }
    void setName(string nombre) {
        aName = nombre;
    }

    Tank *getTank() {
        return aTank;
    }
    int getTurn() {
        return aTurn;
    }
    string getName() {
        return aName;
    }

    int getSpecial() {
        return aSpecial;
    }

    void setSpecial(int n) {
        aSpecial = n;
    }

};
#endif