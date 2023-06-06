#pragma once
#ifndef MAGE_H
#define MAGE_H
#include "Ranged.h"
using namespace std;
class Mage : public Ranged {
private:
	int damage_per_hit;
	int use_limit;
	int count;
public:
	Mage();
	Mage(int, char, int, char, int, int);
	void setDamagePerHit(int);
	int getDamagePerHit();
	int getLimit();
	void setCount(int);
	int getCount();
	Pieces** LifeBonus(Pieces**,int,int);
};


#endif 