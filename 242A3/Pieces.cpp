/* Irem Ciloglu 2385292
I read and accept the submission rules and the important section
specified in assignment file.This is my own work that is done by myself
and my team - mate only */
#include<iostream>
#include "Pieces.h"
Pieces::Pieces() {
	this->life= 0;
	this->character = '/0';
}
Pieces::Pieces(int life, char ch) {
	this->life = life;
	this->character = ch;
}
void Pieces::setLife(int life) {
	this->life = life;
}
int Pieces::getLife() {
	return this->life;
}
char Pieces::getCharacter() {
	return character;
}
void Pieces::setCharacter(char C) {
	this->character = C;
}


void Pieces::setDamagePerHit(int) {}
int Pieces::getDamagePerHit() { return 0; }
