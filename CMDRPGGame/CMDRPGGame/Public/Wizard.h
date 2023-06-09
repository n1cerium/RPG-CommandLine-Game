//Gevin Sarmiento
//CS/IS 137
//Final Project

#ifndef WIZARD_H
#define WIZARD_H
#include "Character.h"
#include "Staff.h"

class Wizard : public Character
{
private:
	int magicDamage;
	int range;
	Staff staff;
public:
	Wizard();
	Wizard& setStaff(const Staff&);
	Wizard& setMagicDamage(int);
	Wizard& setRange(int);
	Staff getStaff() const;
	int getMagicDamage() const;
	int getRange() const;
	virtual void normalAttack() override;
	virtual void setSkills() override;
	virtual void addWeaponStats() override;
	virtual void removeWeaponAS(const Weapon&) override;
	virtual void showStat() const override;
	virtual string characterType() const override;
};

#endif
