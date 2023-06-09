/* Irem Ciloglu 2385292
I read and accept the submission rules and the important section
specified in assignment file.This is my own work that is done by myself
and my team - mate only */
#include<iostream>
#include "Bowman.h"

Bowman::Bowman() : Ranged() {
    this->life = 12;
    this->character = 'B';
    this->damage_per_hit = 3;
}
Bowman::Bowman(int life, char ch, int damage, char row, int column) : Ranged(life, ch, column, row) {
    this->damage_per_hit = damage;
}
void Bowman::setDamagePerHit(int damage) {
    this->damage_per_hit = damage;
}
/*int Bowman::getDamagePerHit() {
    return this->damage_per_hit;
}*/