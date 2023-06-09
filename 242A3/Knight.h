#pragma once
#ifndef KNIGHT_H
#define KNIGHT_H
#include "Melee.h"
using namespace std;
class Knight : public Melee {
private:
    int damage_per_hit;
    int use_limit;
public:
    Knight();
    Knight(int, char, int, char, int);
    void setDamagePerHit(int);
    int getDamagePerHit() override {
        cout<<"arabam";
        return damage_per_hit;
    }
    int getLimit();
    Pieces* AttackBonus(Pieces*,int);
};


#endif 