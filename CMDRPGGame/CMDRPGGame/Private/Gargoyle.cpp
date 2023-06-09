//Gevin Sarmiento
//CS/IS 137
//Final Project

#include "Gargoyle.h"
#include "Character.h"
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

Gargoyle::Gargoyle()
{
	setName("Dark Gargoyle").setCurrentHealth(3000).setMaxHealth(3000);
	setArmor(300).setAttackPower(350).setMagicResist(310);
	setMovementSpeed(375);
	setCriticalChance(50).setCriticalDamage(190);
	setMagicDamage(330).setBarrier(1000);
}
Gargoyle& Gargoyle::setCriticalChance(int criticalChance)
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
Gargoyle& Gargoyle::setCriticalDamage(int criticalDamage)
{
	this->criticalDamage = criticalDamage > 0 ? criticalDamage : 0;
	return *this;
}
int Gargoyle::getCriticalChance() const
{
	return criticalChance;
}
int Gargoyle::getCriticalDamage() const
{
	return criticalDamage;
}
Gargoyle& Gargoyle::setMagicDamage(int magicDamage)
{
	this->magicDamage = magicDamage > 0 ? magicDamage : 0;
	return *this;
}
int Gargoyle::getMagicDamage() const
{
	return magicDamage;
}
Gargoyle& Gargoyle::setBarrier(int barrier)
{
	this->barrier = barrier > 0 ? barrier : 0;
	return *this;
}
int Gargoyle::getBarrier() const
{
	return barrier;
}
void Gargoyle::takeAttackDamage(int damage)
{
	int tempDamage = damage > 0 ? getArmor() % damage : 0;
	int tempBarrier;
	int tempCurrentHealth;

	if (getBarrier() > 0)
	{
		tempBarrier = getBarrier() - tempDamage;
		setBarrier(tempBarrier);
	}
	else
	{
		tempCurrentHealth = getCurrentHealth() - tempDamage;
		setCurrentHealth(tempCurrentHealth);
	}
}
void Gargoyle::takeMagicalDamage(int magicDamage)
{
	int tempMagicDamage = magicDamage > 0 ? getMagicResist() % magicDamage : 0;
	int tempBarrier;
	int tempCurrentHealth;

	if (getBarrier() > 0)
	{
		tempBarrier = getBarrier() - tempMagicDamage;
		setBarrier(tempBarrier);
	}
	else
	{
		tempCurrentHealth = getCurrentHealth() - tempMagicDamage;
		setCurrentHealth(tempCurrentHealth);
	}
}
void Gargoyle::normalAttack()
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
	character->takeMagicalDamage(this->magicDamage);
}
void Gargoyle::showStat() const
{
	Monster::showStat();
	cout << "Magic Damage: " << getMagicDamage() << endl;
	cout << "Critical Chance: " << getCriticalChance() << "%" << endl;
	cout << "Critical Damage: " << getCriticalDamage() << endl;
	cout << "Barrier: " << getBarrier() << endl;
}