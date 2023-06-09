#include <iostream>
#include "Helmet.h"

Helmet::Helmet(const string& nme, int armor, int health, int magicResist) 
	: Armor(nme, armor, health) 
{
	setMagicResist(magicResist);
}
Helmet& Helmet::setMagicResist(int magicResist)
{
	this->magicResist = magicResist > 0 ? magicResist : 0;
	return *this;
}
int Helmet::getMagicResist() const
{
	return magicResist;
}
void Helmet::viewDescription() const
{
	Armor::viewDescription();
	cout << "Increase your magic resist by " << getMagicResist() << '.' << endl;
	cout << endl;
}
bool Helmet::operator==(const Armor& armor) const
{
	return armor.operator==(*this);
}
bool Helmet::operator==(const Helmet& helmet) const
{
	bool isEqualMG = getMagicResist() == helmet.getMagicResist();
	return Armor::isEqualArmor(helmet) && isEqualMG;
}
bool Helmet::operator==(const BodyArmor& body) const
{
	return false;
}
bool Helmet::operator==(const Ring& ring) const
{
	return false;
}
bool Helmet::operator==(const Boots& boot) const
{
	return false;
}

