//Gevin Sarmiento
//CS/IS 137
//Final Project

#ifndef MONSTER_H
#define MONSTER_H
#include <string>
using namespace std;

class Character; // using forward declaration to prevent circular include

class Monster
{
private:
	Character* character;
	string name;
	int currentHealth;
	int maxHealth;
	int armor;
	int attackPower;
	int magicResist;
	int movementSpeed;
public:
	Monster();
	Monster& setName(const string&);
	Monster& setCurrentHealth(int);
	Monster& setMaxHealth(int);
	Monster& setArmor(int);
	Monster& setAttackPower(int);
	Monster& setMagicResist(int);
	Monster& setMovementSpeed(int);
	Monster& setCharacter(const Character&);
	string getName() const;
	int getCurrentHealth() const;
	int getMaxHealth() const;
	int getArmor() const;
	int getAttackPower() const;
	int getMagicResist() const;
	int getMovementSpeed() const;
	Character* getCharacter() const;
	virtual void takeAttackDamage(int);
	virtual void takeMagicalDamage(int);
	virtual void normalAttack();
	virtual void showStat() const;
};


#endif

#include "Character.h" // i have this because I had an error
// if i did not include this, i would get an error that I could not reference
// a class that is not implemented yet.