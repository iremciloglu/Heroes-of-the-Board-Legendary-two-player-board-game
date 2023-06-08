#pragma once
#ifndef RANGER_H
#define RANGER_H
#include "Melee.h"
using namespace std;
class Ranger : public Melee {
private:
	int damage_per_hit;
	int use_limit;
	int count;
public:
	Ranger();
	Ranger(int, char, int, char, int, int);
	void setDamagePerHit(int);
	int getDamagePerHit();
	int getLimit();
	void setCount(int);
	int getCount();
};


#endif 