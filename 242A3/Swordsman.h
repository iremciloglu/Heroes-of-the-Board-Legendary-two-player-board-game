#pragma once
#ifndef SWORDSMAN_H
#define SWORDSMAN_H
#include "Melee.h"
using namespace std;
class Swordsman : public Melee {
private:
    int damage_per_hit;
public:
    Swordsman();
    Swordsman(int, char, int, char, int);
    void setDamagePerHit(int);
    int getDamagePerHit();
};


#endif 