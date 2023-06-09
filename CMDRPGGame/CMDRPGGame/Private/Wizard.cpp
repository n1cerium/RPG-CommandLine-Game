//Gevin Sarmiento
//CS/IS 137
//Final Project

#include <iostream>
#include "Wizard.h"
#include "Monster.h"

Wizard::Wizard()
{
	setName("Wizard").setMaxHealth(1050).setCurrentHealth(1050);
	setMaxMana(750).setCurrentMana(750).setArmor(110);
	setAttackPower(110).setMagicResist(65);
	setMovementSpeed(355);
	setRange(270).setMagicDamage(120);
	setStaff(staff);

	setSkills();
}
Wizard& Wizard::setStaff(const Staff& staff)
{
	string tempName = staff.getName();
	int tempAtkPwr = staff.getAttackPower();
	int tempRange = staff.getRange();
	int tempMagicDamage = staff.getMagicDamage();

	this->staff.setName(tempName);
	this->staff.setAttackPower(tempAtkPwr);
	this->staff.setRange(tempRange);
	this->staff.setMagicDamage(tempMagicDamage);

	addWeaponAS(staff);

	return *this;
}
Wizard& Wizard::setMagicDamage(int magicDamage)
{
	this->magicDamage = magicDamage > 0 ? magicDamage : 0; 
	return *this;
}
Wizard& Wizard::setRange(int range)
{
	this->range = range > 0 ? range : 0;
	return *this;
}
Staff Wizard::getStaff() const
{
	return staff;
}
int Wizard::getMagicDamage() const
{
	return magicDamage;
}
int Wizard::getRange() const
{
	return range;
}
void Wizard::addWeaponStats()
{
	Character::addWeaponStats();
	int tempMagicDamage = this->magicDamage + staff.getMagicDamage();
	int tempRange = this->range + staff.getRange();

	setMagicDamage(tempMagicDamage);
	setRange(tempRange);
};
void Wizard::removeWeaponAS(const Weapon& weapon)
{
	int tempMagicDamage = this->magicDamage - staff.getMagicDamage();
	int tempRange = this->range - staff.getRange();

	setMagicDamage(tempMagicDamage);
	setRange(tempRange);

	Character::removeWeaponAS(weapon);
}
void Wizard::setSkills()
{
	Skill skill;
	skill.setName("Justice of Power").setMagicDamage(130).setManaCost(100);
	setSkillSet(skill);

	skill.setName("The Magic's Will").setMagicDamage(0).setHealth(100).setMana(100).setManaCost(20);
	setSkillSet(skill);

	skill.setName("Magical Power").setMagicDamage(120).setHealth(50).setMana(40).setManaCost(70);
	setSkillSet(skill);

	skill.setName("Magical Power").setMagicDamage(150).setHealth(30).setMana(20).setManaCost(100);  
	setSkillSet(skill);
}
void Wizard::normalAttack()
{
	Monster* monster = getMonster();
	monster->takeAttackDamage(getAttackPower());
	monster->takeMagicalDamage(getMagicDamage());
}
void Wizard::showStat() const
{
	Character::showStat();
	cout << "Range: " << getRange() << endl;
	cout << "Magic Damage: " << getMagicDamage() << endl;
	cout << endl;
};
string Wizard::characterType() const
{
	return "Wizard";
}