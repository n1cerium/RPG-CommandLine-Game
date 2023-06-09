//Gevin Sarmiento
//CS/IS 137
//Final Project

#ifndef GOLEM_H
#define GOLEM_H
#include "Monster.h"

class Golem : public Monster
{
private:
	int barrier;
public:
	Golem();
	Golem& setBarrier(int);
	int getBarrier() const;
	virtual void takeAttackDamage(int) override;
	virtual void takeMagicalDamage(int) override;
	virtual void showStat() const override;
};

#endif