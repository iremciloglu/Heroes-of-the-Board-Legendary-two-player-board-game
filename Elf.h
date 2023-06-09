#pragma once
#ifndef ELF_H
#define ELF_H
#include "Ranged.h"
using namespace std;
class Elf : public Ranged {
private:

    int use_limit;
public:
    Elf();
    Elf(int, char, int, char, int);
    void setDamagePerHit(int);
    int getDamagePerHit()override {
        return this->damage_per_hit;
    }
    int getLimit();
};


#endif 