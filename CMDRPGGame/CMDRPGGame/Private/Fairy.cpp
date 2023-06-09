#include "Fairy.h"
#include <iostream>
using namespace std;


Fairy::Fairy()
{
	setName("Dark Fairy").setCurrentHealth(750).setMaxHealth(750);
	setArmor(40).setAttackPower(90).setMagicResist(45);
	setMovementSpeed(300);
	setMagicDamage(95).setRange(250);
}
Fairy& Fairy::setMagicDamage(int magicDamage)
{
	this->magicDamage = magicDamage > 0 ? magicDamage : 0;
	return *this;
}
Fairy& Fairy::setRange(int range)
{
	this->range = range > 0 ? range : 0;
	return *this;
}
int Fairy::getMagicDamage() const
{
	return magicDamage;
}
int Fairy::getRange() const
{
	return range;
}
void Fairy::normalAttack()
{
	Character* character = getCharacter();
	character->takeAttackDamage(getAttackPower());
	character->takeMagicalDamage(getMagicDamage());
}
void Fairy::showStat() const
{
	Monster::showStat();
	cout << "Magic Damage: " << getMagicDamage() << endl;
	cout << "Range: " << getRange() << endl;
}