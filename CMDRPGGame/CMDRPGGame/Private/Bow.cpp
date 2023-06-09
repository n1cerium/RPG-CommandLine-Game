//Gevin Sarmiento
//CS/IS 137
//Final Project

#include "Bow.h"
#include <iostream>

Bow::Bow(const string& nme, int attackPower, int range, int critChance, int critDamage)
	: Weapon(nme, attackPower)
{
	setRange(range).setCriticalChance(critChance).setCriticalDamage(critDamage);
}
Bow& Bow::setRange(int range)
{
	this->range = range > 0 ? range : 0;
	return *this;
}
Bow& Bow::setCriticalChance(int criticalChance)
{
	if (criticalChance > 0)
	{
		this->criticalChance = criticalChance <= 100 ? criticalChance : 100;
	}
	else
	{
		this->criticalChance = 0;
	}
	return *this;
}
Bow& Bow::setCriticalDamage(int criticalDamage)
{
	this->criticalDamage = criticalDamage > 0 ? criticalDamage : 0;
	return *this;
}
int Bow::getRange() const
{
	return range;
}
int Bow::getCriticalChance() const
{
	return criticalChance;
}
int Bow::getCriticalDamage() const
{
	return criticalDamage;
}
void Bow::viewDescription() const
{
	Weapon::viewDescription();
	cout << "Has " << getRange() << " range." << endl;
	cout << "Has " << getCriticalChance() << " critical chance." << endl;
	cout << "Has " << getCriticalDamage() << " critical damage." << endl;
}