//Gevin Sarmiento
//CS/IS 137
//Final Project

#include <iostream>
#include "Armor.h"

Armor::Armor(const string& nme, int armor, int health) 
	: name(nme)
{
	setArmor(armor).setHealth(health);

}
Armor& Armor::setName(const string& name)
{
	this->name = name;
	return *this;
}
Armor& Armor::setArmor(int armor)
{
	this->armor = armor > 0 ? armor : 0;
	return *this;
}
Armor& Armor::setHealth(int health)
{
	this->health = health > 0 ? health : 0;
	return *this;
}
//Armor& Armor::addDescription(const string& description)
//{
//	descriptions.push_back(description);
//	return *this;
//}
void Armor::viewDescription() const
{
	cout << "Name: " << getName() << '.' << endl;
	cout << "Increase your armor by " << getArmor() << '.' << endl;
	cout << "Increase your health by " << getHealth() << '.' << endl;
}

string Armor::getName() const
{
	return name;
}
int Armor::getArmor() const
{
	return armor;
}
int Armor::getHealth() const
{
	return health;
}

bool Armor::isEqualArmor(const Armor& armor) const
{
	bool equalArmor = getArmor() == armor.getArmor();
	bool equalName = getName() == armor.getName();
	bool equalHealth = getHealth() == armor.getHealth();

	return equalArmor && equalName && equalHealth;
}
