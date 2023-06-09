/* Irem Ciloglu 2385292
I read and accept the submission rules and the important section
specified in assignment file.This is my own work that is done by myself
and my team - mate only */
#include<iostream>
#include "Melee.h"
Melee::Melee() : Pieces() {
	this->column = 0;
	this->row = 'A';
}
Melee::Melee(int life, char ch, int column, char row) : Pieces(life,ch){
	if (column == 2 || column == 3)
		this->column = column;
	this->row = row;
}
void Melee::setColumn(int column) {
	if (column == 2 || column == 3)
		this->column = column;
}
int Melee::getColumn() {
	return this->column;
}
void Melee::setRow(char row) {
	this->row = row;
}
char Melee::getRow() {
	return this->row;
}
Melee::Melee(const Melee&) {}