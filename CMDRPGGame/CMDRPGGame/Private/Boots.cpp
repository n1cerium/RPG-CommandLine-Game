//Gevin Sarmiento
//CS/IS 137
//Final Project

#include <iostream>
#include "Boots.h"

Boots::Boots(const string& nme, int armor, int health, int movementSpeed)
	: Armor(nme, armor, health)
{
	setMovementSpeed(movementSpeed);
}
Boots& Boots::setMovementSpeed(int movementSpeed)
{
	this->movementSpeed = movementSpeed > 0 ? movementSpeed : 0;
	return *this;
}
int Boots::getMovementSpeed() const
{
	return movementSpeed;
}
void Boots::viewDescription() const
{
	Armor::viewDescription();
	cout << "Increase your movement speed by " << getMovementSpeed() << '.' << endl;
	cout << endl;
}
bool Boots::operator==(const Armor& armor) const
{
	return armor.operator==(*this);
}
bool Boots::operator==(const Helmet& helmet) const
{
	return false;
}
bool Boots::operator==(const BodyArmor& body) const
{
	return false;
}
bool Boots::operator==(const Ring& ring) const
{
	return false;
}
bool Boots::operator==(const Boots& boot) const
{
	bool isEqualMS = getMovementSpeed() == boot.getMovementSpeed();
	return Armor::isEqualArmor(boot) && isEqualMS;
}