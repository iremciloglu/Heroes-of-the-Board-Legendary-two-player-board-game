/* Irem Ciloglu 2385292
I read and accept the submission rules and the important section
specified in assignment file.This is my own work that is done by myself
and my team - mate only */
#include<iostream>
#include "Pieces.h"
Pieces::Pieces() {
    this->life = 0;
    this->character = ' ';
    this->damage_per_hit=0;

}
Pieces::Pieces(int life, char ch) {
    this->life = life;
    this->character = ch;
}
void Pieces::setLife(int life) {
    this->life = life;
}
int Pieces::getLife() {
    return life;
}
void Pieces::setCharacter(int C) {
    this->character = C;
}
char Pieces::getCharacter() {
    return character;
}
void Pieces::setDamagePerHit(int) {}
int Pieces::getDamagePerHit() { return 0; }

Pieces& Pieces::operator=(const Pieces& std) {
    if (this == &std)
    {
        return *this;
    }
    this->life = std.life;
    this->character = std.character;
    this->damage_per_hit=std.damage_per_hit;

    return *this;
}