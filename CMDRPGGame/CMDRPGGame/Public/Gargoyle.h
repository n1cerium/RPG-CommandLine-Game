//Gevin Sarmiento
//CS/IS 137
//Final Project

#ifndef GARGOYLE_H
#define GARGOYLE_H
#include "Monster.h"

class Gargoyle : public Monster
{
private:
	int magicDamage;
	int criticalChance;
	int criticalDamage;
	int barrier;
public:
	Gargoyle();
	Gargoyle& setBarrier(int);
	Gargoyle& setMagicDamage(int);
	Gargoyle& setCriticalChance(int);
	Gargoyle& setCriticalDamage(int);
	int getCriticalChance() const;
	int getCriticalDamage() const;
	int getMagicDamage() const;
	int getBarrier() const;
	virtual void takeAttackDamage(int) override;
	virtual void takeMagicalDamage(int) override;
	virtual void normalAttack() override;
	virtual void showStat() const override;

};


#endif