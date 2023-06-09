//Gevin Sarmiento
//CS/IS 137
//Final Project

#include <iostream>
#include "Archer.h"
#include "Monster.h"
#include <iomanip>
#include <ctime>

Archer::Archer()
{
	setName("Archer").setMaxHealth(1100).setCurrentHealth(1100);
	setMaxMana(550).setCurrentMana(550).setArmor(105);
	setAttackPower(200).setMagicResist(55);
	setMovementSpeed(375);
	setRange(300).setCriticalChance(10);
	setCriticalDamage(50).setBow(bow); 

	setSkills();
}
Archer& Archer::setBow(const Bow& bow)
{
	string tempName = bow.getName();
	int tempAtkPw = bow.getAttackPower();
	int tempRange = bow.getRange();
	int tempCritChance = bow.getCriticalChance();
	int tempCritDamage = bow.getCriticalDamage();

	this->bow.setName(tempName);
	this->bow.setAttackPower(tempAtkPw);
	this->bow.setRange(tempRange);
	this->bow.setCriticalChance(tempCritChance);
	this->bow.setCriticalDamage(tempCritDamage);

	addWeaponAS(bow);
	return *this;
}
Archer& Archer::setRange(int range)
{
	this->range = range > 0 ? range : 0;
	return *this;
}
Archer& Archer::setCriticalChance(int criticalChance)
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
Archer& Archer::setCriticalDamage(int criticalDamage)
{
	this->criticalDamage = criticalDamage > 0 ? criticalDamage : 0;
	return *this;
}
Bow Archer::getBow() const
{
	return bow;
}
int Archer::getRange() const
{
	return range;
}
int Archer::getCriticalChance() const
{
	return criticalChance;
}
int Archer::getCriticalDamage() const
{
	return criticalDamage;
}
void Archer::addWeaponStats()
{
	Character::addWeaponStats();
	int tempRange = getRange() + bow.getRange();
	int tempCritChance = getCriticalChance() + bow.getCriticalChance();
	int tempCritDamage = getCriticalDamage() + bow.getCriticalDamage();

	setRange(tempRange);
	setCriticalChance(tempCritChance);
	setCriticalDamage(tempCritDamage);
}
void Archer::removeWeaponAS(const Weapon& weapon)
{
	int tempRange = getRange() - bow.getRange();
	int tempCritChance = getCriticalChance() - bow.getCriticalChance();
	int tempCritDamage = getCriticalDamage() - bow.getCriticalDamage();

	setRange(tempRange);
	setCriticalChance(tempCritChance);
	setCriticalDamage(tempCritDamage);

	Character::removeWeaponAS(weapon);
}
void Archer::setSkills()
{
	Skill skill;
	skill.setName("Rising Arrow").setDamage(120).setManaCost(50);
	setSkillSet(skill);

	skill.setName("Hawk Shot").setDamage(100).setManaCost(45);
	setSkillSet(skill);

	skill.setName("Piercing Arrow").setDamage(90).setHealth(30).setManaCost(40);
	setSkillSet(skill);

	skill.setName("Light Arrow").setDamage(110).setHealth(50).setManaCost(55);
	setSkillSet(skill);
}
void Archer::normalAttack()
{
	Monster* monster = getMonster();
	srand((unsigned int)time(0));
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
	monster->takeAttackDamage(tempDamage);


}
void Archer::showStat() const
{
	Character::showStat();
	cout << "Range: " << getRange() << endl;
	cout << "Critical Chance: " << getCriticalChance() << "%" << endl;
	cout << "Critical Damage: " << getCriticalDamage() << endl;
	cout << endl;
}
string Archer::characterType() const
{
	return "Archer";
}