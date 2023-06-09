//Gevin Sarmiento
//CS/IS 137
//Final Project

#include "Warrior.h"
#include <iostream>

Warrior::Warrior()
{
	setName("Warrior").setMaxHealth(1200).setCurrentHealth(1200);
	setMaxMana(500).setCurrentMana(500).setArmor(135);
	setAttackPower(120).setMagicResist(100);
	setMovementSpeed(300);
	setSword(sword).setBarrier(300);

	setSkills();
}
Warrior& Warrior::setSword(const Sword& sword)
{
	string tempName = sword.getName();
	int tempAtkPw = sword.getAttackPower();
	int tempArmor = sword.getArmor();
	int tempMagicResist = sword.getMagicResist();

	this->sword.setName(tempName);
	this->sword.setAttackPower(tempAtkPw);
	this->sword.setArmor(tempArmor);
	this->sword.setMagicResist(tempMagicResist);
	

	addWeaponAS(sword);
	return *this;
}
Warrior& Warrior::setBarrier(int barrier)
{
	this->barrier = barrier > 0 ? barrier : 0;
	return *this;
}
int Warrior::getBarrier() const
{
	return barrier;
}
Sword Warrior::getSword() const
{
	return sword;
}
void Warrior::addWeaponStats()
{
	Character::addWeaponStats();
	int tempArmor = getArmor() + sword.getArmor();
	int tempMagicResist = getMagicResist() + sword.getMagicResist();

	setArmor(tempArmor);
	setMagicResist(tempMagicResist);
}
void Warrior::removeWeaponAS(const Weapon& weapon)
{
	int tempArmor = getArmor() - sword.getArmor();
	int tempMagicResist = getMagicResist() - sword.getMagicResist();

	setArmor(tempArmor);
	setMagicResist(tempMagicResist);

	Character::removeWeaponAS(weapon);
}
void Warrior::takeAttackDamage(int damage)
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
void Warrior::takeMagicalDamage(int magicDamage)
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
void Warrior::setSkills()
{
	Skill skill;
	skill.setName("Warrior Strike").setDamage(130).setManaCost(40);
	setSkillSet(skill);

	skill.setName("Warrior's Pride").setDamage(0).setArmor(20).setHealth(200).setManaCost(35); // heal and increase armor
	setSkillSet(skill);

	skill.setName("Warrior Smash").setDamage(100).setArmor(0).setHealth(0).setManaCost(45);
	setSkillSet(skill);

	skill.setName("Justice Strike").setDamage(90).setArmor(30).setHealth(50).setManaCost(60);
	setSkillSet(skill);
}
void Warrior::showStat() const
{
	Character::showStat();
	cout << "Barrier: " << getBarrier() << endl;
	cout << endl;
}
string Warrior::characterType() const
{
	return "Warrior";
}
