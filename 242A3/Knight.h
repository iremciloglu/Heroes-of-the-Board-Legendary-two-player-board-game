#pragma once
#ifndef KNIGHT_H
#define KNIGHT_H
#include "Melee.h"
using namespace std;
class Knight : public Melee {
private:
	int damage_per_hit;
	int use_limit;
	int count;
public:
	Knight();
	Knight(int, char, int, char, int, int);
	void setDamagePerHit(int);
	int getDamagePerHit();
	int getLimit();
	void setCount(int);
	int getCount();
	Pieces** AttackBonus(Pieces**,int,int);
};


#endif 