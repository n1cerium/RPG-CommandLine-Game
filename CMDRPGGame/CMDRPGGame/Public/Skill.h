//Gevin Sarmiento
//CS/IS 137
//Final Project

#ifndef SKILL_H
#define SKILL_H
#include <string>
using namespace std;

class Skill
{
private:
	string name;
	int damage;
	int magicDamage;
	int health;
	int armor;
	int mana;
	int manaCost;
public:
	Skill(const string & = "", int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);
	Skill& setName(const string&);
	Skill& setDamage(int);
	Skill& setMagicDamage(int);
	Skill& setHealth(int);
	Skill& setArmor(int);
	Skill& setMana(int);
	Skill& setManaCost(int);
	string getName() const;
	int getDamage() const;
	int getMagicDamage() const;
	int getHealth() const;
	int getArmor() const;
	int getMana() const;
	int getManaCost() const;
};

#endif
