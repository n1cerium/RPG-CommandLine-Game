//Gevin Sarmiento
//CS/IS 137
//Final Project

#include "Skill.h"

Skill::Skill(const string& nme, int damage, int magicDamage, int health, int armor, int mana, int manaCost) : name(nme)
{
	setDamage(damage).setMagicDamage(magicDamage);
	setHealth(health).setArmor(armor).setMana(mana);
	setManaCost(manaCost);
	
}
Skill& Skill::setName(const string& name)
{
	this->name = name;
	return *this;
}
Skill& Skill::setDamage(int damage)
{
	this->damage = damage > 0 ? damage : 0;
	return *this;
}
Skill& Skill::setMagicDamage(int magicDamage)
{
	this->magicDamage = magicDamage > 0 ? magicDamage : 0;
	return *this;
}
Skill& Skill::setArmor(int armor)
{
	this->armor = armor > 0 ? armor : 0;
	return *this;
}
Skill& Skill::setHealth(int health)
{
	this->health = health > 0 ? health : 0;
	return *this;
}
Skill& Skill::setMana(int mana)
{
	this->mana = mana > 0 ? mana : 0;
	return *this;
}
Skill& Skill::setManaCost(int manaCost)
{
	this->manaCost = manaCost > 0 ? manaCost : 0;
	return *this;
}
string Skill::getName() const
{
	return name;
}
int Skill::getDamage() const
{
	return damage;
}
int Skill::getMagicDamage() const
{
	return magicDamage;
}
int Skill::getArmor() const
{
	return armor;
}
int Skill::getHealth() const
{
	return health;
}
int Skill::getMana() const
{
	return mana;
}
int Skill::getManaCost() const
{
	return manaCost;
}
