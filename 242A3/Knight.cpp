/* Irem Ciloglu 2385292
I read and accept the submission rules and the important section
specified in assignment file.This is my own work that is done by myself
and my team - mate only */
#include<iostream>
#include "Knight.h"

Knight::Knight() : Melee() {
	this->life = 10;
	this->character = 'K';
	this->damage_per_hit = 10;
	this->use_limit = 1;
}
Knight::Knight(int life, char ch, int damage, char row, int column) : Melee(life, ch, column, row) {
	this->damage_per_hit = damage;
}
void Knight::setDamagePerHit(int damage) {
	this->damage_per_hit = damage;
}
int Knight::getDamagePerHit() {
	return this->damage_per_hit;
}
int Knight::getLimit() {
	return use_limit;
}
Pieces* Knight::AttackBonus(Pieces* pieces_list, int count) {
	int attack = 0;
	for (int i = 0; i < count; i++) {
		attack = pieces_list[i].getDamagePerHit();
		pieces_list[i].setDamagePerHit(attack++);
	}
	return pieces_list;
}