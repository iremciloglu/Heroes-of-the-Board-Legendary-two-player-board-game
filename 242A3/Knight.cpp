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
	this->count = 0;
}
Knight::Knight(int life, char ch, int damage, char row, int column, int count) : Melee(life, ch, column, row) {
	this->count = count;
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
void Knight::setCount(int count) {
	if (count <= this->use_limit)
		this->count = count;
}
int Knight::getCount() {
	return this->count;
}
Pieces** Knight::AttackBonus(Pieces** board1, int r, int c) {
	int attack = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board1[i][j].getCharacter() != ' ' && board1[i][j].getLife() != 0) {
				attack = board1[i][j].getDamagePerHit();
				board1[i][j].setDamagePerHit(attack++);
			}
		}
	}
	return board1;
}