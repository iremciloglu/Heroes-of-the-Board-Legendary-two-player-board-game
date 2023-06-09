#pragma once
#ifndef MAGE_H
#define MAGE_H
#include "Ranged.h"
using namespace std;
class Mage : public Ranged {
private:

    int use_limit;
public:
    Mage();
    Mage(int, char, int, char, int);
    void setDamagePerHit(int);
    int getDamagePerHit()override {
        return this->damage_per_hit;
    }
    int getLimit();
    Pieces** LifeBonus(Pieces**, int, int);
};

#endif 