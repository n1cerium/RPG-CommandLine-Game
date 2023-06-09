//Gevin Sarmiento
//CS/IS 137
//Final Project

#include "Monster.h"
#include <iostream>
using namespace std;

Monster::Monster()
{
	setName("").setCurrentHealth(0).setMaxHealth(0);
    setArmor(0).setAttackPower(0).setMagicResist(0); 
	setMovementSpeed(0);
}
Monster& Monster::setName(const string& name)
{
	this->name = name;
	return *this;
}
Monster& Monster::setCurrentHealth(int currentHealth)
{
	this->currentHealth = currentHealth > 0 ? currentHealth : 0;
	return *this;
}
Monster& Monster::setMaxHealth(int maxHealth)
{
	this->maxHealth = maxHealth > 0 ? maxHealth : 0;
	return *this;
}
Monster& Monster::setArmor(int armor)
{
	this->armor = armor > 0 ? armor : 0;
	return *this;
}
Monster& Monster::setAttackPower(int attackPower)
{
	this->attackPower = attackPower > 0 ? attackPower : 0;
	return *this;
}
Monster& Monster::setMagicResist(int magicResist)
{
	this->magicResist = magicResist > 0 ? magicResist : 0;
	return *this;
}
Monster& Monster::setMovementSpeed(int movementSpeed)
{
	this->movementSpeed = movementSpeed > 0 ? movementSpeed : 0;
	return *this;
}
Monster& Monster::setCharacter(const Character& character)
{
	this->character = const_cast<Character*>(&character);
	return *this;
}
string Monster::getName() const
{
	return name;
}
int Monster::getCurrentHealth() const
{
	return currentHealth;
}
int Monster::getMaxHealth() const
{
	return maxHealth;
}
int Monster::getArmor() const
{
	return armor;
}
int Monster::getAttackPower() const
{
	return attackPower;
}
int Monster::getMagicResist() const
{
	return magicResist;
}
int Monster::getMovementSpeed() const
{
	return movementSpeed;
}
Character* Monster::getCharacter() const
{
	return character;
}
void Monster::takeAttackDamage(int damage)
{
	int tempDamage = damage > 0 ? (getArmor() % damage) : 0; 
	int tempCurrentHealth = getCurrentHealth() - tempDamage;

	setCurrentHealth(tempCurrentHealth);
}
void Monster::takeMagicalDamage(int magicDamage)
{
	int tempMagicDamage = magicDamage > 0 ? magicResist % magicDamage : 0;
	int tempCurrentHealth = getCurrentHealth() - tempMagicDamage;

	setCurrentHealth(tempCurrentHealth);
}
void Monster::normalAttack()
{
	character->takeAttackDamage(this->attackPower);
}
void Monster::showStat() const
{
	cout << "Here is the monster stats: " << endl;
	cout << "Monster Name: " << getName() << endl;
	cout << "Health: " << getCurrentHealth() << " / " << getMaxHealth() << endl;
	cout << "Armor: " << getArmor() << endl;
	cout << "Magic Resist: " << getMagicResist() << endl;
	cout << "Movement Speed: " << getMovementSpeed() << endl;
	cout << "Attack Power: " << getAttackPower() << endl;
}