#pragma once
#ifndef ELF_H
#define ELF_H
#include "Ranged.h"
using namespace std;
class Elf : public Ranged {
private:
	int damage_per_hit;
	int use_limit;
	int count;
public:
	Elf();
	Elf(int, char, int, char, int, int);
	void setDamagePerHit(int);
	int getDamagePerHit();
	int getLimit();
	void setCount(int);
	int getCount();
};


#endif 