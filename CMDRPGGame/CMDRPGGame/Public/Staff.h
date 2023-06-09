//Gevin Sarmiento
//CS/IS 137
//Final Project

#ifndef STAFF_H
#define STAFF_H
#include <string>
#include "Weapon.h"
using namespace std;

class Staff : public Weapon
{
private:
	int range;
	int magicDamage;
public:
	Staff(const string & = "Bronze Staff", int = 45, int = 90, int = 50);
	Staff& setRange(int);
	Staff& setMagicDamage(int);
	int getRange() const;
	int getMagicDamage() const;
	virtual void viewDescription() const override;
};

#endif