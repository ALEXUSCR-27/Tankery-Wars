#ifndef TANK_HPP
#define TANK_HPP

#include <stdlib.h>
#include <string>

using namespace std;

class Tank {
    private:
        string aName;
        int aLife;
        int aDamage;
        int aPosition;
        int aSpecial;

    public:
        Tank (string name,int life, int damage) {
            aName = name;
            aLife = life;
            aDamage = damage;
            aPosition = 0;
            aSpecial = 0;
        }

        void setLife(int life) {
            aLife = life;
        }

        void setDamage(int damage) {
            aDamage = damage;
        }

        void setPosition(int posicion) {
            aPosition = posicion;
        }

        string getName() {
            return aName;
        }

        int getLife() {
            return aLife;
        }

        int getDamage() {
            return aDamage;
        }

        int getPosition() {
            return aPosition;
        }
        int getSpecial() {
            return aSpecial;
        }

        void setSpecial(int n) {
            aSpecial = n;
        }
};
#endif
