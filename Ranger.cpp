/* Irem Ciloglu 2385292
I read and accept the submission rules and the important section
specified in assignment file.This is my own work that is done by myself
and my team - mate only */
#include<iostream>
#include "Ranger.h"

Ranger::Ranger() : Melee() {
    this->life = 8;
    this->character = 'R';
    this->damage_per_hit = 6;
    this->use_limit = 2;
    this->count = 0;
}
Ranger::Ranger(int life, char ch, int damage, char row, int column, int count) : Melee(life, ch, column, row) {
    this->count = count;
    this->damage_per_hit = damage;
}
void Ranger::setDamagePerHit(int damage) {
    this->damage_per_hit = damage;
}
int Ranger::getDamagePerHit() {
    return this->damage_per_hit;
}
int Ranger::getLimit() {
    return use_limit;
}
void Ranger::setCount(int count) {
    if (count <= this->use_limit)
        this->count = count;
}
int Ranger::getCount() {
    return this->count;
}
