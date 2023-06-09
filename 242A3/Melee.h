#pragma once
#ifndef MELEE_H
#define MELEE_H
#include "Pieces.h"
using namespace std;

class Melee : public Pieces {
private:
    int column;
    char row;

public:
    Melee();
    Melee(int, char, int, char);
    void setColumn(int);
    int getColumn();
    void setRow(char);
    char getRow();
    void setDamagePerHit(int) {};
    Melee(const Melee&);

};
#endif