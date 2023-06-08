/* Irem Ciloglu 2385292
I read and accept the submission rules and the important section
specified in assignment file.This is my own work that is done by myself
and my team - mate only */
#include<iostream>
#include "Mage.h"
 
Mage::Mage() : Ranged(){
	this->life = 4;
	this->character = 'M';
	this->damage_per_hit = 8;
	this->use_limit=2;
}
Mage::Mage(int life, char ch, int damage, char row, int column) : Ranged(life,ch,column,row){
	this->damage_per_hit = damage;
}
void Mage::setDamagePerHit(int damage) {
	this->damage_per_hit = damage;
}
int Mage::getDamagePerHit() {
	return this->damage_per_hit;
}
int Mage::getLimit() {
	return use_limit;
}

Pieces** Mage::LifeBonus(Pieces** board1, int r, int c) {
	int Life = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board1[i][j].getCharacter() != ' ' && board1[i][j].getLife() != 0) {
				Life = board1[i][j].getLife();
				board1[i][j].setLife(Life++);
			}
		}
	}
	return board1;
}