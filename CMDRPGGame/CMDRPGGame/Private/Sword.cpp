//Gevin Sarmiento
//CS/IS 137
//Final Project

#include "Sword.h"
#include <iostream>

Sword::Sword(const string& nme, int attackPower, int armor, int magicResist)
	: Weapon(nme, attackPower)
{
	setArmor(armor).setMagicResist(magicResist);
}

Sword& Sword::setArmor(int armor)
{
	this->armor = armor > 0 ? armor : 0;
	return *this;
}
Sword& Sword::setMagicResist(int magicResist)
{
	this->magicResist = magicResist > 0 ? magicResist : 0;
	return *this;
}
int Sword::getArmor() const
{
	return armor;
}
int Sword::getMagicResist() const
{
	return magicResist;
}
void Sword::viewDescription() const
{
	Weapon::viewDescription();
	cout << "Has " << getArmor() << " armor." << endl;
	cout << "Has " << getMagicResist() << " magic resist." << endl;
}