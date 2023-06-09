#pragma once
#ifndef RANGED_H
#define RANGED_H
#include "Pieces.h"
using namespace std;
class Ranged : public Pieces {
private:
    int column;
    char row;
public:
    Ranged();
    Ranged(int, char, int, char);
    void setColumn(int);
    int getColumn();
    void setRow(char);
    char getRow();
    void setDamagePerHit(int) {};

    Ranged(const Ranged&);
};
#endif