
#pragma once
#ifndef BOWMAN_H
#define BOWMAN_H
#include "Ranged.h"
using namespace std;
class Bowman : public Ranged{
private:
	int damage_per_hit;
public:
	Bowman();
	Bowman(int, char, int, char, int);
	void setDamagePerHit(int);
	int getDamagePerHit();
	int hit( Pieces**,int);
};


#endif 
