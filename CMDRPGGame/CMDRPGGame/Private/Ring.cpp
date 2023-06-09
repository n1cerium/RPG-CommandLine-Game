//Gevin Sarmiento
//CS/IS 137
//Final Project

#include <iostream>
#include "Ring.h"

Ring::Ring(const string& nme, int armor, int health, int mana)
	: Armor(nme, armor, health)
{
	setMana(mana);
}
Ring& Ring::setMana(int mana)
{
	this->mana = mana > 0 ? mana : 0;
	return *this;
}
int Ring::getMana() const
{
	return mana;
}

void Ring::viewDescription() const
{
	Armor::viewDescription();
	cout << "Increase your mana by " << getMana() << '.' << endl;
	cout << endl;
}
bool Ring::operator==(const Armor& armor) const
{
	return armor.operator==(*this);
}
bool Ring::operator==(const Helmet& helmet) const
{
	return false;
}
bool Ring::operator==(const BodyArmor& body) const
{
	return false;
}
bool Ring::operator==(const Ring& ring) const
{
	bool isEqualMana = getMana() == ring.getMana();
	return Armor::isEqualArmor(ring) && isEqualMana;
}
bool Ring::operator==(const Boots& boot) const
{
	return false;
}