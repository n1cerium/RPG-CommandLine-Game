//Gevin Sarmiento
//CS/IS 137
//Final Project

#include "Golem.h"
#include <iostream>
using namespace std;

Golem::Golem()
{
	setName("Dark Golem").setCurrentHealth(850).setMaxHealth(850);
	setArmor(65).setAttackPower(100).setMagicResist(110);
	setMovementSpeed(275);
	setBarrier(75);
}
Golem& Golem::setBarrier(int barrier)
{
	this->barrier = barrier > 0 ? barrier : 0;
	return *this;
}
int Golem::getBarrier() const
{
	return barrier;
}
void Golem::takeAttackDamage(int damage)
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
void Golem::takeMagicalDamage(int magicDamage)
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
void Golem::showStat() const
{
	Monster::showStat();
	cout << "Barrier: " << getBarrier() << endl;
}