//Gevin Sarmiento
//CS/IS 137
//Final Project

#include <iostream>
#include "Weapon.h"

Weapon::Weapon(const string& nme, int attackPower) : name(nme)
{
	setAttackPower(attackPower);
}
Weapon& Weapon::setName(const string& name)
{
	this->name = name;
	return *this;
}
Weapon& Weapon::setAttackPower(int attackPower)
{
	this->attackPower = attackPower > 0 ? attackPower : 0;
	return *this;
}
string Weapon::getName() const
{
	return name;
}
int Weapon::getAttackPower() const
{
	return attackPower;
}
void Weapon::viewDescription() const
{
	cout << "Name: " << getName() << endl;
	cout << "Has " << getAttackPower() << " attack power." << endl;
}