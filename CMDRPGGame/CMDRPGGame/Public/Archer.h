//Gevin Sarmiento
//CS/IS 137
//Final Project

#ifndef ARCHER_H
#define ARCHER_H
#include "Character.h"
#include "Bow.h"

class Archer : public Character
{
private:
	int range;
	int criticalChance;
	int criticalDamage;
	Bow bow;
public:
	Archer();
	Archer& setBow(const Bow&);
	Archer& setRange(int);
	Archer& setCriticalChance(int);
	Archer& setCriticalDamage(int);
	Bow getBow() const;
	int getRange() const;
	int getCriticalChance() const;
	int getCriticalDamage() const;
	virtual void normalAttack() override;
	virtual void setSkills() override;
	virtual void addWeaponStats() override;
	virtual void removeWeaponAS(const Weapon&) override;
	virtual void showStat() const override;
	virtual string characterType() const override;
};

#endif
