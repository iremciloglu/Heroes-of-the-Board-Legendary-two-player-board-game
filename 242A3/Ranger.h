#pragma once
#ifndef RANGER_H
#define RANGER_H
#include "Melee.h"
using namespace std;
class Ranger : public Melee {
private:
	int damage_per_hit;
	int use_limit;
public:
	Ranger();
	Ranger(int, char, int, char, int);
	void setDamagePerHit(int);
	int getDamagePerHit()override {
		return this->damage_per_hit;
	}
	int getLimit();
};


#endif 