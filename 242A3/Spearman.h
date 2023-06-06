#pragma once
#ifndef SPEARMAN_H
#define SPEARMAN_H
#include "Melee.h"
using namespace std;
class Spearman : public Melee {
private:
	int damage_per_hit;
public:
	Spearman();
	Spearman(int, char, int, char, int);
	void setDamagePerHit(int);
	int getDamagePerHit();
};


#endif 