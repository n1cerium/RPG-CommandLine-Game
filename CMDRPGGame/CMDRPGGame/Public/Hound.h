//Gevin Sarmiento
//CS/IS 137
//Final Project

#ifndef HOUND_H
#define HOUND_H
#include "Monster.h"

class Hound : public Monster
{
private:
	int criticalChance;
	int criticalDamage;
public:
	Hound();
	Hound& setCriticalChance(int);
	Hound& setCriticalDamage(int);
	int getCriticalChance() const;
	int getCriticalDamage() const;
	virtual void normalAttack() override;
	virtual void showStat() const override;
};
#endif