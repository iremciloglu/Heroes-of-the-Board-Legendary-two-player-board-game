/* Irem Ciloglu 2385292
I read and accept the submission rules and the important section
specified in assignment file.This is my own work that is done by myself
and my team - mate only */
#include<iostream>
#include "Ranged.h"
Ranged::Ranged() : Pieces() {
	this->column = 0;
	this->row = 'A';
}
Ranged::Ranged(int life, char ch, int column, char row) : Pieces(life, ch) {
	if(column==1 || column==2)
		this->column = column;
	this->row = row;
}
void Ranged::setColumn(int column) {
	if (column == 1 || column == 2)
		this->column = column;
}
int Ranged::getColumn() {
	return this->column;
}
void Ranged::setRow(char row) {
	this->row = row;
}
char Ranged::getRow() {
	return this->row;
}
Ranged::Ranged(const Ranged&) {}