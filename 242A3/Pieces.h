#pragma once
#ifndef PIECES_H
#define PIECES_H

using namespace std;
class Pieces {
protected:
    int life;
    char character;

public:
    Pieces();
    Pieces(int, char);
    void setLife(int);
    int getLife();
    char getCharacter();
    void setCharacter(int);
    virtual void setDamagePerHit(int);
    virtual int getDamagePerHit();
    Pieces& operator=(const Pieces& std);
};
#endif