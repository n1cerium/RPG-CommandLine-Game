//Gevin Sarmiento
//CS/IS 137
//Final Project

#include "Staff.h"
#include <iostream>

Staff::Staff(const string& nme, int attackPower, int range, int magicDamage)
	: Weapon(nme, attackPower)
{
	setRange(range).setMagicDamage(magicDamage);
}
Staff& Staff::setRange(int range)
{
	this->range = range > 0 ? range : 0;
	return *this;
}
Staff& Staff::setMagicDamage(int magicDamage)
{
	this->magicDamage = magicDamage > 0 ? magicDamage : 0;
	return *this;
}
int Staff::getRange() const
{
	return range;
}
int Staff::getMagicDamage() const
{
	return magicDamage;
}
void Staff::viewDescription() const
{
	Weapon::viewDescription();
	cout << "Has " << getRange() << " range." << endl;
	cout << "Has " << getMagicDamage() << " magic damage." << endl;
}