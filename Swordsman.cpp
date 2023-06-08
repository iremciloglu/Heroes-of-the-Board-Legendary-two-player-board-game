/* Irem Ciloglu 2385292
I read and accept the submission rules and the important section
specified in assignment file.This is my own work that is done by myself
and my team - mate only */
#include<iostream>
#include "Swordsman.h"

Swordsman::Swordsman() : Melee() {
    this->life = 6;
    this->character = 'W';
    this->damage_per_hit = 4;
}
Swordsman::Swordsman(int life, char ch, int damage, char row, int column) : Melee(life, ch, column, row) {
    this->damage_per_hit = damage;
}
void Swordsman::setDamagePerHit(int damage) {
    this->damage_per_hit = damage;
}
int Swordsman::getDamagePerHit() {
    return this->damage_per_hit;
}

