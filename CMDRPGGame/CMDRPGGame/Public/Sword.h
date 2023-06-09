//Gevin Sarmiento
//CS/IS 137
//Final Project

#ifndef SWORD_H
#define SWORD_H
#include <string>
#include "Weapon.h"
using namespace std;

class Sword : public Weapon
{
private:
	int armor;
	int magicResist;
public:
	Sword(const string & = "Bronze Sword", int = 50, int = 60, int = 75);
	Sword& setArmor(int);
	Sword& setMagicResist(int);
	int getArmor() const;
	int getMagicResist() const;
	virtual void viewDescription() const override;

};

#endif