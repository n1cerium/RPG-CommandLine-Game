//Gevin Sarmiento
//CS/IS 137
//Final Project

#include "Hound.h"
#include "Character.h"
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

Hound::Hound()
{
	setName("Dark Hound").setCurrentHealth(900).setMaxHealth(900);
	setArmor(110).setAttackPower(115).setMagicResist(110);
	setMovementSpeed(310);
	setCriticalChance(15).setCriticalDamage(40);
}
Hound& Hound::setCriticalChance(int criticalChance)
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
Hound& Hound::setCriticalDamage(int criticalDamage)
{
	this->criticalDamage = criticalDamage > 0 ? criticalDamage : 0;
	return *this;
}
int Hound::getCriticalChance() const
{
	return criticalChance;
}
int Hound::getCriticalDamage() const
{
	return criticalDamage;
}
void Hound::normalAttack()
{
	srand((unsigned int)time(0));
	Character* character = getCharacter();
	int tempDamage;
	int destinedToCrit = (100 - getCriticalChance()) + 1;
	int chanceToCrit = (rand() % destinedToCrit) + 1;

	if (destinedToCrit == chanceToCrit)
	{
		tempDamage = getCriticalDamage() + getAttackPower();
	}
	else
	{
		tempDamage = getAttackPower();
	}
	character->takeAttackDamage(tempDamage);
}

void Hound::showStat() const
{
	Monster::showStat();
	cout << "Critical Chance: " << getCriticalChance() << "%" << endl;
	cout << "Critical Damage: " << getCriticalDamage() << endl;
}