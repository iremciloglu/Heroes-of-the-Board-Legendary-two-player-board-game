/* Irem Ciloglu 2385292
I read and accept the submission rules and the important section
specified in assignment file.This is my own work that is done by myself
and my team - mate only */
#include<iostream>
#include "Spearman.h"

Spearman::Spearman() : Melee() {
	this->life = 6;
	this->character = 'S';
	this->damage_per_hit = 3;
}
Spearman::Spearman(int life, char ch, int damage, char row, int column) : Melee(life, ch, column, row) {
	this->damage_per_hit = damage;
}
void Spearman::setDamagePerHit(int damage) {
	this->damage_per_hit = damage;
}
int Spearman::getDamagePerHit() {
	return this->damage_per_hit;
}

