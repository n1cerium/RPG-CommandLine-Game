//Gevin Sarmiento
//CS/IS 137
//Final Project

#ifndef WARRIOR_H
#define WARRIOR_H
#include "Character.h"


class Warrior : public Character
{
private:
	int barrier;
	Sword sword;
public:
	Warrior();
	Warrior& setSword(const Sword&);
	Warrior& setBarrier(int);
	int getBarrier() const;
	Sword getSword() const;
	virtual void takeAttackDamage(int) override;
	virtual void takeMagicalDamage(int) override;
	virtual void setSkills() override;
	virtual void addWeaponStats() override;
	virtual void removeWeaponAS(const Weapon&) override;
	virtual void showStat() const override;
	virtual string characterType() const override;
};


#endif