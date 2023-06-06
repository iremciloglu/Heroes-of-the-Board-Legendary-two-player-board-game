/* Irem Ciloglu 2385292
I read and accept the submission rules and the important section
specified in assignment file.This is my own work that is done by myself
and my team - mate only */
#include<iostream>
#include "Elf.h"

Elf::Elf() : Ranged() {
    this->life = 8;
    this->character = 'E';
    this->damage_per_hit = 6;
    this->use_limit = 3;
    this->count = 0;
}
Elf::Elf(int life, char ch, int damage, char row, int column, int count) : Ranged(life, ch, column, row) {
    this->count = count;
    this->damage_per_hit = damage;
}
void Elf::setDamagePerHit(int damage) {
    this->damage_per_hit = damage;
}
int Elf::getDamagePerHit() {
    return this->damage_per_hit;
}
int Elf::getLimit() {
    return use_limit;
}
void Elf::setCount(int count) {
    if(count<=this->use_limit)
        this->count = count;
}
int Elf::getCount() {
    return this->count;
}
