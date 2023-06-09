//Gevin Sarmiento
//CS/IS 137
//Final Project

#include <iostream>
#include "BodyArmor.h"

BodyArmor::BodyArmor(const string& nme, int armor, int health, int magicResist)
	: Armor(nme, armor, health)
{
	setMagicResist(magicResist);
}
BodyArmor& BodyArmor::setMagicResist(int magicResist)
{
	this->magicResist = magicResist > 0 ? magicResist : 0;
	return *this;
}
int BodyArmor::getMagicResist() const
{
	return magicResist;
}
void BodyArmor::viewDescription() const
{
	Armor::viewDescription();
	cout << "Increase your magic resist by " << getMagicResist() << '.' << endl;
	cout << endl;
}
bool BodyArmor::operator==(const Armor& armor) const
{
	return armor.operator==(*this);
}
bool BodyArmor::operator==(const Helmet& helmet) const
{
	//have to return false becauase BodyArmor != helmet
	return false;
}
bool BodyArmor::operator==(const BodyArmor& body) const
{
	bool isEqualMG = getMagicResist() == body.getMagicResist();
	return Armor::isEqualArmor(body) && isEqualMG;
}
bool BodyArmor::operator==(const Ring& ring) const
{
	return false;
}
bool BodyArmor::operator==(const Boots& boot) const
{
	return false;
}